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

EMSCRIPTEN_BINDING_BEGIN(Node)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<Node>("Node")
    .smart_ptr_constructor("Node", &std::make_shared<Node>)
    .function("addChildNode", &Node::addChildNode, emscripten::allow_raw_pointers())
    .function("removeChildNode", &Node::removeChildNode, emscripten::allow_raw_pointers())
    .function("getNumOfChildNodes", &Node::getNumOfChildNodes)
    .function("getParentNode", &Node::getParentNode, emscripten::allow_raw_pointers())
    .function("getChildAt", &Node::getChildAt, emscripten::allow_raw_pointers())
    .function("getNodeIndex", &Node::getNodeIndex)
    .property("visible", &Node::isVisible, &Node::setVisible);
#endif
EMSCRIPTEN_BINDING_END()

Node::Node()
    : idx_(NodeIndex())
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

void Node::addChildNode(NodeTypedefs::SharedPtr_t child) {
  auto childParentNode = child->getParentNode();
  if (childParentNode) {
    printf("%s %s\n", childParentNode->get()->getNodeIndex().toStr().c_str(), "Node alread has parent");
    return;
  }

  child->setParentNode(weak_from_this());

  child->setNodeIndex(idx_.getChain(), getNumOfChildNodes());
  for (const auto &childNode : child->getChildNodes()) {
    recursiveAddChainLinks(childNode, child->getNodeIndex());
  }

  children_.push_back(child);

  auto *eventdata = new NodeEventData();
  eventdata->nodeidx = child->getNodeIndex();
  emit(EVT_ADDED, new NodeAddedEvent(0, eventdata), [&](foundation::EventHandler::Ptr_t handler) {
    return static_cast<NodeTypedefs::Ptr_t>(handler->getSender())->getNodeIndex().equal(getNodeIndex());
  });
}

void Node::recursiveAddChainLinks(NodeTypedefs::SharedPtr_t child, NodeIndex parentIdx) {
  auto chain = child->getNodeIndex().getChain();
  auto parentChain = parentIdx.getChain();

  chain.insert(chain.begin() + 1, parentChain.begin() + 1, parentChain.end());
  child->setNodeIndex(chain, NODEIDX_NEGATIVE);

  for (const auto &childNode : child->getChildNodes()) {
    recursiveAddChainLinks(childNode, child->getNodeIndex());
  }
}

void Node::removeChildNode(NodeTypedefs::SharedPtr_t child) {
  // clang-format off
  children_.erase(std::remove_if(children_.begin(), children_.end(), [&](NodeTypedefs::SharedPtr_t node) {
    auto const result = node->equal(child);
    if (result) {
      for (auto childNode : child->getChildNodes()) {
        recursiveRemoveChainLinks(childNode, getNodeIndex());
      }

      child->setParentNode(NodeTypedefs::WeakPtr_t());
      child->setAsRoot();
    }
    return result;
  }), children_.end());
  // clang-format on

  auto *eventdata = new NodeEventData();
  eventdata->nodeidx = child->getNodeIndex();
  emit(EVT_REMOVED, new NodeRemovedEvent(0, eventdata), [&](foundation::EventHandler::Ptr_t) { return true; });
}

void Node::recursiveRemoveChainLinks(NodeTypedefs::SharedPtr_t child, NodeIndex parentIdx) {
  if (!parentIdx.chainEqual({NODEIDX_NEGATIVE})) {
    auto chain = child->getNodeIndex().getChain();
    chain.erase(chain.begin(), chain.begin() + parentIdx.getDepth());
    chain.at(0) = NODEIDX_ROOT;
    child->setNodeIndex(chain, NODEIDX_NEGATIVE);
  }

  for (const auto &childNode : child->getChildNodes()) {
    recursiveRemoveChainLinks(childNode, parentIdx);
  }
}

auto Node::getChildNodes() -> NodeTypedefs::Container_t { return children_; }

auto Node::getChildNode(const NodeIndex &idx) const -> NodeTypedefs::SharedPtr_t {
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

auto Node::getChildAt(int targetIdx) const -> NodeTypedefs::OptionalSharedPtr_t {
  if (targetIdx >= 0 && targetIdx < getNumOfChildNodes()) {
    return children_[targetIdx];
  }

  return std::nullopt;
}

auto Node::getNumOfChildNodes() const -> int { return static_cast<int>(children_.size()); }

void Node::setNodeIndex(const NodeIndex::ChainVec_t &chain, int last) { idx_.setChain(chain, last); }

auto Node::getNodeIndex() -> NodeIndex { return idx_; }

void Node::setParentNode(NodeTypedefs::WeakPtr_t parent) { parent_ = parent; }

auto Node::getParentNode() -> NodeTypedefs::OptionalSharedPtr_t {
  auto ptr = parent_.lock();
  if (!ptr) {
    return std::nullopt;
  }

  return ptr;
}

auto Node::getParentNodeByDepth(int depth) -> NodeTypedefs::SharedPtr_t {
  auto node = shared_from_this();
  while (depth != 0 && node->getNodeIndex().getDepth() > depth) {
    node = getParentNode().value();
  }

  return node;
}

void Node::setAsRoot() { idx_.setAsRoot(); }

auto Node::equal(NodeTypedefs::SharedPtr_t other) -> bool { return other->chainEqual(idx_.getChain()); }

auto Node::chainEqual(NodeIndex::ChainVec_t other) -> bool { return idx_.chainEqual(other); }

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)

auto createNode() -> NodeTypedefs::JsPtr_t { return Node::toJs(new Node()); }

void deleteNode(NodeTypedefs::JsPtr_t node) {
  auto obj = Node::fromJs(node);
  SAFE_DELETE_OBJECT(obj);
}

void addChildNode(NodeTypedefs::JsPtr_t root, NodeTypedefs::JsPtr_t node) {
  auto obj = Node::fromJs(root);
  if (!obj) {
    // TODO
  }

  return obj->addChildNode(NodeTypedefs::SharedPtr_t(Node::fromJs(node)));
}

auto getNodeIndex(NodeTypedefs::JsPtr_t node) -> lpcstr_t {
  auto obj = Node::fromJs(node);
  if (!obj) {
    // TODO
  }

  auto idxStr = obj->getNodeIndex().toStr();
  auto result = new s8_t[idxStr.size() + 1];
  strcpy(result, idxStr.c_str());

  return result;
}

auto getChildNodes(NodeTypedefs::JsPtr_t node) -> NodeTypedefs::JsPtrArray_t {
  auto obj = Node::fromJs(node);
  if (!obj) {
    // TODO
  }

  auto nodes = obj->getChildNodes();
  NodeTypedefs::JsPtr_t arr[nodes.size()];

  for (auto i = 0; i < nodes.size(); i++) {
    arr[i] = Node::toJs(nodes[i]);
  }

  auto *result = &arr[0];
  return result;
}

auto getNumOfChildNodes(NodeTypedefs::JsPtr_t node) -> i32_t {
  auto obj = Node::fromJs(node);
  if (!obj) {
    // TODO
  }

  return obj->getNumOfChildNodes();
}

#endif

NS_END()  // namespace core
NS_END()  // namespace sway
