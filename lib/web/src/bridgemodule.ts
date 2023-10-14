"use strict";

import { ICoreSubmodule } from "./core";

export interface BridgeModule extends ICoreSubmodule {
  /* eslint-disable */
  [name: string]: any;
}
