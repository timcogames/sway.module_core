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

	it('findNode', async () => {
		const { module } = await useBridge();

		let hierarchy = new module.Hierarchy();

		let integerList = new module.IntegerList();
		integerList.push_back(-1);
		integerList.push_back(0);

		let child = new module.Node();
		hierarchy.getRootNode().addChildNode(child);
		expect(module.Hierarchy.findNode(hierarchy.getRootNode(), new module.NodeIdx(integerList))).toBeTruthy();
	});

	afterEach(() => { });
});
