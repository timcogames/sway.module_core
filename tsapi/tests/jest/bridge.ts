"use strict";

import { readFile } from "node:fs/promises";
import { WASI } from "wasi";
import { argv, env } from "node:process";
import { join } from "node:path";
import { BridgeModule } from "../../src/bridgemodule";

async function importModule(moduleName: string): Promise<any>{
  return await import(moduleName);
}

export const useBridge = (): Promise<{ module: BridgeModule }> => {
  return new Promise(async(resolve) => {
    if (process.env.EMSCRIPTEN_PLATFOTRM_USE_BINDING == "ON") {
      importModule("../../../bin/module_core.0.1.0.js").then((module: BridgeModule) => {
        resolve({ module });
      });
    }
    else {
      const wasi = new WASI({
        version: "preview1",
        args: argv,
        env,
        preopens: {
          "/": join(process.cwd(), "."),
        }
      } as any);

      const importObject = {
        wasi_snapshot_preview1: wasi.wasiImport,
        env: {
          memory: new WebAssembly.Memory({ initial: 256 }),
          table: new WebAssembly.Table({ initial: 0, element: "anyfunc" })
        }
      };

      const wasm = await WebAssembly.compile(await readFile(join(__dirname, "/../../../bin/module_core.0.1.0.wasm")));
      const instance = await WebAssembly.instantiate(wasm, importObject);

      wasi.initialize(instance);

      const module: BridgeModule = instance.exports as any;
      resolve({ module });
    }
  });
}
