#include <sway/core/containers/tree.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

Tree::Tree()
	: _root(nullptr) {
	// Empty
}

Tree::~Tree() {
	SAFE_DELETE(_root)
}

TreeNodePtr_t Tree::find(const TreeNodeIndex & index) {
	TreeNodePtr_t retrieved = _root;
	for (int i = 0; i < index.getDepth(); ++i) {
		if (index[i] >= retrieved->getChildCount())
			return nullptr;

		retrieved = retrieved->getChild(index[i]);
	}

	return retrieved;
}

void Tree::attachListener(TreeListener * listener) {
	_listeners.push_back(listener);
}

void Tree::detachListener(TreeListener * listener) {
	// Empty
}

TreeNodePtr_t Tree::getRootNode() {
	return _root;
}

void Tree::setRootNode(TreeNodePtr_t root) {
	_root = root;
	_root->setHostTree(this);
}

TreeListenerVec_t Tree::getListeners() {
	return _listeners;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
