"use strict";

import { useBridge } from "../../src/bridge";
import { Optional } from "../../src/misc/optional";

describe("Uniqueable", () => {
  it("has accessible constructor", async () => {
    const { module } = await useBridge();
    
    const uniqueIdStr: Optional<string> = module.StringOptional.set("unique_id");
    const uniqueable = new module.Uniqueable(uniqueIdStr);

     expect(uniqueable.getUid().value()).toEqual("unique_id");
  });
});
