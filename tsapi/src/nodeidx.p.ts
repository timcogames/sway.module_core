'use strict';

import { List } from './misc/list';

export interface BaseIface {
  getChain(): List;
  getParent(): EmscriptenClass;
  getDepth(): number;
  getIdxAt(idx: number): number;
  toStr(): string;
}

export interface EmscriptenIface extends BaseIface {
  new(): EmscriptenClass;
  new(chain: List): EmscriptenClass;
  new(parent: EmscriptenClass, idx: number): EmscriptenClass;
}

export declare class EmscriptenClass implements BaseIface {
  constructor();
  constructor(chain: List);
  constructor(parent: EmscriptenClass, idx: number);

  getChain(): List;
  getParent(): EmscriptenClass;
  getDepth(): number;
  getIdxAt(idx: number): number;
  toStr(): string;
}
