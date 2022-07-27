"use strict";

import { ICoreSubmodule } from "./core";

export interface BridgeModule extends ICoreSubmodule {
  [name: string]: any;
}
