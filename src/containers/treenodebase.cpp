#include <sway/core/containers/treenodebase.h>
#include <sway/core/containers/tree.h>
#include <algorithm> // std::remove_if

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

TreeNodeBase::TreeNodeBase(TreeNodePtr_t parent, const TreeNodeIndex & nodeIndex, const std::string & nodeId)
	: _parent(parent)
	, _nodeIndex(nodeIndex)
	, _nodeId(nodeId) {

	if (_parent)
		_tree = _parent->getHostTree();
}

TreeNodeBase::~TreeNodeBase() {
	// Empty
}

TreeNodeIndex TreeNodeBase::addChild(TreeNodePtr_t child) {
	TreeNodeIndex childIndex = TreeNodeIndex();
	if (hasChild(child->getNodeId()))
		return childIndex;

	childIndex = TreeNodeIndex(getNodeIndex(), _children.size());
	child->setNodeIndex(childIndex);

	_children.push_back(child);

	if (_tree) {
		for (TreeListener * listener : _tree->getListeners())
			listener->onNodeAdded(this, child);
	}

	return childIndex;
}

void TreeNodeBase::removeChild(TreeNodePtr_t child) {
	_children.erase(std::remove_if(_children.begin(), _children.end(), [&](TreeNodePtr_t node) {
		return child->getNodeId().compare(node->getNodeId());
	}), _children.end());

	if (_tree) {
		for (TreeListener * listener : _tree->getListeners())
			listener->onNodeRemoved(this, child);
	}
}

TreeNodePtr_t TreeNodeBase::findChild(const std::string & nodeId) const {
	std::vector<TreeNodePtr_t>::const_iterator iter = _children.begin();
	while (iter != _children.end()) {
		if ((*iter)->getNodeId().compare(nodeId) == 0)
			break;

		iter++;
	}

	if (iter != _children.end())
		return *iter;

	return nullptr;
}

bool TreeNodeBase::hasChild(const std::string & nodeId) const {
	if (findChild(nodeId) == nullptr)
		return false;

	return true;
}

TreeNodePtr_t TreeNodeBase::getChild(u32_t nodeIdx) const {
	if (nodeIdx >= 0 && nodeIdx < _children.size())
		return _children[nodeIdx];

	return nullptr;
}

const std::vector<TreeNodePtr_t> & TreeNodeBase::getChildren() const {
	return _children;
}

u32_t TreeNodeBase::getChildCount() {
	return static_cast<u32_t>(_children.size());
}

Tree * TreeNodeBase::getHostTree() {
	return _tree;
}

void TreeNodeBase::setHostTree(Tree * tree) {
	if (tree)
		_tree = tree;
}

TreeNodePtr_t TreeNodeBase::getParentNode() {
	return _parent;
}

void TreeNodeBase::setParentNode(TreeNodePtr_t parent) {
	_parent = parent;
}

TreeNodeIndex TreeNodeBase::getNodeIndex() const {
	return _nodeIndex;
}

void TreeNodeBase::setNodeIndex(const TreeNodeIndex & nodeIndex) {
	_nodeIndex = nodeIndex;
}

std::string TreeNodeBase::getNodeId() const {
	return _nodeId;
}

void TreeNodeBase::setNodeId(const std::string & nodeId) {
	_nodeId = nodeId;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
