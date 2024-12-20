"use strict";

import { NodeIndex } from "./container/nodeindex";
import { Node } from "./container/node";
import { Hierarchy } from "./container/hierarchy";

export type PrimTypeSet = boolean | number | string;

export interface IObjectWrap {
  /* eslint-disable */
  __parent: any;
  __construct(...args: Array<PrimTypeSet | {[prop: string]: PrimTypeSet}>): void;
  __destruct(): void;
}

export type INodeIndex = NodeIndex.BaseIface;
export type INode = Node.BaseIface<Node.EmscriptenIface>;
export type IHierarchy = Hierarchy.BaseIface;

export interface ICoreSubmodule {
  NodeIndex: NodeIndex.EmscriptenIface;
  Node: Node.EmscriptenIface;
  Hierarchy: Hierarchy.EmscriptenIface;
}
