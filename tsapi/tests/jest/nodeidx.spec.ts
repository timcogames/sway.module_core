"use strict";

import { useBridge } from "./bridge";
import { INodeIdx } from "../../src/core";

describe("NodeIdx", () => {
  it("added node idx", async () => {
    const { module } = await useBridge();

    if (process.env.EMSCRIPTEN_PLATFOTRM_USE_BINDING == "ON") {
      const integerVec = new module.IntegerVec();
      integerVec.push_back(0);
      integerVec.push_back(1);
      integerVec.push_back(2);

      const nodeidx: INodeIdx = new module.NodeIdx(integerVec);
      // or
      // const nodeidx: INodeIdx = new module.NodeIdx(module.toIntegerVec([0, 1, 2]));
      expect(nodeidx.toStr()).toEqual("[0, 1, 2]");
    }
    else {
      // TODO
    }
  });
});
