'use strict';

import { ICoreSubmodule } from '../../../include/sway/core';

export interface BridgeModule extends ICoreSubmodule {
	[name: string]: any;
};
