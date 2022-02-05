'use strict';

import { NodeIdx } from './nodeidx';

export interface Node<T> {
	addChildNode(child: T): void;

	removeChildNode(child: T): void;

	getNumOfChildNodes(): number;

	getNodeIdx(): NodeIdx;
};
