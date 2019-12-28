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

HierarchyNodePtr_t Hierarchy::find(const HierarchyNodeIndex & index) {
	HierarchyNodePtr_t retrieved = _root;
	for (int i = 1/* пропускаем корневой индекс */; i < index.getDepth(); ++i) {
		if (index[i] >= retrieved->getChildCount())
			return nullptr;

		retrieved = retrieved->getChild(index[i]);
	}

	return retrieved;
}

void Hierarchy::attachListener(HierarchyListener * listener) {
	_listeners.push_back(listener);
}

void Hierarchy::detachListener(HierarchyListener * listener) {
	// Empty
}

HierarchyNodePtr_t Hierarchy::getRootNode() {
	return _root;
}

void Hierarchy::setRootNode(HierarchyNodePtr_t root) {
	_root = root;
	_root->setHostTree(this);
}

HierarchyListenerVec_t Hierarchy::getListeners() {
	return _listeners;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
