'use strict';

import { NodeIdx } from './nodeidx';
import { Node } from './node';

export namespace Hierarchy {
    export interface BaseIface {
        findNode(parent:  Node.EmscriptenClass, nodeIdx: NodeIdx.EmscriptenClass): Node.EmscriptenClass;

        getRootNode(): Node.EmscriptenClass;

        setRootNode(node: Node.EmscriptenClass): void;
    };

    export interface EmscriptenClass extends Hierarchy.BaseIface {
        new(): Hierarchy.EmscriptenClass;
    };
}
