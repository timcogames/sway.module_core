"use strict";

import { BridgeModule } from "@core/bridgemodule";
import { useBridge } from "@core/bridge";

describe("Hierarchy", () => {
  let module: BridgeModule;

  beforeAll(async () => {
    module = (await useBridge("/../../bin/module_core.0.1.0.js")).module;
  });

  it("getRootNode", async () => {
    const hierarchy = new module.Hierarchy();
    expect(hierarchy.getRootNode().getNodeIdx().toStr()).toEqual("[-1]");
  });

  it("findNode", async () => {
    const hierarchy = new module.Hierarchy();
    const child = new module.Node();

    hierarchy.getRootNode().addChildNode(child);
    expect(module.Hierarchy.findNode(hierarchy.getRootNode(), new module.NodeIdx(module.toIntegerVec([-1, 0])))).toBeTruthy();
  });
});
