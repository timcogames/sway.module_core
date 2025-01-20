#ifndef SWAY_CORE_CONTAINER_HIERARCHY_HPP
#define SWAY_CORE_CONTAINER_HIERARCHY_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/container/_typedefs.hpp>
#include <sway/core/container/node.hpp>
#include <sway/core/container/nodedata.hpp>
#include <sway/core/container/nodeindex.hpp>
#include <sway/coremacros.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/types.hpp>
#include <sway/visibilitymacros.hpp>

namespace sway::core {

class Hierarchy : public Emscripteable<Hierarchy> {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Define aliases"

  using Ptr_t = HierarchyPtr_t;
  using JsPtr_t = HierarchyJsPtr_t;

#pragma endregion

#pragma region "Static methods"

  static auto findNode(NodeSharedPtr_t parent, const NodeIndex &nodeIdx) -> NodeOptionalSharedPtr_t;

#pragma endregion

#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  Hierarchy();

  ~Hierarchy() = default;

  /** @} */
#pragma endregion

  auto getRootNode() -> NodeSharedPtr_t;

  void setRootNode(NodeSharedPtr_t root);

private:
  NodeSharedPtr_t root_;
};

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

D_MODULE_CORE_INTERFACE_EXPORT_API auto createHierarchy() -> HierarchyJsPtr_t;

D_MODULE_CORE_INTERFACE_EXPORT_API void deleteHierarchy(HierarchyJsPtr_t hierarchy);

D_MODULE_CORE_INTERFACE_EXPORT_API auto getRootNode(HierarchyJsPtr_t hierarchy) -> NodeJsPtr_t;

EXTERN_C_END
#endif

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_HIERARCHY_HPP
