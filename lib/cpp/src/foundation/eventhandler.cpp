#include <sway/core/foundation/eventable.hpp>
#include <sway/core/foundation/eventhandler.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

EMSCRIPTEN_BINDING_BEGIN(AEventHandler)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<AEventHandler>("AEventHandler")
    .allow_subclass<AEventHandlerWrapper>("AEventHandlerWrapper", emscripten::constructor<Eventable *>())
    .function("invoke", &AEventHandler::invoke, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
    .function("getSender", &AEventHandler::getSender, emscripten::allow_raw_pointers())
    .function("setSender", &AEventHandler::setSender, emscripten::allow_raw_pointers())
    .function("getReceiver", &AEventHandler::getReceiver, emscripten::allow_raw_pointers());
#endif
EMSCRIPTEN_BINDING_END()

AEventHandler::AEventHandler(Eventable *receiver)
    : receiver_(receiver) {}

auto AEventHandler::getSender() const -> Eventable * { return sender_; }

void AEventHandler::setSender(Eventable *sender) { sender_ = sender; }

auto AEventHandler::getReceiver() const -> Eventable * { return receiver_; }

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
