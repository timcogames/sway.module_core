#ifndef SWAY_CORE_CONTAINER_NODEEVENTUSERDATA_HPP
#define SWAY_CORE_CONTAINER_NODEEVENTUSERDATA_HPP

#include <sway/core/container/nodeidx.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(container)

struct NodeEventUserData : public foundation::EventUserData {
  NodeIdx nodeidx;

  MTHD_OVERRIDE(std::string serialize() const) { return ""; }
};

NAMESPACE_END(container)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
