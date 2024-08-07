#ifndef SWAY_CORE_FOUNDATION_EVENTABLE_HPP
#define SWAY_CORE_FOUNDATION_EVENTABLE_HPP

#include <sway/core/foundation/eventhandler.hpp>
#include <sway/core/foundation/types.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <algorithm>  // std::remove_if
#include <functional>
#include <string>
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

using EmitPredicate_t = std::function<bool(EventHandler::Ptr_t)>;

class Eventable {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Define aliases"

  using Ptr_t = EventablePtr_t;

#pragma endregion

#pragma region "Ctors/Dtor"

  Eventable() = default;

  ~Eventable() = default;

#pragma endregion

  void subscribe(Eventable::Ptr_t sender, const std::string &eventname, EventHandler::Ptr_t handler);

  void unsubscribe(const std::string &eventname);

  void emit(const std::string &eventname, Event::Ptr_t event, EmitPredicate_t predicate);

  auto findEventHandler(const std::string &eventname) -> EventHandler::Ptr_t;

protected:
  std::vector<EventHandler::Ptr_t> eventHandlers_;  // Обработчики событий.
};

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_EVENTABLE_HPP
