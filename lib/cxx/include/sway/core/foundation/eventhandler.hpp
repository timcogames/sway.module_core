#ifndef SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP
#define SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/types.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/pointermacros.hpp>
#include <sway/types.hpp>

#include <string>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

class Eventable;

/**
 * @class EventHandler
 * @brief Описывает обработчик для события.
 */
class EventHandler {
  DECLARE_PTR_ALIASES(EventHandler)
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  EventHandler(EventablePtr_t receiver);

  virtual ~EventHandler() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  PURE_VIRTUAL(void invoke(Event::Ptr_t evt));

#pragma endregion

  [[nodiscard]]
  auto getSender() const -> EventablePtr_t;

  void setSender(EventablePtr_t sender);

  [[nodiscard]]
  auto getReceiver() const -> EventablePtr_t;

  [[nodiscard]]
  auto getEventName() const -> std::string {
    return eventname_;
  }

  void setEventName(const std::string &name) { eventname_ = name; }

protected:
  EventablePtr_t sender_ = nullptr;  // Отправитель события.
  EventablePtr_t receiver_;  // Слушатель события.
  std::string uniqueid_;  // Уникальный идентификатор, который будет связан с функцией обработчика событий.
  std::string eventname_;  // Название события.
};

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
class EventHandlerWrapper : public emscripten::wrapper<EventHandler> {
public:
  EMSCRIPTEN_WRAPPER(EventHandlerWrapper);

  MTHD_VIRTUAL_OVERRIDE(void invoke(Event::Ptr_t evt)) { return call<void>("invoke", evt); }
};
#endif

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP
