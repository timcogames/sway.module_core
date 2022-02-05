'use strict';

import { useBridge } from 'bridge';

describe('Node', () => {
	beforeEach(() => { });

	it('Added/Removed child node', async () => {
		const { module } = await useBridge();

		let root = new module.Node();
		let worker = new module.Node();

		root.addChildNode(worker);
		root.removeChildNode(worker);
	});

	afterEach(() => { });
});
