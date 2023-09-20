"use strict";

import { join } from "node:path";
import { BridgeModule } from "@core/bridgemodule";
import { useBridge } from "@core/bridge";

describe("Node", () => {
  let module: BridgeModule;

  beforeAll(async () => {
    module = (await useBridge<BridgeModule>(join(__dirname, "/../../../bin/module_core.0.1.0.js"))).module;
  });

  it("added node", async () => {
    const root = new module.Node();
    const node = new module.Node();
    root.addChildNode(node);

    expect(node.getNodeIdx().toStr()).toEqual("[-1, 0]");
  });
});
