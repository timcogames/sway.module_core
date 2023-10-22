"use strict";

import { join } from "node:path";
import { BridgeModule } from "@core/bridgemodule";
import { useBridge } from "@core/bridge";

describe("Hierarchy", () => {
  let module: BridgeModule;

  beforeAll(async () => {
    module = (await useBridge<BridgeModule>(join(__dirname, "/../../../../bin/module_core_wasm_async.wasm"))).create_core_module;
  });

  it("getRootNode", async () => {

  });

  it("findNode", async () => {

  });
});
