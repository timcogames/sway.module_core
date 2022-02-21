'use strict';

import { useBridge } from './bridge';
import { INodeIdx } from '../../../include/sway/core';

describe('Hierarchy', () => {
	beforeEach(() => { });

	it('getRootNode', async () => {
		const { module } = await useBridge();

		let hierarchy = new module.Hierarchy();
		expect(hierarchy.getRootNode().getNodeIdx().toStr()).toEqual('[-1]');
	});

	afterEach(() => { });
});
