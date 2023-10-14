#ifndef SWAY_CORE_CONTAINER_HIERARCHY_HPP
#define SWAY_CORE_CONTAINER_HIERARCHY_HPP

#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>
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
#  ifdef EMSCRIPTEN_USE_WEB_BINDINGS
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
#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_WEB_BINDINGS)
  using HierarchyPtr = intptr_t;

  static Hierarchy *fromJs(HierarchyPtr hierarchy) { return reinterpret_cast<Hierarchy *>(hierarchy); }

  static HierarchyPtr toJs(Hierarchy *hierarchy) { return reinterpret_cast<HierarchyPtr>(hierarchy); }
#endif

  DECLARE_EMSCRIPTEN_BINDING()

  static auto findNode(std::shared_ptr<Node> parent, const NodeIdx &nodeIdx) -> std::optional<std::shared_ptr<Node>>;

  Hierarchy();

  ~Hierarchy() = default;

  auto getRootNode() -> std::shared_ptr<Node>;

  void setRootNode(std::shared_ptr<Node> root);

private:
  std::shared_ptr<Node> root_;
};

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_WEB_BINDINGS)

EXTERN_C EMSCRIPTEN_KEEPALIVE auto createHierarchy() -> Hierarchy::HierarchyPtr;

EXTERN_C EMSCRIPTEN_KEEPALIVE void deleteHierarchy(Hierarchy::HierarchyPtr hierarchy);

EXTERN_C EMSCRIPTEN_KEEPALIVE auto getRootNode(Hierarchy::HierarchyPtr hierarchy) -> Node::NodePtr;

#endif

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_CONTAINER_HIERARCHY_HPP
