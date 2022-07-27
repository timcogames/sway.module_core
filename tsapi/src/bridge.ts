"use strict";

import Bridge from "../../bin/module_core.0.1.0.js";
import { BridgeModule } from "./bridgemodule";

export const useBridge = (): Promise<{ module: BridgeModule }> => {
  return new Promise((resolve) => {
    Bridge().then((module: BridgeModule) => {
      resolve({ module });
    });
  });
}
