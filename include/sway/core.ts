'use strict';

import { NodeIdx } from './core/container/nodeidx';
import { Node } from './core/container/node';

export type INodeIdx = NodeIdx.BaseIface;
export type INode = Node.BaseIface<{}>;

interface IObjectWrap {
    __parent: any;
    __construct(args?: any): void;
    __destruct(): void;
};

export interface ICoreSubmodule {
    NodeIdx: NodeIdx.EmscriptenClass;
    Node: Node.EmscriptenClass;
};
