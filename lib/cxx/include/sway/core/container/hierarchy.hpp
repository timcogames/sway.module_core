#ifndef SWAY_CORE_CONTAINER_HIERARCHY_HPP
#define SWAY_CORE_CONTAINER_HIERARCHY_HPP

#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>
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
  std::vector<NodeIdx::index_t> nodeidx;
  std::string name;
};

#ifdef EMSCRIPTEN_PLATFORM
using NodeDataList = emscripten::val;
#else
using NodeDataList = std::vector<NodeData>;
#endif

class Hierarchy {
public:
  DECLARE_EMSCRIPTEN(Hierarchy)
  DECLARE_EMSCRIPTEN_BINDING()

  static auto findNode(std::shared_ptr<Node> parent, const NodeIdx &nodeIdx) -> std::optional<std::shared_ptr<Node>>;

  Hierarchy();

  ~Hierarchy() = default;

  auto getRootNode() -> std::shared_ptr<Node>;

  void setRootNode(std::shared_ptr<Node> root);

private:
  std::shared_ptr<Node> root_;
};

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

MODULE_CORE_INTERFACE_EXPORT_API auto createHierarchy() -> Hierarchy::JsPtr_t;

MODULE_CORE_INTERFACE_EXPORT_API void deleteHierarchy(Hierarchy::JsPtr_t hierarchy);

MODULE_CORE_INTERFACE_EXPORT_API auto getRootNode(Hierarchy::JsPtr_t hierarchy) -> Node::JsPtr_t;

EXTERN_C_END
#endif

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_CONTAINER_HIERARCHY_HPP
