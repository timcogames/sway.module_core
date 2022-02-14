'use strict';

import { BridgeCoreSubmodule } from '../../../include/sway/_index';

export interface BridgeModule extends BridgeCoreSubmodule {
	[name: string]: any;
};
