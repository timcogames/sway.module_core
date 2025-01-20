
#include <sway/core/container/nodeindex.hpp>
#include <sway/core/container/nodeutil.hpp>

namespace sway::core {

template <typename TYPE>
auto Node::getChild(NodePtr_t parent, const NodeIndex &idx) -> std::shared_ptr<TYPE> {
  return NodeUtil::cast<TYPE>(parent->getChildNode(idx));
}

template <typename TYPE>
auto Node::getChild(NodePtr_t parent, const NodeIndexOptional_t &idxOpt) -> std::shared_ptr<TYPE> {
  return idxOpt.has_value() ? Node::getChild<TYPE>(parent, idxOpt.value()) : nullptr;
}

template <typename TYPE>
auto Node::getSharedFrom(TYPE *ptr) -> std::shared_ptr<TYPE> {
  return std::static_pointer_cast<TYPE>(static_cast<NodePtr_t>(ptr)->shared_from_this());
}

}  // namespace sway::core
