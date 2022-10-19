#ifndef SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP
#define SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP

#include <sway/core/foundation/eventhandler.hpp>
#include <sway/namespacemacros.hpp>

#include <algorithm>  // std::remove_if
#include <vector>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

template <class TYPE>
class TEventHandlerImpl : public AEventHandler {
public:
  using HandlerFunction_t = void (TYPE::*)(Event *);

  TEventHandlerImpl(TYPE *receiver, HandlerFunction_t function)
      : AEventHandler(receiver)
      , function_(std::move(function)) {}

  virtual ~TEventHandlerImpl() = default;

  MTHD_OVERRIDE(void invoke(Event *event)) {
    TYPE *receiver = static_cast<TYPE *>(receiver_);
    (receiver->*function_)(event);
  }

private:
  HandlerFunction_t function_; /*!< Функцию обработчика событий. */
};

#ifdef _EMSCRIPTEN
class EventHandlerImpl : public AEventHandler {
public:
  static void registerEmsClass() {
    emscripten::class_<EventHandlerImpl, emscripten::base<AEventHandler>>("EventHandlerImpl")
        .constructor<Eventable *, emscripten::val>()
        .function("invoke", &EventHandlerImpl::invoke, emscripten::allow_raw_pointers());
  }

  EventHandlerImpl(Eventable *receiver, emscripten::val function)
      : AEventHandler(receiver)
      , function_(function) {}

  virtual ~EventHandlerImpl() = default;

  MTHD_OVERRIDE(void invoke(Event *event)) {
    if (function_.typeOf().as<std::string>() == "function") {
      function_(event);
    } else {
      EM_ASM(throw "callback is not a function");
    }
  }

private:
  emscripten::val function_; /*!< Функцию обработчика событий. */
};
#endif

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#define EVENT_HANDLER(classname, function) \
  (new core::foundation::TEventHandlerImpl<classname>(this, &classname::function))

#endif
