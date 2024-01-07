"use strict";

import { useBridge } from "@core/bridge";
import { Optional } from "@core/misc/optional";
import { BridgeModule } from "@core/bridgemodule";

describe("Uniqueable", () => {
  let module: BridgeModule;

  beforeAll(async () => {
    module = (await useBridge<BridgeModule>("../../bin/module_core_wasm_async.js")).create_core_module;
  });

  it("has accessible constructor", async () => {
    const uniqueIdStr: Optional<string> = module.StringOptional.set("unique_id");
    const uniqueable = new module.Uniqueable(uniqueIdStr);

    expect(uniqueable.getUid().value()).toEqual("unique_id");
  });
});
