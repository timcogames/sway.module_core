#ifndef SWAY_CORE_CONTAINER_HIERARCHY_HPP
#define SWAY_CORE_CONTAINER_HIERARCHY_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/container/_typedefs.hpp>
#include <sway/core/container/node.hpp>
#include <sway/core/container/nodedata.hpp>
#include <sway/core/container/nodeindex.hpp>
#include <sway/coremacros.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/pointermacros.hpp>
#include <sway/types.hpp>
#include <sway/visibilitymacros.hpp>

namespace sway::core {

#ifdef EMSCRIPTEN_PLATFORM
using NodeDataList = emscripten::val;
#else
using NodeDataList = std::vector<NodeData>;
#endif

class Hierarchy : public Emscripteable<Hierarchy> {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Static methods"

  static auto findNode(NodeTypedefs::SharedPtr_t parent, const NodeIndex &nodeIdx) -> NodeTypedefs::OptionalSharedPtr_t;

#pragma endregion

#pragma region "Ctors/Dtor"

  Hierarchy();

  ~Hierarchy() = default;

#pragma endregion

  auto getRootNode() -> NodeTypedefs::SharedPtr_t;

  void setRootNode(NodeTypedefs::SharedPtr_t root);

private:
  NodeTypedefs::SharedPtr_t root_;
};

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

D_MODULE_CORE_INTERFACE_EXPORT_API auto createHierarchy() -> HierarchyTypedefs::JsPtr_t;

D_MODULE_CORE_INTERFACE_EXPORT_API void deleteHierarchy(HierarchyTypedefs::JsPtr_t hierarchy);

D_MODULE_CORE_INTERFACE_EXPORT_API auto getRootNode(HierarchyTypedefs::JsPtr_t hierarchy) -> NodeTypedefs::JsPtr_t;

EXTERN_C_END
#endif

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_HIERARCHY_HPP
