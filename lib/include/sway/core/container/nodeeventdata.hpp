#ifndef SWAY_CORE_CONTAINER_NODEEVENTDATA_HPP
#define SWAY_CORE_CONTAINER_NODEEVENTDATA_HPP

#include <sway/core/container/nodeidx.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

struct NodeEventData : public foundation::EventData {
  NodeIdx nodeidx;

  // clang-format off
  MTHD_OVERRIDE(auto serialize() const -> std::string) {  // clang-format on
    return "";
  }

  MTHD_OVERRIDE(void deserialize(const std::string &jdata)) {}
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
