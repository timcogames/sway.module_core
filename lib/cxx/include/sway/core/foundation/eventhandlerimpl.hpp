#ifndef SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP
#define SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventhandler.hpp>
#include <sway/namespacemacros.hpp>

#include <algorithm>  // std::remove_if
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

template <class TYPE>
class TEventHandlerImpl : public EventHandler {
public:
  using HandlerFunction_t = void (TYPE::*)(Event *);

  TEventHandlerImpl(TYPE *receiver, HandlerFunction_t func)
      : EventHandler(receiver)
      , function_(std::move(func)) {}

  virtual ~TEventHandlerImpl() = default;

  MTHD_OVERRIDE(void invoke(Event *evt)) {
    auto *receiver = static_cast<TYPE *>(receiver_);
    (receiver->*function_)(evt);
  }

private:
  HandlerFunction_t function_;  // Функцию обработчика событий.
};

#ifdef EMSCRIPTEN_PLATFORM
class EventHandlerImpl : public EventHandler {
public:
  static void registerEmsClass() {
#  ifdef EMSCRIPTEN_USE_BINDINGS
    emscripten::class_<EventHandlerImpl, emscripten::base<EventHandler>>("EventHandlerImpl")
        .constructor<Eventable::Ptr_t, emscripten::val>()
        .function("invoke", &EventHandlerImpl::invoke, emscripten::allow_raw_pointers());
#  endif
  }

  EventHandlerImpl(Eventable::Ptr_t receiver, emscripten::val func)
      : EventHandler(receiver)
      , function_(func) {}

  virtual ~EventHandlerImpl() = default;

  MTHD_OVERRIDE(void invoke(Event *evt)) {
    if (function_.typeOf().as<std::string>() == "function") {
      function_(evt);
    } else {
      EM_ASM(throw "callback is not a function");
    }
  }

private:
  emscripten::val function_;  // Функцию обработчика событий.
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#define EVENT_HANDLER(CLASS_NAME, FUNC) \
  (new sway::core::foundation::TEventHandlerImpl<CLASS_NAME>(this, &CLASS_NAME::FUNC))

#endif  // SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP
