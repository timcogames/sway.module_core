'use strict';

export namespace NodeIdx {
    export interface BaseIface {
        getChain(): any;

        getParent(): any;

        getDepth(): number;

        getIdxAt(idx: number): number;

        toStr(): string;
    };

    export interface EmscriptenClass extends BaseIface {
        new(): NodeIdx.EmscriptenClass;
        new(chain: any): NodeIdx.EmscriptenClass;
        new(parent: any, idx: number): NodeIdx.EmscriptenClass;
    };
}
