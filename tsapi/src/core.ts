"use strict";

import { NodeIdx } from "./foundation/nodeidx";
import { Node } from "./foundation/node";
import { Hierarchy } from "./foundation/hierarchy";

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
