#ifndef SWAY_CORE_CONTAINER_NODEEVENTDATA_HPP
#define SWAY_CORE_CONTAINER_NODEEVENTDATA_HPP

#include <sway/core/container/nodeindex.hpp>
#include <sway/core/foundation/eventdata.hpp>
#include <sway/keywords.hpp>
#include <sway/types.hpp>

namespace sway::core {

struct NodeEventData : public EventData {
  NodeIndex nodeidx;
};

}  // namespace sway::core

#endif  // SWAY_CORE_CONTAINER_NODEEVENTDATA_HPP
