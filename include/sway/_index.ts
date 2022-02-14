'use strict';

import { NodeIdx } from './core/container/nodeidx';
import { Node } from './core/container/node';

export type INodeIdx = NodeIdx.BaseIface;
export type INode = Node.BaseIface<{}>;

export interface BridgeCoreSubmodule {
  NodeIdx: NodeIdx.EmscriptenClass;
  Node: Node.EmscriptenClass;
};
