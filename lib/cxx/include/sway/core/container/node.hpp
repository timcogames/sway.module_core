#ifndef SWAY_CORE_CONTAINER_NODE_HPP
#define SWAY_CORE_CONTAINER_NODE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/container/_typedefs.hpp>
#include <sway/core/container/nodeindex.hpp>
#include <sway/core/container/nodeutil.hpp>
#include <sway/core/events/_typedefs.hpp>
#include <sway/core/foundation/declareeventmacros.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventable.hpp>
#include <sway/core/memory/safedelete.hpp>
#include <sway/core/misc/format.hpp>
#include <sway/core/misc/guid.hpp>
#include <sway/core/utilities/visitor/traverser.hpp>
#include <sway/core/utilities/visitor/visitable.hpp>
#include <sway/coremacros.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>
#include <sway/visibilitymacros.hpp>

namespace sway::core {

class Node : public std::enable_shared_from_this<Node>, public Visitable, public Eventable, public Emscripteable<Node> {
  DECLARE_EVENT(EVT_ADDED, NodeAdded)
  DECLARE_EVENT(EVT_REMOVED, NodeRemoved)
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Define aliases"

  using Ptr_t = NodePtr_t;
  using WeakPtr_t = NodeWeakPtr_t;
  using SharedPtr_t = NodeSharedPtr_t;
  using OptionalSharedPtr_t = NodeOptionalSharedPtr_t;
  using Container_t = NodeContainer_t;
  using JsPtr_t = NodeJsPtr_t;
  using JsPtrArray_t = NodeJsPtrArray_t;

#pragma endregion

#pragma region "Static methods"

  template <typename TYPE>
  static auto getChild(NodePtr_t parent, const NodeIndex &idx) -> std::shared_ptr<TYPE>;

  template <typename TYPE>
  static auto getChild(NodePtr_t parent, const NodeIndexOptional_t &idxOpt) -> std::shared_ptr<TYPE>;

#pragma endregion

#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  Node();

  virtual ~Node();

  /** @} */
#pragma endregion

#pragma region "Overridden Visitable methods"

  virtual auto traverse(typedefs::TraverserSharedPtr_t traverser) -> u32_t override;

#pragma endregion

  void addChildNode(NodeSharedPtr_t child);

  void removeChildNode(NodeSharedPtr_t child);

  auto getChildNodes() -> NodeContainer_t;

  [[nodiscard]] auto getChildNode(const NodeIndex &idx) const -> NodeSharedPtr_t;

  [[nodiscard]] auto getChildAt(i32_t targetIdx) const -> NodeOptionalSharedPtr_t;

  [[nodiscard]] auto getNumOfChildNodes() const -> i32_t;

  void setNodeIndex(const NodeIndexChainContainer_t &chain, int last);

  auto getNodeIndex() const -> NodeIndex;

  void setParentNode(NodeWeakPtr_t parent);

  auto getParentNode() -> NodeOptionalSharedPtr_t;

  auto getParentNodeByDepth(i32_t depth) -> NodeSharedPtr_t;

  auto equal(NodeSharedPtr_t other) -> bool;

  auto chainEqual(NodeIndexChainContainer_t other) -> bool;

  void setAsRoot();

protected:
  template <typename TYPE>
  auto getSharedFrom(TYPE *ptr) -> std::shared_ptr<TYPE>;

private:
  NodeIndex index_;
  NodeWeakPtr_t parent_;
  NodeContainer_t children_;
};

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

D_MODULE_CORE_INTERFACE_EXPORT_API auto createNode() -> NodeJsPtr_t;

D_MODULE_CORE_INTERFACE_EXPORT_API void deleteNode(NodeJsPtr_t node);

D_MODULE_CORE_INTERFACE_EXPORT_API void addChildNode(NodeJsPtr_t root, NodeJsPtr_t node);

D_MODULE_CORE_INTERFACE_EXPORT_API auto getNodeIndex(NodeJsPtr_t node) -> lpcstr_t;

D_MODULE_CORE_INTERFACE_EXPORT_API auto getChildNodes(NodeJsPtr_t node) -> NodeJsPtrArray_t;

D_MODULE_CORE_INTERFACE_EXPORT_API auto getNumOfChildNodes(NodeJsPtr_t node) -> i32_t;

EXTERN_C_END
#endif

}  // namespace sway::core

#include <sway/core/container/node.inl>

#endif  // SWAY_CORE_CONTAINER_NODE_HPP
