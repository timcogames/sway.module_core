"use strict";

import { useBridge } from "@core/bridge";
import { INodeIdx } from "@core/core";
import { BridgeModule } from "@core/bridgemodule";

describe("NodeIdx", () => {
  let module: BridgeModule;

  beforeAll(async () => {
    module = (await useBridge<BridgeModule>("/../../bin/module_core.0.1.0.js")).module;
  });

  it("added node idx", async () => {
    const integerVec = new module.IntegerVec();
    integerVec.push_back(0);
    integerVec.push_back(1);
    integerVec.push_back(2);

    const nodeidx: INodeIdx = new module.NodeIdx(integerVec);
    // or
    // const nodeidx: INodeIdx = new module.NodeIdx(module.toIntegerVec([0, 1, 2]));
    expect(nodeidx.toStr()).toEqual("[0, 1, 2]");
  });
});
