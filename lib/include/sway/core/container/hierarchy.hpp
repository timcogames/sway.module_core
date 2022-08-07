#ifndef SWAY_CORE_CONTAINER_HIERARCHY_HPP
#define SWAY_CORE_CONTAINER_HIERARCHY_HPP

#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeidx.hpp>
#include <sway/core/memory/safedeletemacros.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <algorithm>
#include <any>
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#ifdef _EMSCRIPTEN
#  include <emscripten/bind.h>
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

struct NodeData {
  std::vector<NodeIdx::index_t> nodeidx;
  std::string name;
};

#ifdef _EMSCRIPTEN
using NodeDataList = emscripten::val;
#else
using NodeDataList = std::vector<NodeData>;
#endif

class Hierarchy {
public:
  DECLARE_EMSCRIPTEN_BINDING()

  static std::optional<std::shared_ptr<Node>> findNode(std::shared_ptr<Node> parent, const NodeIdx &nodeIdx);

  Hierarchy();
  ~Hierarchy() = default;

  std::shared_ptr<Node> getRootNode();

  void setRootNode(std::shared_ptr<Node> root);

private:
  std::shared_ptr<Node> root_;
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif