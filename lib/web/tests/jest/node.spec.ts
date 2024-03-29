"use strict";

import { join } from "node:path";
import { BridgeModule } from "@core/bridgemodule";
import { useBridge } from "@core/bridge";

describe("Node", () => {
  let module: BridgeModule;

  beforeAll(async () => {
    module = (await useBridge<BridgeModule>(join(__dirname, "/../../../../bin/module_core_wasm_async.wasm"))).create_core_module;
  });

  it("added node", async () => {
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

    module.deleteNode(root);
  });
});
