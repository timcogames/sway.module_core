#ifndef SWAY_CORE_CONTAINER_NODEDATA_HPP
#define SWAY_CORE_CONTAINER_NODEDATA_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/container/_typedefs.hpp>
#include <sway/core/container/nodeindex.hpp>

namespace sway::core {

struct NodeData {
  NodeIndexChainContainer_t nodeidx;
  std::string name;
};

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_NODEDATA_HPP
