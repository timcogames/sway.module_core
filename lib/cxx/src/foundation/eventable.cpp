#include <sway/core/foundation/eventable.hpp>
#include <sway/core/misc/guid.hpp>

namespace sway::core {

EMSCRIPTEN_BINDING_BEGIN(Eventable)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<Eventable>("Eventable")
    .constructor<>()
    .function("subscribe", &Eventable::subscribe, emscripten::allow_raw_pointers())
    .function("unsubscribe", &Eventable::unsubscribe)
    .function("emit", &Eventable::emit, emscripten::allow_raw_pointers())
    .function("findEventHandler", &Eventable::findEventHandler, emscripten::allow_raw_pointers());
#endif
EMSCRIPTEN_BINDING_END()

void Eventable::subscribe(
    EventableTypedefs::Ptr_t sender, const std::string &eventname, EventHandlerTypedefs::Ptr_t handler) {
  handler->setSender(sender);
  handler->setEventName(eventname);
  eventHandlers_.push_back(handler);
}

void Eventable::unsubscribe(const std::string &eventname) {
  // clang-format off
  eventHandlers_.erase(std::remove_if(eventHandlers_.begin(), eventHandlers_.end(), [eventname](EventHandlerTypedefs::Ptr_t handler) {
    return handler->getEventName().compare(eventname);
  }), eventHandlers_.end());  // clang-format on
}

void Eventable::emit(const std::string &eventname, EventTypedefs::UniquePtr_t &&evt, EmitPredicate_t predicate) {
  for (auto *handler : eventHandlers_) {
    if (handler->getEventName().compare(eventname) == 0 && predicate(handler)) {
      handler->invoke(std::forward<EventTypedefs::UniquePtr_t>(evt));
    }
  }
}

auto Eventable::findEventHandler(const std::string &eventname) -> EventHandlerTypedefs::Ptr_t {
  auto found = false;
  auto iter = eventHandlers_.begin();
  while (iter != eventHandlers_.end()) {
    if ((*iter)->getEventName().compare(eventname) == 0) {
      found = true;
      break;
    }

    iter++;
  }

  if (found) {
    return *iter;
  }

  return nullptr;
}

}  // namespace sway::core
