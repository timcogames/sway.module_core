"use strict";

import { NodeIdx } from "./nodeidx";
import { Node } from "./node";
import { Hierarchy } from "./hierarchy";

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
