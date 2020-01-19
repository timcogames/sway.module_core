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

void Hierarchy::attachListener(HierarchyListener * listener) {
	_listeners.push_back(listener);
}

void Hierarchy::detachListener(HierarchyListener * listener) {
	// Empty
}

HierarchyNode * Hierarchy::getRootNode() {
	return _root;
}

void Hierarchy::setRootNode(HierarchyNode * root) {
	_root = root;
	_root->setHostTree(this);
}

HierarchyListenerVec_t Hierarchy::getListeners() {
	return _listeners;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
