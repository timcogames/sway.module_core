'use strict';

import { NodeIdx } from './core/container/nodeidx';
import { Node } from './core/container/node';
import { Hierarchy } from './core/container/hierarchy';

export interface IList<T> {
    get(val: T): any;
    set(val: T, index?: number): boolean;
    push_back(val: T): void;
    resize(size: number, val: T): void;
    size(): number;
};

export interface IOpt<T> {
    has_value(): boolean
};

export interface IObjectWrap {
    __parent: any;
    __construct(args?: any): void;
    __destruct(): void;
};

export type INodeIdx = NodeIdx.BaseIface;
export type INode = Node.BaseIface<{}>;
export type IHierarchy = Hierarchy.BaseIface;

export interface ICoreSubmodule {
    NodeIdx: NodeIdx.EmscriptenClass;
    Node: Node.EmscriptenClass;
    Hierarchy: Hierarchy.EmscriptenClass;
};
