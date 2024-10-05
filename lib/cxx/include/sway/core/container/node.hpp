#ifndef SWAY_CORE_CONTAINER_NODE_HPP
#define SWAY_CORE_CONTAINER_NODE_HPP

#include <sway/classpointermacros.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/core/container/types.hpp>
#include <sway/core/foundation/declareeventmacros.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventable.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/core/misc/format.hpp>
#include <sway/core/misc/guid.hpp>
#include <sway/core/util/traverser.hpp>
#include <sway/core/util/visitable.hpp>
#include <sway/coremacros.hpp>
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

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(container)

class Node : public std::enable_shared_from_this<Node>, public util::Visitable, public foundation::Eventable {
  DECLARE_CLASS_POINTER_ALIASES(Node)
  DECLARE_EVENT(EVT_ADDED, NodeAdded)
  DECLARE_EVENT(EVT_REMOVED, NodeRemoved)
  DECLARE_EMSCRIPTEN(Node)
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  Node();

  virtual ~Node();

#pragma endregion

#pragma region "Override Visitable methods"

  MTHD_VIRTUAL_OVERRIDE(auto traverse(util::TraverserPtr_t traverser) -> u32_t);

#pragma endregion

  void addChildNode(Node::SharedPtr_t child);

  void removeChildNode(Node::SharedPtr_t child);

  auto getChildNodes() -> std::vector<Node::SharedPtr_t>;

  [[nodiscard]]
  auto getChildNode(const NodeIdx &idx) const -> Node::SharedPtr_t;

  [[nodiscard]]
  auto getChildAt(int targetIdx) const -> std::optional<Node::SharedPtr_t>;

  [[nodiscard]]
  auto getNumOfChildNodes() const -> int;

  void setNodeIdx(const NodeIdx::Chain_t &chain, int last);

  auto getNodeIdx() -> NodeIdx;

  void setParentNode(Node::WeakPtr_t parent);

  auto getParentNode() -> std::optional<Node::SharedPtr_t>;

  auto getParentNodeByDepth(int depth) -> Node::SharedPtr_t;

  auto equal(Node::SharedPtr_t other) -> bool;

  auto chainEqual(NodeIdx::Chain_t other) -> bool;

  void setAsRoot();

  void setVisible(bool value) { visible_ = value; }

  [[nodiscard]]
  auto isVisible() const -> bool {
    return visible_;
  }

protected:
  template <typename TYPE>
  auto getSharedFrom(TYPE *ptr) -> std::shared_ptr<TYPE> {
    return std::static_pointer_cast<TYPE>(static_cast<Node::Ptr_t>(ptr)->shared_from_this());
  }

private:
  void recursiveAddChainLinks(Node::SharedPtr_t child, NodeIdx parentNodeIdx);

  void recursiveRemoveChainLinks(Node::SharedPtr_t child, NodeIdx parentNodeIdx);

  NodeIdx idx_;
  Node::WeakPtr_t parent_;
  std::vector<Node::SharedPtr_t> children_;
  bool visible_;
};

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

D_MODULE_CORE_INTERFACE_EXPORT_API auto createNode() -> Node::JavaScriptPtr_t;

D_MODULE_CORE_INTERFACE_EXPORT_API void deleteNode(Node::JavaScriptPtr_t node);

D_MODULE_CORE_INTERFACE_EXPORT_API void addChildNode(Node::JavaScriptPtr_t root, Node::JavaScriptPtr_t node);

D_MODULE_CORE_INTERFACE_EXPORT_API auto getNodeIdx(Node::JavaScriptPtr_t node) -> lpcstr_t;

D_MODULE_CORE_INTERFACE_EXPORT_API auto getChildNodes(Node::JavaScriptPtr_t node) -> Node::JavaScriptPtr_t *;

D_MODULE_CORE_INTERFACE_EXPORT_API auto getNumOfChildNodes(Node::JavaScriptPtr_t node) -> i32_t;

EXTERN_C_END
#endif

NS_END()  // namespace container
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_CONTAINER_NODE_HPP
