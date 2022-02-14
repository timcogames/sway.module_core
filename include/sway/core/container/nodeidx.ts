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
		new(): EmscriptenClass;
		new(chain: any): EmscriptenClass;
		new(parent: any, idx: number): EmscriptenClass;
	};
}
