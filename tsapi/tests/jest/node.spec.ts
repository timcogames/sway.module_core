'use strict';

import { useBridge } from '../../src/bridge';

describe('Node', () => {
  beforeEach(() => {
    // Empty
  });

  it('added node', async () => {
    const { module } = await useBridge();

    const root = new module.Node();
    const node = new module.Node();
    root.addChildNode(node);

    expect(node.getNodeIdx().toStr()).toEqual('[-1, 0]');
  });

  afterEach(() => {
    // Empty
  });
});
