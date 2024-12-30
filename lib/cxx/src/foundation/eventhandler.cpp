#include <sway/core/foundation/eventable.hpp>
#include <sway/core/foundation/eventhandler.hpp>

namespace sway::core {

EMSCRIPTEN_BINDING_BEGIN(EventHandler)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<EventHandler>("EventHandler")
    .allow_subclass<EventHandlerWrapper>("EventHandlerWrapper", emscripten::constructor<EventablePtr_t>())
    .function("invoke", &EventHandler::invoke, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
    .function("getSender", &EventHandler::getSender, emscripten::allow_raw_pointers())
    .function("setSender", &EventHandler::setSender, emscripten::allow_raw_pointers())
    .function("getReceiver", &EventHandler::getReceiver, emscripten::allow_raw_pointers());
#endif
EMSCRIPTEN_BINDING_END()

EventHandler::EventHandler(EventableTypedefs::Ptr_t receiver)
    : receiver_(receiver) {}

auto EventHandler::getSender() const -> EventableTypedefs::Ptr_t { return sender_; }

void EventHandler::setSender(EventableTypedefs::Ptr_t sender) { sender_ = sender; }

auto EventHandler::getReceiver() const -> EventableTypedefs::Ptr_t { return receiver_; }

}  // namespace sway::core
