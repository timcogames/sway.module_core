"use strict";

import { BridgeModule } from "@core/bridgemodule";
import { useBridge } from "@core/bridge";

describe("Node", () => {
  let module: BridgeModule;

  beforeAll(async () => {
    module = (await useBridge<BridgeModule>("../../bin/module_core_wasm_async.js")).create_core_module;
  });

  it("added node", async () => {
    const root = new module.Node();
    const node = new module.Node();
    root.addChildNode(node);

    expect(node.getNodeIdx().toStr()).toEqual("[-1, 0]");
  });
});
