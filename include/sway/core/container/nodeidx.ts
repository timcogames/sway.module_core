'use strict';

export interface NodeIdx {
	getChain(): any;

	getParent(): any;

	getDepth(): number;

	getIdxAt(idx: number): number;

	toStr(): string;
};
