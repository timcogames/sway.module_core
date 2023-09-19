"use strict";

import { useBridge } from "./bridge";
import { Optional } from "../../src/misc/optional";

describe("Uniqueable", () => {
  it("has accessible constructor", async () => {
    const { module } = await useBridge();
    
    if (process.env.EMSCRIPTEN_PLATFOTRM_USE_BINDING == "ON") {
      const uniqueIdStr: Optional<string> = module.StringOptional.set("unique_id");
      const uniqueable = new module.Uniqueable(uniqueIdStr);

      expect(uniqueable.getUid().value()).toEqual("unique_id");
    }
    else {
      // TODO
    }
  });
});
