#include <sway/core/containers/hierarchy.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

Hierarchy::Hierarchy()
	: _root(nullptr) {
	// Empty
}

Hierarchy::~Hierarchy() {
	SAFE_DELETE(_root)
}

void Hierarchy::addNodeListener(HierarchyNodeListener * listener) {
	_listeners.push_back(listener);
}

// void Hierarchy::addNodeListener(HierarchyNodeListener * listener, HierarchyNode * node, u32_t flags) {
// 	_listeners.push_back(listener);
// }

void Hierarchy::removeNodeListener(HierarchyNodeListener * listener) {
	// Empty
}

HierarchyNode * Hierarchy::getRootNode() {
	return _root;
}

void Hierarchy::setRootNode(HierarchyNode * root) {
	_root = root;
	_root->setHostTree(this);
}

HierarchyNodeListenerVec_t Hierarchy::getListeners() {
	return _listeners;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
