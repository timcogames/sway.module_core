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
async function importModule(moduleName: string): Promise<any>{
  return await import(moduleName);
}

export const useBridge = <TBridgeModule>(moduleName: string): Promise<{ module: TBridgeModule }> => {
  return new Promise(async (resolve) => {
    if (process.env.USE_BINDING == "ON") {
      importModule(join(__dirname, moduleName)).then((module: TBridgeModule) => {
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

      const wasm = await WebAssembly.compile(await readFile(join(__dirname, moduleName)));
      const instance = await WebAssembly.instantiate(wasm, importObject);

      wasi.initialize(instance);

      const module: TBridgeModule = instance.exports as any;
      resolve({ module });
    }
  });
}
