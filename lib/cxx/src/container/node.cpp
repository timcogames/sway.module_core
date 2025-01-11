#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeeventdata.hpp>
#include <sway/core/container/nodeindexrepresentation.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/core/foundation/_typedefs.hpp>
#include <sway/core/foundation/context.hpp>
#include <sway/core/foundation/eventable.hpp>
#include <sway/core/foundation/eventhandler.hpp>
#include <sway/core/utilities/visitor/traverseractions.hpp>

namespace sway::core {

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
    : index_(NodeIndex())
    , parent_({}) {}

Node::~Node() { children_.clear(); }

auto Node::traverse(typedefs::TraverserPtr_t traverser) -> u32_t {
  switch (static_cast<TraverserAction::Enum>(traverser->visit(this))) {
    case TraverserAction::Enum::CONTINUE:
      for (const auto &node : getChildNodes()) {
        if (node->traverse(traverser) == toBase(TraverserAction::Enum::ABORT)) {
          return toBase(TraverserAction::Enum::ABORT);
        }
      }

    case TraverserAction::Enum::PRUNE:
      return toBase(TraverserAction::Enum::CONTINUE);

    case TraverserAction::Enum::ABORT:
    default:
      break;
  }

  return toBase(TraverserAction::Enum::NONE);
}

void Node::addChildNode(NodeTypedefs::SharedPtr_t child) {
  auto childParentNode = child->getParentNode();
  if (childParentNode) {
    printf("%s %s\n", Representation<NodeIndex>::get(childParentNode->get()->getNodeIndex()).c_str(),
        "Node alread has parent");
    return;
  }

  child->setParentNode(weak_from_this());

  child->setNodeIndex(index_.getChain(), getNumOfChildNodes());
  for (const auto &childNode : child->getChildNodes()) {
    recursiveAddChainLinks(childNode, child->getNodeIndex());
  }

  children_.push_back(child);

  auto *eventdata = new NodeEventData();
  eventdata->nodeidx = child->getNodeIndex();
  emit(EVT_ADDED, std::make_unique<NodeAddedEvent>(0, eventdata), [&](EventHandlerTypedefs::Ptr_t handler) {
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
  emit(
      EVT_REMOVED, std::make_unique<NodeRemovedEvent>(0, eventdata), [&](EventHandlerTypedefs::Ptr_t) { return true; });
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

void Node::setNodeIndex(const NodeIndexChainTypedefs::Container_t &chain, int last) { index_.setChain(chain, last); }

auto Node::getNodeIndex() -> NodeIndex { return index_; }

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

void Node::setAsRoot() { index_.setAsRoot(); }

auto Node::equal(NodeTypedefs::SharedPtr_t other) -> bool { return other->chainEqual(index_.getChain()); }

auto Node::chainEqual(NodeIndexChainTypedefs::Container_t other) -> bool { return index_.chainEqual(other); }

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

  auto idxStr = Representation<NodeIndex>::get(obj->getNodeIndex());
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

}  // namespace sway::core
