#ifndef SWAY_CORE_CONTAINER_NODE_HPP
#define SWAY_CORE_CONTAINER_NODE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/container/_typedefs.hpp>
#include <sway/core/container/nodeindex.hpp>
#include <sway/core/container/nodeutil.hpp>
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
#include <sway/types.hpp>
#include <sway/visibilitymacros.hpp>

namespace sway::core {

class Node : public std::enable_shared_from_this<Node>,
             public util::Visitable,
             public foundation::Eventable,
             public Emscripteable<Node> {
  DECLARE_EVENT(EVT_ADDED, NodeAdded)
  DECLARE_EVENT(EVT_REMOVED, NodeRemoved)
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Static methods"

  template <typename TYPE>
  static auto getChild(NodeTypedefs::Ptr_t parent, const NodeIndex &idx) -> std::shared_ptr<TYPE>;

  template <typename TYPE>
  static auto getChild(NodeTypedefs::Ptr_t parent, const NodeIndexTypedefs::Optional_t &idxOpt)
      -> std::shared_ptr<TYPE>;

#pragma endregion

#pragma region "Ctors/Dtor"

  Node();

  virtual ~Node();

#pragma endregion

#pragma region "Override Visitable methods"

  virtual auto traverse(util::TraverserPtr_t traverser) -> u32_t override;

#pragma endregion

  void addChildNode(NodeTypedefs::SharedPtr_t child);

  void removeChildNode(NodeTypedefs::SharedPtr_t child);

  auto getChildNodes() -> NodeTypedefs::Container_t;

  [[nodiscard]] auto getChildNode(const NodeIndex &idx) const -> NodeTypedefs::SharedPtr_t;

  [[nodiscard]] auto getChildAt(i32_t targetIdx) const -> NodeTypedefs::OptionalSharedPtr_t;

  [[nodiscard]] auto getNumOfChildNodes() const -> i32_t;

  void setNodeIndex(const NodeIndex::ChainVec_t &chain, int last);

  auto getNodeIndex() -> NodeIndex;

  void setParentNode(NodeTypedefs::WeakPtr_t parent);

  auto getParentNode() -> NodeTypedefs::OptionalSharedPtr_t;

  auto getParentNodeByDepth(i32_t depth) -> NodeTypedefs::SharedPtr_t;

  auto equal(NodeTypedefs::SharedPtr_t other) -> bool;

  auto chainEqual(NodeIndex::ChainVec_t other) -> bool;

  void setAsRoot();

protected:
  template <typename TYPE>
  auto getSharedFrom(TYPE *ptr) -> std::shared_ptr<TYPE>;

private:
  void recursiveAddChainLinks(NodeTypedefs::SharedPtr_t child, NodeIndex parentIdx);

  void recursiveRemoveChainLinks(NodeTypedefs::SharedPtr_t child, NodeIndex parentIdx);

  NodeIndex idx_;
  NodeTypedefs::WeakPtr_t parent_;
  NodeTypedefs::Container_t children_;
};

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

D_MODULE_CORE_INTERFACE_EXPORT_API auto createNode() -> NodeTypedefs::JsPtr_t;

D_MODULE_CORE_INTERFACE_EXPORT_API void deleteNode(NodeTypedefs::JsPtr_t node);

D_MODULE_CORE_INTERFACE_EXPORT_API void addChildNode(NodeTypedefs::JsPtr_t root, NodeTypedefs::JsPtr_t node);

D_MODULE_CORE_INTERFACE_EXPORT_API auto getNodeIndex(NodeTypedefs::JsPtr_t node) -> lpcstr_t;

D_MODULE_CORE_INTERFACE_EXPORT_API auto getChildNodes(NodeTypedefs::JsPtr_t node) -> NodeTypedefs::JsPtrArray_t;

D_MODULE_CORE_INTERFACE_EXPORT_API auto getNumOfChildNodes(NodeTypedefs::JsPtr_t node) -> i32_t;

EXTERN_C_END
#endif

}  // namespace sway::core

#include <sway/core/container/node.inl>

#endif  // SWAY_CORE_CONTAINER_NODE_HPP
