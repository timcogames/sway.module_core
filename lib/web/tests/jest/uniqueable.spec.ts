"use strict";

import { join } from "node:path";
import { useBridge } from "@core/bridge";
import { BridgeModule } from "@core/bridgemodule";

describe("Uniqueable", () => {
  let module: BridgeModule;

  beforeAll(async () => {
    module = (await useBridge<BridgeModule>(join(__dirname, "/../../../../bin/module_core_wasm_async.wasm"))).create_core_module;
  });

  it("has accessible constructor", async () => {

  });
});
