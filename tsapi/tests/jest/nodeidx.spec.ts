'use strict';

import { useBridge } from '../../src/bridge';
import { INodeIdx } from '../../src/core';

describe('NodeIdx', () => {
  beforeEach(() => {
    // Empty
  });

  it('added node idx', async () => {
    const { module } = await useBridge();

    const integerVec = new module.IntegerVec();
    integerVec.push_back(0);
    integerVec.push_back(1);
    integerVec.push_back(2);

    const nodeidx: INodeIdx = new module.NodeIdx(integerVec);
    // or
    // const nodeidx: INodeIdx = new module.NodeIdx(module.toIntegerVec([0, 1, 2]));
    expect(nodeidx.toStr()).toEqual('[0, 1, 2]');
  });

  afterEach(() => {
    // Empty
  });
});
