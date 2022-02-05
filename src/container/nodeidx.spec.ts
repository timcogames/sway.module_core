'use strict';

import { useBridge } from '../../tests/jest/src/bridge';

describe('NodeIdx', () => {
	beforeEach(() => { });

	it('Added node idx', async () => {
		const { module } = await useBridge();

		let integerList = new module.IntegerList();
		integerList.push_back(0);
		integerList.push_back(1);
		integerList.push_back(2);

		let nodeidx = new module.NodeIdx(integerList);
		expect(nodeidx.toStr()).toEqual('[0, 1, 2]');
	});

	afterEach(() => { });
});
