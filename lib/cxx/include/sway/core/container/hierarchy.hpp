#ifndef SWAY_CORE_CONTAINER_HIERARCHY_HPP
#define SWAY_CORE_CONTAINER_HIERARCHY_HPP

#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/core/container/types.hpp>
#include <sway/coremacros.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>
#include <sway/visibilitymacros.hpp>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

struct NodeData {
  std::vector<NodeIdx::Index_t> nodeidx;
  std::string name;
};

#ifdef EMSCRIPTEN_PLATFORM
using NodeDataList = emscripten::val;
#else
using NodeDataList = std::vector<NodeData>;
#endif

class Hierarchy {
  DECLARE_EMSCRIPTEN(Hierarchy)
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Define aliases"

  using Ptr_t = HierarchyPtr_t;
  using SharedPtr_t = HierarchySharedPtr_t;

#pragma endregion

#pragma region "Static methods"

  static auto findNode(Node::SharedPtr_t parent, const NodeIdx &nodeIdx) -> std::optional<Node::SharedPtr_t>;

#pragma endregion

#pragma region "Ctors/Dtor"

  Hierarchy();

  ~Hierarchy() = default;

#pragma endregion

  auto getRootNode() -> Node::SharedPtr_t;

  void setRootNode(Node::SharedPtr_t root);

private:
  Node::SharedPtr_t root_;
};

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

D_MODULE_CORE_INTERFACE_EXPORT_API auto createHierarchy() -> Hierarchy::JsPtr_t;

D_MODULE_CORE_INTERFACE_EXPORT_API void deleteHierarchy(Hierarchy::JsPtr_t hierarchy);

D_MODULE_CORE_INTERFACE_EXPORT_API auto getRootNode(Hierarchy::JsPtr_t hierarchy) -> Node::JsPtr_t;

EXTERN_C_END
#endif

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_CONTAINER_HIERARCHY_HPP
