#ifndef SWAY_CORE_CONTAINER_NODE_HPP
#define SWAY_CORE_CONTAINER_NODE_HPP

#include <sway/core/container/nodeidx.hpp>
#include <sway/core/foundation/declareeventmacros.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventable.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/core/misc/format.hpp>
#include <sway/core/misc/guid.hpp>
#include <sway/core/utils/traverser.hpp>
#include <sway/core/utils/visitable.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>
#include <sway/visibilitymacros.hpp>

#include <algorithm>
#include <any>
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

class Node : public std::enable_shared_from_this<Node>, public utils::Visitable, public foundation::Eventable {
public:
  DECLARE_EMSCRIPTEN(Node)
  DECLARE_EMSCRIPTEN_BINDING()
  DECLARE_EVENT(EVT_ADDED, NodeAdded)
  DECLARE_EVENT(EVT_REMOVED, NodeRemoved)

  Node();

  virtual ~Node();

  // clang-format off
  MTHD_OVERRIDE(auto traverse(utils::Traverser *traverser) -> u32_t);  // clang-format on

  void addChildNode(std::shared_ptr<Node> child);

  void removeChildNode(std::shared_ptr<Node> child);

  auto getChildNodes() -> std::vector<std::shared_ptr<Node>>;

  auto getChildNode(const NodeIdx &idx) const -> std::shared_ptr<Node>;

  auto getChildAt(int targetIdx) const -> std::optional<std::shared_ptr<Node>>;

  auto getNumOfChildNodes() const -> int;

  void setNodeIdx(const NodeIdx::chain_t &chain, int last);

  auto getNodeIdx() -> NodeIdx;

  void setParentNode(std::weak_ptr<Node> parent);

  auto getParentNode() -> std::optional<std::shared_ptr<Node>>;

  auto getParentNodeByDepth(int depth) -> std::shared_ptr<Node>;

  auto equal(std::shared_ptr<Node> other) -> bool;

  auto chainEqual(NodeIdx::chain_t other) -> bool;

  void setAsRoot();

  void setVisible(bool value) { visible_ = value; }

  auto isVisible() const -> bool { return visible_; }

protected:
  template <typename T>
  auto sharedFrom(T *ptr) -> std::shared_ptr<T> {
    return std::static_pointer_cast<T>(static_cast<Node *>(ptr)->shared_from_this());
  }

private:
  void recursiveAddChainLinks(std::shared_ptr<Node> child, NodeIdx parentNodeIdx);

  void recursiveRemoveChainLinks(std::shared_ptr<Node> child, NodeIdx parentNodeIdx);

  NodeIdx idx_;
  std::weak_ptr<Node> parent_;
  std::vector<std::shared_ptr<Node>> children_;
  bool visible_;
};

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

EXPORT_API auto createNode() -> Node::JsPtr_t;

EXPORT_API void deleteNode(Node::JsPtr_t node);

EXPORT_API void addChildNode(Node::JsPtr_t root, Node::JsPtr_t node);

EXPORT_API auto getNodeIdx(Node::JsPtr_t node) -> lpcstr_t;

EXPORT_API auto getChildNodes(Node::JsPtr_t node) -> Node::JsPtr_t *;

EXPORT_API auto getNumOfChildNodes(Node::JsPtr_t node) -> s32_t;

EXTERN_C_END
#endif

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_CONTAINER_NODE_HPP
