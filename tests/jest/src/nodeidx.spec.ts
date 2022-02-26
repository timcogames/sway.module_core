'use strict';

import { useBridge } from './bridge';
import { INodeIdx } from '../../../include/sway/core';

describe('NodeIdx', () => {
	beforeEach(() => { });

	it('added node idx', async () => {
		const { module } = await useBridge();

		let integerVec = new module.IntegerVec();
		integerVec.push_back(0);
		integerVec.push_back(1);
		integerVec.push_back(2);

		let nodeidx: INodeIdx = new module.NodeIdx(integerVec);
		//let nodeidx: INodeIdx = new module.NodeIdx(module.toIntegerVec([0, 1, 2]));
		expect(nodeidx.toStr()).toEqual('[0, 1, 2]');
	});

	afterEach(() => { });
});
