#ifndef SWAY_CORE_FOUNDATION_EVENTABLE_HPP
#define SWAY_CORE_FOUNDATION_EVENTABLE_HPP

#include <sway/classpointermacros.hpp>
#include <sway/core/foundation/eventhandler.hpp>
#include <sway/core/foundation/types.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <algorithm>  // std::remove_if
#include <functional>
#include <string>
#include <vector>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

using EmitPredicate_t = std::function<bool(EventHandler::Ptr_t)>;

class Eventable {
  DECLARE_CLASS_POINTER_ALIASES(Eventable)
  DECLARE_EMSCRIPTEN_BINDING()

public:
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

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_FOUNDATION_EVENTABLE_HPP
