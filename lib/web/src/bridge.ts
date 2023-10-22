"use strict";

import { readFile } from "node:fs/promises";
import { WASI } from "wasi";
import { argv, env } from "node:process";
import { join } from "node:path";

/**
 * @brief Динамический импорт.
 * @param moduleName Имя модуля.
 * @returns Promise
 */
async function importModule(moduleName: string): Promise<any> {
  const { default: module } = await eval(`import('${moduleName}')`);
  return module;
}

export const useBridge = <TBridgeModule>(moduleName: string): Promise<{ create_core_module: TBridgeModule }> => {
  return new Promise(async (resolve) => {
    if (process.env.USE_BINDING == "ON") {
      // importModule("../../bin/module_core.0.1.0.js")

      const fileData = await readFile(join(process.cwd(), moduleName));
      const filePath = join(process.cwd(), moduleName.substring(0, moduleName.lastIndexOf("/")));
      let fileAsStr = fileData.toString("utf8");

      fileAsStr = fileAsStr.replace(/__dirname/g, `"${filePath}"`);

      const Bridge = await eval(fileAsStr);
      Bridge().then((create_core_module: TBridgeModule) => {
        resolve({ create_core_module });
      });
    }
    else {
      const wasi = new WASI(Object.assign({}, {
        args: argv,
        env,
        preopens: { "/": join(process.cwd(), ".") }
      }, { version: "preview1" }));

      const importObject = {
        wasi_snapshot_preview1: wasi.wasiImport
      };

      const wasm = await WebAssembly.compile(await readFile(moduleName as string));
      const instance = await WebAssembly.instantiate(wasm, importObject);

      wasi.initialize(instance);

      const create_core_module: TBridgeModule = instance.exports as any;
      resolve({ create_core_module });
    }
  });
}
