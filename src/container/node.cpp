#include <sway/core/container/node.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/core/foundation/context.hpp>

#include <algorithm>  // std::remove_if

#ifdef _EMSCRIPTEN
#    include <emscripten/bind.h>
#    include <emscripten/emscripten.h>
#    include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

void Node::registerEmClass() {
#ifdef _EMSCRIPTEN
    emscripten::class_<Node>("Node")
        .smart_ptr_constructor("Node", &std::make_shared<Node>)
        .function("addChildNode", &Node::addChildNode, emscripten::allow_raw_pointers())
        .function("removeChildNode", &Node::removeChildNode, emscripten::allow_raw_pointers())
        .function("getNumOfChildNodes", &Node::getNumOfChildNodes)
        .function("getNodeIdx", &Node::getNodeIdx);
#endif
}

Node::Node()
    : idx_(NodeIdx())
    , parent_({}) {}

Node::~Node() { children_.clear(); }

u32_t Node::traverse(utils::Traverser *traverser) {
    switch (static_cast<utils::Traverser::Action>(traverser->visit(this))) {
        case utils::Traverser::Action::CONTINUE:
            for (const auto &node : getChildNodes()) {
                if (node->traverse(traverser) == detail::toUnderlying(utils::Traverser::Action::ABORT)) {
                    return detail::toUnderlying(utils::Traverser::Action::ABORT);
                }
            }

        case utils::Traverser::Action::PRUNE:
            return detail::toUnderlying(utils::Traverser::Action::CONTINUE);

        case utils::Traverser::Action::ABORT:
            break;
    }

    return detail::toUnderlying(utils::Traverser::Action::ABORT);
}

void Node::addChildNode(std::shared_ptr<Node> child) {
    std::optional<std::shared_ptr<Node>> childParentNode = child->getParentNode();
    if (childParentNode) {
        printf("%s %s\n", childParentNode->get()->getNodeIdx().toStr().c_str(), "Node alread has parent");
        return;
    }

    child->setParentNode(weak_from_this());

    child->setNodeIdx(idx_.getChain(), getNumOfChildNodes());
    for (const auto &childNode : child->getChildNodes()) {
        recursiveAddChainLinks(childNode, child->getNodeIdx());
    }

    children_.push_back(child);

#ifdef _EMSCRIPTEN
    EventData_t eventdata = emscripten::val::object();
    eventdata.set("node_idx", emscripten::val(child->getNodeIdx()));
#else
    EventData_t eventdata;
    eventdata["node_idx"] = child->getNodeIdx();
#endif

    // emit(EVT_ADDED, new EvtNodeAdded(0, eventdata));
}

void Node::recursiveAddChainLinks(std::shared_ptr<Node> child, NodeIdx parentNodeIdx) {
    NodeIdx::chain_t chain = child->getNodeIdx().getChain();
    NodeIdx::chain_t parentChain = parentNodeIdx.getChain();

    chain.insert(chain.begin() + 1, parentChain.begin() + 1, parentChain.end());
    child->setNodeIdx(chain, NODEIDX_NEGATIVE);

    for (const auto &childNode : child->getChildNodes()) {
        recursiveAddChainLinks(childNode, child->getNodeIdx());
    }
}

void Node::removeChildNode(std::shared_ptr<Node> child) {
    children_.erase(std::remove_if(children_.begin(), children_.end(),
                        [&](std::shared_ptr<Node> node) {
                            bool result = node->equal(child);
                            if (result) {
                                for (auto childNode : child->getChildNodes()) {
                                    recursiveRemoveChainLinks(childNode, getNodeIdx());
                                }

                                child->setParentNode(std::weak_ptr<Node>());
                                child->setAsRoot();
                            }
                            return result;
                        }),
        children_.end());
}

void Node::recursiveRemoveChainLinks(std::shared_ptr<Node> child, NodeIdx parentNodeIdx) {
    if (!parentNodeIdx.chainEqual({NODEIDX_NEGATIVE})) {
        NodeIdx::chain_t chain = child->getNodeIdx().getChain();
        chain.erase(chain.begin(), chain.begin() + parentNodeIdx.getDepth());
        chain.at(0) = NODEIDX_ROOT;
        child->setNodeIdx(chain, NODEIDX_NEGATIVE);
    }

    for (const auto &childNode : child->getChildNodes()) {
        recursiveRemoveChainLinks(childNode, parentNodeIdx);
    }
}

std::vector<std::shared_ptr<Node>> Node::getChildNodes() { return children_; }

std::shared_ptr<Node> Node::getChildNode(const NodeIdx &idx) const {
    auto iter = children_.begin();
    while (iter != children_.end()) {
        if ((*iter)->chainEqual(idx.getChain())) {
            break;
        }
        iter++;
    }

    if (iter != children_.end()) {
        return *iter;
    }

    return std::make_shared<Node>();
}

std::optional<std::shared_ptr<Node>> Node::getChildAt(int targetIdx) const {
    if (targetIdx >= 0 && targetIdx < getNumOfChildNodes()) {
        return children_[targetIdx];
    }

    return std::nullopt;
}

int Node::getNumOfChildNodes() const { return static_cast<int>(children_.size()); }

void Node::setNodeIdx(NodeIdx::chain_t chain, int last) { idx_.setChain(chain, last); }

NodeIdx Node::getNodeIdx() { return idx_; }

void Node::setParentNode(std::weak_ptr<Node> parent) { parent_ = parent; }

std::optional<std::shared_ptr<Node>> Node::getParentNode() {
    std::shared_ptr<Node> ptr = parent_.lock();
    if (!ptr) {
        return std::nullopt;
    }

    return ptr;
}

void Node::setAsRoot() { idx_.setAsRoot(); }

bool Node::equal(std::shared_ptr<Node> other) { return other->chainEqual(idx_.getChain()); }

bool Node::chainEqual(NodeIdx::chain_t other) { return idx_.chainEqual(other); }

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)
