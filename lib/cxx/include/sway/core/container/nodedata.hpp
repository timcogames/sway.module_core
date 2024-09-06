#ifndef SWAY_CORE_CONTAINER_NODEDATA_HPP
#define SWAY_CORE_CONTAINER_NODEDATA_HPP

#include <sway/core/container/nodeidx.hpp>
#include <sway/namespacemacros.hpp>

#include <string>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

struct NodeData {
  std::vector<NodeIdx::Index_t> nodeidx;
  std::string name;
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_CONTAINER_NODEDATA_HPP
