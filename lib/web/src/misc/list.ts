"use strict";

export interface List<T = number | string> {
  get(val: number): number | string;
  set(val: T, index?: number): boolean;
  push_back(val: T): void;
  resize(size: number, val: T): void;
  size(): number;
}
