#ifndef SWAY_CORE_FOUNDATION_EVENTABLE_HPP
#define SWAY_CORE_FOUNDATION_EVENTABLE_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/_typedefs.hpp>
#include <sway/core/foundation/eventhandler.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/types.hpp>

namespace sway::core {

using EmitPredicate_t = std::function<bool(EventHandlerTypedefs::Ptr_t)>;

class Eventable {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  Eventable() = default;

  ~Eventable() = default;

#pragma endregion

  void subscribe(EventableTypedefs::Ptr_t sender, const std::string &evtname, EventHandlerTypedefs::Ptr_t handler);

  void unsubscribe(const std::string &evtname);

  void emit(const std::string &evtname, const EventTypedefs::UniquePtr_t &evt, EmitPredicate_t predicate);

  auto findEventHandler(const std::string &evtname) -> EventHandlerTypedefs::Ptr_t;

protected:
  EventHandlerTypedefs::Container_t eventHandlers_;  // Обработчики событий.
};

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_EVENTABLE_HPP
