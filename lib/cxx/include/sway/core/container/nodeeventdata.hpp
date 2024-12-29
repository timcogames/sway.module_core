#ifndef SWAY_CORE_CONTAINER_NODEEVENTDATA_HPP
#define SWAY_CORE_CONTAINER_NODEEVENTDATA_HPP

#include <sway/core/container/nodeindex.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NS_BEGIN_SWAY()
NS_BEGIN(core)

struct NodeEventData : public EventData {
  NodeIndex nodeidx;
};

NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_CONTAINER_NODEEVENTDATA_HPP
