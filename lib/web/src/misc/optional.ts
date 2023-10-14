"use strict";

export interface Optional<T> {
  value(): T;
  has_value(): boolean;
  reset(): void;
}

export interface StringOptional {
  set(val: string): void;
}
