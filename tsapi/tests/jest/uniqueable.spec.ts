"use strict";

import { useBridge } from "@core/bridge";
import { BridgeModule } from "@core/bridgemodule";

describe("Uniqueable", () => {
  let module: BridgeModule;

  beforeAll(async () => {
    module = (await useBridge("/../../bin/module_core.0.1.0.wasm")).module;
  });

  it("has accessible constructor", async () => {

  });
});
