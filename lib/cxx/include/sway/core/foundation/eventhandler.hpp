#ifndef SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP
#define SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

class Eventable;

/**
 * @class EventHandler
 * @brief Описывает обработчик для события.
 */
class EventHandler {
public:
  DECLARE_EMSCRIPTEN_BINDING()

  EventHandler(Eventable *receiver);

  virtual ~EventHandler() = default;

  PURE_VIRTUAL(void invoke(Event *event));

  [[nodiscard]] auto getSender() const -> Eventable *;

  void setSender(Eventable *sender);

  [[nodiscard]] auto getReceiver() const -> Eventable *;

  [[nodiscard]] auto getEventName() const -> std::string { return eventname_; }

  void setEventName(const std::string &name) { eventname_ = name; }

protected:
  Eventable *sender_ = nullptr;  // Отправитель события.
  Eventable *receiver_;  // Слушатель события.
  std::string uniqueid_;  // Уникальный идентификатор, который будет связан с функцией обработчика событий.
  std::string eventname_;  // Название события.
};

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
class EventHandlerWrapper : public emscripten::wrapper<EventHandler> {
public:
  EMSCRIPTEN_WRAPPER(EventHandlerWrapper);

  MTHD_OVERRIDE(void invoke(Event *event)) { return call<void>("invoke", event); }
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP
