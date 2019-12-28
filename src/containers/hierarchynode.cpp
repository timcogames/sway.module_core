#include <sway/core/containers/hierarchynode.h>
#include <sway/core/containers/hierarchy.h>
#include <sway/core/utilities/visitor.h>
#include <algorithm> // std::remove_if

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

HierarchyNode::HierarchyNode(HierarchyNodePtr_t parent, const HierarchyNodeIndex & nodeIndex, const std::string & nodeId)
	: _parent(parent)
	, _nodeIndex(nodeIndex)
	, _nodeId(nodeId) {

	if (_parent)
		_tree = _parent->getHostTree();
}

HierarchyNode::~HierarchyNode() {
	// Empty
}

void HierarchyNode::accept(utilities::Visitor * visitor) {
	// Empty
}

HierarchyNodeIndex HierarchyNode::addChild(HierarchyNodePtr_t node) {
	const HierarchyNodeIndex nodeIndex = HierarchyNodeIndex(getNodeIndex(), _children.size());
	if (hasChild(node->getNodeId()))
		return HierarchyNodeIndex();

	_children.push_back(node);
	_children.back()->setNodeIndex(nodeIndex);

	if (_tree) {
		for (HierarchyListener * listener : _tree->getListeners())
			listener->onNodeAdded(nodeIndex);
	}

	return nodeIndex;
}

HierarchyNodeIndex HierarchyNode::add(HierarchyNodePtr_t node, std::function<void (const HierarchyNodeIndex &)> handleNodeAdded) {
	const HierarchyNodeIndex nodeIndex = addChild(node);
	if (handleNodeAdded)
		handleNodeAdded(nodeIndex);

	return nodeIndex;
}

void HierarchyNode::removeChild(HierarchyNodePtr_t child) {
	_children.erase(std::remove_if(_children.begin(), _children.end(), [&](HierarchyNodePtr_t node) {
		return child->getNodeId().compare(node->getNodeId());
	}), _children.end());

	if (_tree) {
		for (HierarchyListener * listener : _tree->getListeners())
			listener->onNodeRemoved(this, child);
	}
}

HierarchyNodePtr_t HierarchyNode::findChild(const std::string & nodeId) const {
	std::vector<HierarchyNodePtr_t>::const_iterator iter = _children.begin();
	while (iter != _children.end()) {
		if ((*iter)->getNodeId().compare(nodeId) == 0)
			break;

		iter++;
	}

	if (iter != _children.end())
		return *iter;

	return nullptr;
}

bool HierarchyNode::hasChild(const std::string & nodeId) const {
	if (findChild(nodeId) == nullptr)
		return false;

	return true;
}

HierarchyNodePtr_t HierarchyNode::getChild(u32_t nodeIndex) const {
	if (nodeIndex >= 0 && nodeIndex < _children.size())
		return _children[nodeIndex];

	return nullptr;
}

const std::vector<HierarchyNodePtr_t> & HierarchyNode::getChildren() const {
	return _children;
}

u32_t HierarchyNode::getChildCount() {
	return static_cast<u32_t>(_children.size());
}

Hierarchy * HierarchyNode::getHostTree() {
	return _tree;
}

void HierarchyNode::setHostTree(Hierarchy * tree) {
	if (tree)
		_tree = tree;
}

HierarchyNodePtr_t HierarchyNode::getParentNode() {
	return _parent;
}

void HierarchyNode::setParentNode(HierarchyNodePtr_t parent) {
	_parent = parent;
}

HierarchyNodeIndex HierarchyNode::getNodeIndex() const {
	return _nodeIndex;
}

void HierarchyNode::setNodeIndex(const HierarchyNodeIndex & nodeIndex) {
	_nodeIndex = nodeIndex;
}

std::string HierarchyNode::getNodeId() const {
	return _nodeId;
}

void HierarchyNode::setNodeId(const std::string & nodeId) {
	_nodeId = nodeId;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
