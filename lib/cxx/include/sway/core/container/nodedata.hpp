#ifndef SWAY_CORE_CONTAINER_NODEDATA_HPP
#define SWAY_CORE_CONTAINER_NODEDATA_HPP

#include <sway/core/container/nodeidx.hpp>
#include <sway/namespacemacros.hpp>

#include <string>
#include <vector>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(container)

struct NodeData {
  std::vector<NodeIdx::Index_t> nodeidx;
  std::string name;
};

NS_END()  // namespace container
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_CONTAINER_NODEDATA_HPP
