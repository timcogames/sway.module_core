#ifndef SWAY_CORE_EVTS_EVENTHANDLER_HPP
#define SWAY_CORE_EVTS_EVENTHANDLER_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>

#include <memory>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(evts)

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

NS_END()  // namespace evts
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_EVTS_EVENTHANDLER_HPP
