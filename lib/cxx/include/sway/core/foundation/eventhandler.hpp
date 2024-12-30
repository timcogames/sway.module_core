#ifndef SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP
#define SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/emscriptenmacros.hpp>
#include <sway/keywords.hpp>

namespace sway::core {

/**
 * @class EventHandler
 * @brief Описывает обработчик для события.
 */
class EventHandler {
  DECLARE_EMSCRIPTEN_BINDING()

public:
#pragma region "Ctors/Dtor"

  EventHandler(EventableTypedefs::Ptr_t receiver);

  virtual ~EventHandler() = default;

#pragma endregion

#pragma region "Pure virtual methods"

  virtual auto invoke(const EventTypedefs::UniquePtr_t &evt) -> bool = 0;

#pragma endregion

  [[nodiscard]] auto getSender() const -> EventableTypedefs::Ptr_t;

  void setSender(EventableTypedefs::Ptr_t sender);

  [[nodiscard]] auto getReceiver() const -> EventableTypedefs::Ptr_t;

  [[nodiscard]] auto getEventName() const -> std::string { return eventname_; }

  void setEventName(const std::string &name) { eventname_ = name; }

protected:
  EventableTypedefs::Ptr_t sender_ = nullptr;  // Отправитель события.
  EventableTypedefs::Ptr_t receiver_;  // Слушатель события.
  std::string uniqueid_;  // Уникальный идентификатор, который будет связан с функцией обработчика событий.
  std::string eventname_;  // Название события.
};

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
class EventHandlerWrapper : public emscripten::wrapper<EventHandler> {
public:
  EMSCRIPTEN_WRAPPER(EventHandlerWrapper);

  virtual auto invoke(const EventTypedefs::UniquePtr_t &event) -> bool override { return call<bool>("invoke", evt); }
};
#endif

}  // namespace sway::core

#endif  // SWAY_CORE_FOUNDATION_EVENTHANDLER_HPP
