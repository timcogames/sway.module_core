'use strict';

import { Optional } from './misc/optional';
import { NodeIdx } from './nodeidx';

export interface BaseIface<T> {
  addChildNode(child: T): void;
  removeChildNode(child: T): void;
  getChildAt(idx: number): Optional<EmscriptenClass>;
  getNumOfChildNodes(): number;
  getNodeIdx(): NodeIdx.BaseIface;
  getParentNode(): Optional<EmscriptenClass>;
}

export interface EmscriptenIface extends BaseIface<EmscriptenIface> {
  new(): EmscriptenClass;
}

export declare class EmscriptenClass implements BaseIface<EmscriptenClass> {
  constructor();

  addChildNode(child: EmscriptenClass): void;
  removeChildNode(child: EmscriptenClass): void;
  getChildAt(idx: number): Optional<EmscriptenClass>;
  getNumOfChildNodes(): number;
  getNodeIdx(): NodeIdx.BaseIface;
  getParentNode(): Optional<EmscriptenClass>;
}
