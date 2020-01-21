#include <sway/core/containers/hierarchynode.h>
#include <sway/core/containers/hierarchy.h>
#include <sway/core/utilities/visitor.h>
#include <algorithm> // std::remove_if

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

HierarchyNode::HierarchyNode(HierarchyNode * parent,
	const HierarchyNodeIdx & nodeIdx, const std::string & nodeUid)
	: _parent(parent)
	, _nodeIdx(nodeIdx)
	, _nodeUid(nodeUid) {

	if (hasParentNode())
		_tree = _parent->getHostTree();
}

TraversalAction_t HierarchyNode::traverse(IHierarchyTraverser * traverser) {
	TraversalAction_t result = traverser->visit(this);

	switch (result) {
	case TraversalAction_t::Continue:
		for (HierarchyNode * node : getChildren()) {
			if (node->traverse(traverser) == TraversalAction_t::Abort)
				return TraversalAction_t::Abort;
		}

	case TraversalAction_t::Prune:
		return TraversalAction_t::Continue;

	case TraversalAction_t::Abort:
		break;
	}

	return TraversalAction_t::Abort;
}

HierarchyNodeIdx HierarchyNode::addChild(HierarchyNode * child) {
	const HierarchyNodeIdx childIdx = HierarchyNodeIdx(getNodeIdx(), _children.size());
	if (hasChild(child->getNodeUid()))
		return HierarchyNodeIdx();

	_children.push_back(child);
	_children.back()->setNodeIdx(childIdx);

	if (_tree) {
		for (HierarchyNodeListener * listener : _tree->getListeners())
			listener->onNodeAdded(childIdx);
	}

	return childIdx;
}

void HierarchyNode::removeChild(HierarchyNode * child) {
	_children.erase(std::remove_if(_children.begin(), _children.end(), [&](HierarchyNode * node) {
		return child->getNodeUid().compare(node->getNodeUid());
	}), _children.end());

	if (_tree) {
		for (HierarchyNodeListener * listener : _tree->getListeners())
			listener->onNodeRemoved(child->getNodeIdx());
	}
}

bool HierarchyNode::hasChild(const std::string & nodeUid) const {
	if (getChild(nodeUid) == nullptr)
		return false;

	return true;
}

const std::vector<HierarchyNode *> & HierarchyNode::getChildren() const {
	return _children;
}

u32_t HierarchyNode::getChildCount() {
	return static_cast<u32_t>(_children.size());
}

Hierarchy * HierarchyNode::getHostTree() {
	return _tree;
}

void HierarchyNode::setHostTree(Hierarchy * tree) {
	_tree = tree;
}

HierarchyNode * HierarchyNode::getParentNode() {
	return _parent;
}

void HierarchyNode::setParentNode(HierarchyNode * parent) {
	_parent = parent;
}

bool HierarchyNode::hasParentNode() const {
	return _parent != nullptr;
}

HierarchyNodeIdx HierarchyNode::getNodeIdx() const {
	return _nodeIdx;
}

void HierarchyNode::setNodeIdx(const HierarchyNodeIdx & nodeIdx) {
	_nodeIdx = nodeIdx;
}

std::string HierarchyNode::getNodeUid() const {
	return _nodeUid;
}

void HierarchyNode::setNodeUid(const std::string & nodeUid) {
	_nodeUid = nodeUid;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
