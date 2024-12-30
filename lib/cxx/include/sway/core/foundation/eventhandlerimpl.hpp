#ifndef SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP
#define SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/events/_typedefs.hpp>
#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventhandler.hpp>

namespace sway::core {

template <class TYPE>
class TEventHandlerImpl : public EventHandler {
public:
  using HandlerFunction_t = bool (TYPE::*)(const EventTypedefs::UniquePtr_t &);

#pragma region "Ctors/Dtor"

  TEventHandlerImpl(TYPE *receiver, HandlerFunction_t func)
      : EventHandler(receiver)
      , function_(std::move(func)) {}

  virtual ~TEventHandlerImpl() = default;

#pragma endregion

#pragma region "Implementation EventHandler methods"

  virtual auto invoke(const EventTypedefs::UniquePtr_t &evt) -> bool {
    auto *receiver = static_cast<TYPE *>(receiver_);
    return (receiver->*function_)(std::move(evt));
  }

#pragma endregion

private:
  HandlerFunction_t function_;  // Функцию обработчика событий.
};

#ifdef EMSCRIPTEN_PLATFORM
class EventHandlerImpl : public EventHandler {
public:
  static void registerEmsClass() {
#  ifdef EMSCRIPTEN_USE_BINDINGS
    emscripten::class_<EventHandlerImpl, emscripten::base<EventHandler>>("EventHandlerImpl")
        .constructor<EventableTypedefs::Ptr_t, emscripten::val>()
        .function("invoke", &EventHandlerImpl::invoke, emscripten::allow_raw_pointers());
#  endif
  }

  EventHandlerImpl(EventableTypedefs::Ptr_t receiver, emscripten::val func)
      : EventHandler(receiver)
      , function_(func) {}

  virtual ~EventHandlerImpl() = default;

#  pragma region "Implementation EventHandler methods"

  virtual auto invoke(const EventTypedefs::UniquePtr_t &evt) -> bool {
    if (function_.typeOf().as<std::string>() == "function") {
      function_(std::move(evt));
    } else {
      EM_ASM(throw "callback is not a function");
    }
  }

#  pragma endregion

private:
  emscripten::val function_;  // Функцию обработчика событий.
};
#endif

}  // namespace sway::core

#define EVENT_HANDLER(CLASS_NAME, FUNC) (new sway::core::TEventHandlerImpl<CLASS_NAME>(this, &CLASS_NAME::FUNC))

#endif  // SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP
