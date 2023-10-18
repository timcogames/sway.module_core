"use strict";

import { join } from "node:path";
import { BridgeModule } from "@core/bridgemodule";
import { useBridge } from "@core/bridge";

describe("Hierarchy", () => {
  let module: BridgeModule;

  beforeAll(async () => {
    module = (await useBridge<BridgeModule>(join(__dirname, "/../../../bin/module_core.0.1.0.wasm"))).module;
  });

  it("getRootNode", async () => {

  });

  it("findNode", async () => {

  });
});