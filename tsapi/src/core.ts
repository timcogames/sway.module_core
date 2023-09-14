"use strict";

import { NodeIdx } from "./container/nodeidx";
import { Node } from "./container/node";
import { Hierarchy } from "./container/hierarchy";

export interface IObjectWrap {
  __parent: any;
  __construct(args?: any): void;
  __destruct(): void;
}

export type INodeIdx = NodeIdx.BaseIface;
export type INode = Node.BaseIface<Node.EmscriptenIface>;
export type IHierarchy = Hierarchy.BaseIface;

export interface ICoreSubmodule {
  NodeIdx: NodeIdx.EmscriptenIface;
  Node: Node.EmscriptenIface;
  Hierarchy: Hierarchy.EmscriptenIface;
}
