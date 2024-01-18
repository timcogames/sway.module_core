#include <sway/core/foundation/eventable.hpp>
#include <sway/core/foundation/eventhandler.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

EMSCRIPTEN_BINDING_BEGIN(EventHandler)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<EventHandler>("EventHandler")
    .allow_subclass<EventHandlerWrapper>("EventHandlerWrapper", emscripten::constructor<Eventable *>())
    .function("invoke", &EventHandler::invoke, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
    .function("getSender", &EventHandler::getSender, emscripten::allow_raw_pointers())
    .function("setSender", &EventHandler::setSender, emscripten::allow_raw_pointers())
    .function("getReceiver", &EventHandler::getReceiver, emscripten::allow_raw_pointers());
#endif
EMSCRIPTEN_BINDING_END()

EventHandler::EventHandler(Eventable *receiver)
    : receiver_(receiver) {}

auto EventHandler::getSender() const -> Eventable * { return sender_; }

void EventHandler::setSender(Eventable *sender) { sender_ = sender; }

auto EventHandler::getReceiver() const -> Eventable * { return receiver_; }

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
