'use strict';

import { useBridge } from './bridge';
import { INode } from '../../../include/sway/core';

describe('Node', () => {
	beforeEach(() => { });

	it('added node', async () => {
		const { module } = await useBridge();

		let integerVec = new module.IntegerVec();
		integerVec.push_back(-1);
		integerVec.push_back(0);
		integerVec.push_back(2);

        let l1 = new module.NodeData();
        l1.nodeidx = integerVec;

        let nodeDataVec = new module.NodeDataVec();
        nodeDataVec.push_back(l1);

        console.log(nodeDataVec.size());
        console.log(nodeDataVec);
        console.log(nodeDataVec.get(0).nodeidx.size());

		let node = new module.Hierarchy();
		(module.Node as any).parse(node.getRootNode(), nodeDataVec);
		//let nodeidx: INodeIdx = new module.NodeIdx(module.toIntegerVec([0, 1, 2]));
		//expect(node.toStr()).toEqual('[0, 1, 2]');
	});

	afterEach(() => { });
});
