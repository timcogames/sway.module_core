'use strict';

import { useBridge } from '../../src/bridge';

describe('Hierarchy', () => {
  beforeEach(() => {
    // Empty
  });

  it('getRootNode', async () => {
    const { module } = await useBridge();

    const hierarchy = new module.Hierarchy();
    expect(hierarchy.getRootNode().getNodeIdx().toStr()).toEqual('[-1]');
  });

  it('findNode', async () => {
    const { module } = await useBridge();

    const hierarchy = new module.Hierarchy();
    const child = new module.Node();

    hierarchy.getRootNode().addChildNode(child);
    expect(module.Hierarchy.findNode(hierarchy.getRootNode(), new module.NodeIdx(module.toIntegerVec([-1, 0])))).toBeTruthy();
  });

  afterEach(() => {
    // Empty
  });
});
