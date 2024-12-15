#ifndef SWAY_CORE_CONTAINER_HIERARCHY_HPP
#define SWAY_CORE_CONTAINER_HIERARCHY_HPP

#include <sway/core/container/node.hpp>
#include <sway/core/container/nodedata.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/core/container/types.hpp>
#include <sway/coremacros.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/pointermacros.hpp>
#include <sway/types.hpp>
#include <sway/visibilitymacros.hpp>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <sstream>
#include <string>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(container)

#ifdef EMSCRIPTEN_PLATFORM
using NodeDataList = emscripten::val;
#else
using NodeDataList = std::vector<NodeData>;
#endif

class Hierarchy {
  DECLARE_PTR_ALIASES(Hierarchy)
  DECLARE_EMSCRIPTEN(Hierarchy)
  DECLARE_EMSCRIPTEN_BINDING()

public:
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

D_MODULE_CORE_INTERFACE_EXPORT_API auto createHierarchy() -> Hierarchy::JavaScriptPtr_t;

D_MODULE_CORE_INTERFACE_EXPORT_API void deleteHierarchy(Hierarchy::JavaScriptPtr_t hierarchy);

D_MODULE_CORE_INTERFACE_EXPORT_API auto getRootNode(Hierarchy::JavaScriptPtr_t hierarchy) -> Node::JavaScriptPtr_t;

EXTERN_C_END
#endif

NS_END()  // namespace container
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_CONTAINER_HIERARCHY_HPP
