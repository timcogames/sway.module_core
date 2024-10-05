#ifndef SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP
#define SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP

#include <sway/core/foundation/event.hpp>
#include <sway/core/foundation/eventhandler.hpp>
#include <sway/namespacemacros.hpp>

#include <algorithm>  // std::remove_if
#include <vector>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

template <class TYPE>
class TEventHandlerImpl : public EventHandler {
public:
  using HandlerFunction_t = void (TYPE::*)(Event::Ptr_t);

#pragma region "Ctors/Dtor"

  TEventHandlerImpl(TYPE *receiver, HandlerFunction_t func)
      : EventHandler(receiver)
      , function_(std::move(func)) {}

  virtual ~TEventHandlerImpl() = default;

#pragma endregion

#pragma region "Override EventHandler methods"

  MTHD_VIRTUAL_OVERRIDE(void invoke(Event::Ptr_t evt)) {
    auto *receiver = static_cast<TYPE *>(receiver_);
    (receiver->*function_)(evt);
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
        .constructor<Eventable::Ptr_t, emscripten::val>()
        .function("invoke", &EventHandlerImpl::invoke, emscripten::allow_raw_pointers());
#  endif
  }

  EventHandlerImpl(Eventable::Ptr_t receiver, emscripten::val func)
      : EventHandler(receiver)
      , function_(func) {}

  virtual ~EventHandlerImpl() = default;

  MTHD_VIRTUAL_OVERRIDE(void invoke(Event::Ptr_t evt)) {
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

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway

#define EVENT_HANDLER(CLASS_NAME, FUNC) \
  (new sway::core::foundation::TEventHandlerImpl<CLASS_NAME>(this, &CLASS_NAME::FUNC))

#endif  // SWAY_CORE_FOUNDATION_EVENTHANDLERIMPL_HPP
