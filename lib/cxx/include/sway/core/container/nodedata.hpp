#ifndef SWAY_CORE_CONTAINER_NODEDATA_HPP
#define SWAY_CORE_CONTAINER_NODEDATA_HPP

#include <sway/core/container/nodeindex.hpp>
#include <sway/namespacemacros.hpp>

#include <string>
#include <vector>

NS_BEGIN_SWAY()
NS_BEGIN(core)

struct NodeData {
  std::vector<NodeIndex::ChainItemIndex_t> nodeidx;
  std::string name;
};

NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_CONTAINER_NODEDATA_HPP
