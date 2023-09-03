"use strict";

import { Optional } from "../misc/optional";
import { NodeIdx } from "./nodeidx";
import { Node } from "./node";

export interface BaseIface {
  findNode(parent:  Node.EmscriptenClass, nodeIdx: NodeIdx.EmscriptenClass): Optional<Node.EmscriptenClass>;
  getRootNode(): Node.EmscriptenClass;
  setRootNode(node: Node.EmscriptenClass): void;
}

export interface EmscriptenIface extends BaseIface {
  new(): EmscriptenClass;
}

export declare class EmscriptenClass implements BaseIface {
  constructor();

  findNode(parent: Node.EmscriptenClass, nodeIdx: NodeIdx.EmscriptenClass): Optional<Node.EmscriptenClass>;
  getRootNode(): Node.EmscriptenClass;
  setRootNode(node: Node.EmscriptenClass): void;
}
