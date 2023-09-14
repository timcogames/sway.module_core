"use strict";

export interface IClasseable {
  getSuperclass: () => null | IClasseable;
  getClassname: () => string;
}
