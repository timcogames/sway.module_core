'use strict';

import { NodeIdx } from './nodeidx';

export namespace Node {
    export interface BaseIface<T> {
        addChildNode(child: T): void;

        removeChildNode(child: T): void;

        getChildAt(idx: number): any;

        getNumOfChildNodes(): number;

        getNodeIdx(): NodeIdx.BaseIface;

        getParentNode(): any;
    };

    export interface EmscriptenClass extends Node.BaseIface<Node.EmscriptenClass> {
        new(): Node.EmscriptenClass;
    };
}
