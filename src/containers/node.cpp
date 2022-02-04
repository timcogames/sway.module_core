#include <sway/core/containers/node.hpp>
#include <sway/core/foundation/context.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <algorithm> // std::remove_if

#ifdef _EMSCRIPTEN
	#include <emscripten/emscripten.h>
	#include <emscripten/bind.h>
	#include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(containers)

void Node::registerEmsClass() {
#ifdef _EMSCRIPTEN
	emscripten::class_<Node, emscripten::base<Object>>("Node")
		.function("traverse", &Node::traverse, emscripten::allow_raw_pointers())
		.function("addChild", &Node::addChild, emscripten::allow_raw_pointers())
		.function("removeChild", &Node::removeChild, emscripten::allow_raw_pointers())
		.function("getChild", &Node::getChild, emscripten::allow_raw_pointers())
		.function("getChildAt", &Node::getChildAt, emscripten::allow_raw_pointers())
		.function("hasChild", &Node::hasChild)
		.function("getChildren", &Node::getChildren, emscripten::allow_raw_pointers())
		.function("getChildCount", &Node::getChildCount)
		.function("getParent", &Node::getParent, emscripten::allow_raw_pointers())
		.function("setParent", &Node::setParent, emscripten::allow_raw_pointers())
		.function("hasParent", &Node::hasParent);
#endif
}

Node::Node(foundation::Context * context, Node * parent, const NodeIdx & nodeIdx)
	: foundation::Object(context)
	, parent_(parent)
	, nodeIdx_(nodeIdx) {
	// Empty
}

utils::TraversalAction Node::traverse(utils::ITraverser * traverser) {
	utils::TraversalAction result = traverser->visit(this);

	switch (result) {
	case utils::TraversalAction::Continue:
		for (Node * node : getChildren()) {
			if (node->traverse(traverser) == utils::TraversalAction::Abort)
				return utils::TraversalAction::Abort;
		}

	case utils::TraversalAction::Prune:
		return utils::TraversalAction::Continue;

	case utils::TraversalAction::Abort:
		break;
	}

	return utils::TraversalAction::Abort;
}

NodeIdx Node::addChild(Node * child) {
	NodeIdx childIdx = NodeIdx(getNodeIdx(), children_.size());
	if (hasChild(child->getUid()))
		return NodeIdx();

	children_.push_back(child);
	children_.back()->setNodeIdx(childIdx);


#ifdef _EMSCRIPTEN
	EventData_t eventdata = emscripten::val::object();
	eventdata.set("node_idx", emscripten::val(childIdx));
#else
	EventData_t eventdata;
	eventdata["node_idx"] = childIdx;
#endif

	emit(EVT_ADDED, new EvtNodeAdded(0, eventdata));

	return childIdx;
}

void Node::removeChild(Node * child) {
	children_.erase(std::remove_if(children_.begin(), children_.end(), [&](Node * node) {
		return child->getUid().compare(node->getUid()) == 0;
	}), children_.end());

#ifdef _EMSCRIPTEN
	EventData_t eventdata = emscripten::val::object();
	eventdata.set("node_idx", emscripten::val(child->getNodeIdx()));
#else
	EventData_t eventdata;
	eventdata["node_idx"] = child->getNodeIdx();
#endif

	emit(EVT_REMOVED, new EvtNodeRemoved(0, eventdata));
}

Node * Node::getChild(const std::string & nodeUid) const {
	std::vector<Node *>::const_iterator iter = children_.begin();
	while (iter != children_.end()) {
		if ((*iter)->getUid().compare(nodeUid) == 0)
			break;

		iter++;
	}

	if (iter != children_.end())
		return *iter;

	return nullptr;
}

Node * Node::getChildAt(u32_t targetIdx) const {
	if (targetIdx >= 0 && targetIdx < children_.size())
		return children_[targetIdx];

	return nullptr;
}

bool Node::hasChild(const std::string & nodeUid) const {
	if (getChild(nodeUid) == nullptr)
		return false;

	return true;
}

const std::vector<Node *> & Node::getChildren() const {
	return children_;
}

u32_t Node::getChildCount() {
	return static_cast<u32_t>(children_.size());
}

Node * Node::getParent() {
	return parent_;
}

void Node::setParent(Node * parent) {
	parent_ = parent;
}

bool Node::hasParent() const {
	return parent_ != nullptr;
}

NodeIdx Node::getNodeIdx() const {
	return nodeIdx_;
}

void Node::setNodeIdx(const NodeIdx & nodeIdx) {
	nodeIdx_ = nodeIdx;
}

NAMESPACE_END(containers)
NAMESPACE_END(core)
NAMESPACE_END(sway)
