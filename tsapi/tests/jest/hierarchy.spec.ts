"use strict";

import { useBridge } from "./bridge";

describe("Hierarchy", () => {
  it("getRootNode", async () => {
    const { module } = await useBridge();

    if (process.env.EMSCRIPTEN_PLATFOTRM_USE_BINDING == "ON") {
      const hierarchy = new module.Hierarchy();
      expect(hierarchy.getRootNode().getNodeIdx().toStr()).toEqual("[-1]");
    }
    else {
      // TODO
    }
  });

  it("findNode", async () => {
    const { module } = await useBridge();

    if (process.env.EMSCRIPTEN_PLATFOTRM_USE_BINDING == "ON") {
      const hierarchy = new module.Hierarchy();
      const child = new module.Node();

      hierarchy.getRootNode().addChildNode(child);
      expect(module.Hierarchy.findNode(hierarchy.getRootNode(), new module.NodeIdx(module.toIntegerVec([-1, 0])))).toBeTruthy();
    }
    else {
      // TODO
    }
  });
});
