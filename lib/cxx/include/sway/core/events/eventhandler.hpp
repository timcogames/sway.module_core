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
  using Ptr_t = EventHandler *;

#pragma region "Ctors/Dtor"

  virtual ~EventHandler() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(auto invoke(const foundation::Event::UniquePtr_t &event) -> bool);

#pragma endregion
};

NAMESPACE_END(evts)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_EVTS_EVENTHANDLER_HPP
