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

export const useBridge = <TBridgeModule>(moduleName: string, newpath: string = "__dirname + \"/../../bin\""): Promise<{ module: TBridgeModule }> => {
  return new Promise(async (resolve) => {
    if (process.env.USE_BINDING == "ON") {
      // importModule("../../bin/module_core.0.1.0.js")

      const fileData = await readFile(join(process.cwd(), moduleName));
      let fileAsStr = fileData.toString("utf8");

      fileAsStr = fileAsStr.replace(/__dirname/g, newpath);

      const Bridge = await eval(fileAsStr);
      Bridge().then((module: TBridgeModule) => {
        resolve({ module });
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

      const module: TBridgeModule = instance.exports as any;
      resolve({ module });
    }
  });
}
