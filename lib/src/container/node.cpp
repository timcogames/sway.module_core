#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeeventuserdata.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/core/foundation/context.hpp>

#include <algorithm>  // std::remove_if
#include <functional>

#ifdef _EMSCRIPTEN
#  include <emscripten/bind.h>
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

EMSCRIPTEN_BINDING_BEGIN(Node)
#ifdef _EMSCRIPTEN
emscripten::class_<Node>("Node")
    .smart_ptr_constructor("Node", &std::make_shared<Node>)
    .function("addChildNode", &Node::addChildNode, emscripten::allow_raw_pointers())
    .function("removeChildNode", &Node::removeChildNode, emscripten::allow_raw_pointers())
    .function("getNumOfChildNodes", &Node::getNumOfChildNodes)
    .function("getParentNode", &Node::getParentNode, emscripten::allow_raw_pointers())
    .function("getChildAt", &Node::getChildAt, emscripten::allow_raw_pointers())
    .function("getNodeIdx", &Node::getNodeIdx)
    .property("visible", &Node::isVisible, &Node::setVisible);
#endif
EMSCRIPTEN_BINDING_END()

Node::Node()
    : idx_(NodeIdx())
    , parent_({})
    , visible_(true) {}

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

  NodeEventUserData eventdata;
  eventdata.nodeidx = child->getNodeIdx();
  emit(EVT_ADDED, new NodeAddedEvent(0, &eventdata), [&](foundation::AEventHandler *handler) {
    return static_cast<Node *>(handler->getSender())->getNodeIdx().equal(getNodeIdx());
  });
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

  NodeEventUserData eventdata;
  eventdata.nodeidx = child->getNodeIdx();
  emit(EVT_REMOVED, new NodeRemovedEvent(0, &eventdata), [&](foundation::AEventHandler *) { return true; });
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

void Node::setNodeIdx(const NodeIdx::chain_t &chain, int last) { idx_.setChain(chain, last); }

NodeIdx Node::getNodeIdx() { return idx_; }

void Node::setParentNode(std::weak_ptr<Node> parent) { parent_ = parent; }

std::optional<std::shared_ptr<Node>> Node::getParentNode() {
  std::shared_ptr<Node> ptr = parent_.lock();
  if (!ptr) {
    return std::nullopt;
  }

  return ptr;
}

std::shared_ptr<Node> Node::getParentNodeByDepth(int depth) {
  auto node = shared_from_this();
  while (depth != 0 && node->getNodeIdx().getDepth() > depth) {
    node = getParentNode().value();
  }

  return node;
}

void Node::setAsRoot() { idx_.setAsRoot(); }

bool Node::equal(std::shared_ptr<Node> other) { return other->chainEqual(idx_.getChain()); }

bool Node::chainEqual(NodeIdx::chain_t other) { return idx_.chainEqual(other); }

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)
