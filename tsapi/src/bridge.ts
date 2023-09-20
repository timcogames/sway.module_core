"use strict";

import { readFile } from "node:fs/promises";
import { WASI } from "wasi";
import { argv, env } from "node:process";
import { join } from "node:path";
import { BridgeModule } from "./bridgemodule";

/**
 * @brief Динамический импорт.
 * @param moduleName Имя модуля.
 * @returns Promise
 */
async function importModule(moduleName: string): Promise<any>{
  return await import(moduleName);
}

export const useBridge = (moduleName: string): Promise<{ module: BridgeModule }> => {
  return new Promise(async (resolve) => {
    if (process.env.USE_BINDING == "ON") {
      importModule(join(__dirname, moduleName)).then((module: BridgeModule) => {
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

      const module: BridgeModule = instance.exports as any;
      resolve({ module });
    }
  });
}
