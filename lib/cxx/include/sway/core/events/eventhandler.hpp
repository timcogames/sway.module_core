#ifndef SWAY_CORE_EVTS_EVENTHANDLER_HPP
#define SWAY_CORE_EVTS_EVENTHANDLER_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

#include <memory>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(evts)

class EventHandler {
public:
  virtual ~EventHandler() = default;

  // clang-format off
  PURE_VIRTUAL(auto invoke(const std::unique_ptr<foundation::Event> &event) -> bool);  // clang-format on
};

NAMESPACE_END(evts)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_EVTS_EVENTHANDLER_HPP
