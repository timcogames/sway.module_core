#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeeventdata.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/core/foundation/context.hpp>
#include <sway/core/util/traverseractions.hpp>

#include <algorithm>  // std::remove_if
#include <functional>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(container)

EMSCRIPTEN_BINDING_BEGIN(Node)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
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
    , parent_({}) {}

Node::~Node() { children_.clear(); }

auto Node::traverse(util::TraverserPtr_t traverser) -> u32_t {
  switch (static_cast<util::TraverserAction::Enum>(traverser->visit(this))) {
    case util::TraverserAction::Enum::CONTINUE:
      for (const auto &node : getChildNodes()) {
        if (node->traverse(traverser) == detail::toBase(util::TraverserAction::Enum::ABORT)) {
          return detail::toBase(util::TraverserAction::Enum::ABORT);
        }
      }

    case util::TraverserAction::Enum::PRUNE:
      return detail::toBase(util::TraverserAction::Enum::CONTINUE);

    case util::TraverserAction::Enum::ABORT:
    default:
      break;
  }

  return detail::toBase(util::TraverserAction::Enum::NONE);
}

void Node::addChildNode(Node::SharedPtr_t child) {
  std::optional<Node::SharedPtr_t> childParentNode = child->getParentNode();
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

  auto *eventdata = new NodeEventData();
  eventdata->nodeidx = child->getNodeIdx();
  emit(EVT_ADDED, new NodeAddedEvent(0, eventdata), [&](foundation::EventHandler::Ptr_t handler) {
    return static_cast<Node::Ptr_t>(handler->getSender())->getNodeIdx().equal(getNodeIdx());
  });
}

void Node::recursiveAddChainLinks(Node::SharedPtr_t child, NodeIdx parentNodeIdx) {
  NodeIdx::ChainVec_t chain = child->getNodeIdx().getChain();
  NodeIdx::ChainVec_t parentChain = parentNodeIdx.getChain();

  chain.insert(chain.begin() + 1, parentChain.begin() + 1, parentChain.end());
  child->setNodeIdx(chain, NODEIDX_NEGATIVE);

  for (const auto &childNode : child->getChildNodes()) {
    recursiveAddChainLinks(childNode, child->getNodeIdx());
  }
}

void Node::removeChildNode(Node::SharedPtr_t child) {
  // clang-format off
  children_.erase(std::remove_if(children_.begin(), children_.end(), [&](Node::SharedPtr_t node) {
    auto const result = node->equal(child);
    if (result) {
      for (auto childNode : child->getChildNodes()) {
        recursiveRemoveChainLinks(childNode, getNodeIdx());
      }

      child->setParentNode(Node::WeakPtr_t());
      child->setAsRoot();
    }
    return result;
  }), children_.end());
  // clang-format on

  auto *eventdata = new NodeEventData();
  eventdata->nodeidx = child->getNodeIdx();
  emit(EVT_REMOVED, new NodeRemovedEvent(0, eventdata), [&](foundation::EventHandler::Ptr_t) { return true; });
}

void Node::recursiveRemoveChainLinks(Node::SharedPtr_t child, NodeIdx parentNodeIdx) {
  if (!parentNodeIdx.chainEqual({NODEIDX_NEGATIVE})) {
    auto chain = child->getNodeIdx().getChain();
    chain.erase(chain.begin(), chain.begin() + parentNodeIdx.getDepth());
    chain.at(0) = NODEIDX_ROOT;
    child->setNodeIdx(chain, NODEIDX_NEGATIVE);
  }

  for (const auto &childNode : child->getChildNodes()) {
    recursiveRemoveChainLinks(childNode, parentNodeIdx);
  }
}

auto Node::getChildNodes() -> Node::SharedPtrVec_t { return children_; }

auto Node::getChildNode(const NodeIdx &idx) const -> Node::SharedPtr_t {
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

auto Node::getChildAt(int targetIdx) const -> std::optional<Node::SharedPtr_t> {
  if (targetIdx >= 0 && targetIdx < getNumOfChildNodes()) {
    return children_[targetIdx];
  }

  return std::nullopt;
}

auto Node::getNumOfChildNodes() const -> int { return static_cast<int>(children_.size()); }

void Node::setNodeIdx(const NodeIdx::ChainVec_t &chain, int last) { idx_.setChain(chain, last); }

auto Node::getNodeIdx() -> NodeIdx { return idx_; }

void Node::setParentNode(Node::WeakPtr_t parent) { parent_ = parent; }

auto Node::getParentNode() -> std::optional<Node::SharedPtr_t> {
  Node::SharedPtr_t ptr = parent_.lock();
  if (!ptr) {
    return std::nullopt;
  }

  return ptr;
}

auto Node::getParentNodeByDepth(int depth) -> Node::SharedPtr_t {
  auto node = shared_from_this();
  while (depth != 0 && node->getNodeIdx().getDepth() > depth) {
    node = getParentNode().value();
  }

  return node;
}

void Node::setAsRoot() { idx_.setAsRoot(); }

auto Node::equal(Node::SharedPtr_t other) -> bool { return other->chainEqual(idx_.getChain()); }

auto Node::chainEqual(NodeIdx::ChainVec_t other) -> bool { return idx_.chainEqual(other); }

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)

auto createNode() -> Node::JavaScriptPtr_t { return Node::toJs(new Node()); }

void deleteNode(Node::JavaScriptPtr_t node) {
  auto obj = Node::fromJs(node);
  SAFE_DELETE_OBJECT(obj);
}

void addChildNode(Node::JavaScriptPtr_t root, Node::JavaScriptPtr_t node) {
  auto obj = Node::fromJs(root);
  if (!obj) {
    // TODO
  }

  return obj->addChildNode(Node::SharedPtr_t(Node::fromJs(node)));
}

auto getNodeIdx(Node::JavaScriptPtr_t node) -> lpcstr_t {
  auto obj = Node::fromJs(node);
  if (!obj) {
    // TODO
  }

  auto idxStr = obj->getNodeIdx().toStr();
  auto result = new s8_t[idxStr.size() + 1];
  strcpy(result, idxStr.c_str());

  return result;
}

auto getChildNodes(Node::JavaScriptPtr_t node) -> Node::JavaScriptPtr_t * {
  auto obj = Node::fromJs(node);
  if (!obj) {
    // TODO
  }

  auto nodes = obj->getChildNodes();
  Node::JavaScriptPtr_t arr[nodes.size()];

  for (auto i = 0; i < nodes.size(); i++) {
    arr[i] = Node::toJs(nodes[i]);
  }

  auto *result = &arr[0];
  return result;
}

auto getNumOfChildNodes(Node::JavaScriptPtr_t node) -> i32_t {
  auto obj = Node::fromJs(node);
  if (!obj) {
    // TODO
  }

  return obj->getNumOfChildNodes();
}

#endif

NS_END()  // namespace container
NS_END()  // namespace core
NS_END()  // namespace sway
