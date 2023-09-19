"use strict";

import { useBridge } from "./bridge";

describe("Node", () => {
  it("added node", async () => {
    const { module } = await useBridge();

    if (process.env.EMSCRIPTEN_PLATFOTRM_USE_BINDING == "ON") {
      const root = new module.Node();
      const node = new module.Node();
      root.addChildNode(node);

      expect(node.getNodeIdx().toStr()).toEqual("[-1, 0]");
    }
    else {
      const root = module.createNode();
      const node = module.createNode();
      module.addChildNode(root, node);

      const charArr = new Int8Array(
        module.memory.buffer, // WASM's memory
        module.getNodeIdx(node), // char's pointer
        7 // The string's length
      );

      const str = String.fromCharCode.apply(null, charArr as any);
      expect(str).toEqual("[-1, 0]");
    }
  });
});
