#include <sway/core/foundation/eventable.hpp>
#include <sway/core/misc/guid.hpp>

#ifdef _EMSCRIPTEN
#    include <emscripten/bind.h>
#    include <emscripten/emscripten.h>
#    include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

void Eventable::registerEmsClass() {
#ifdef _EMSCRIPTEN
    emscripten::class_<Eventable>("Eventable")
        .constructor<>()
        .function("subscribe", &Eventable::subscribe, emscripten::allow_raw_pointers())
        .function("unsubscribe", &Eventable::unsubscribe)
        .function("emit", &Eventable::emit, emscripten::allow_raw_pointers())
        .function("findEventHandler", &Eventable::findEventHandler, emscripten::allow_raw_pointers());
#endif
}

void Eventable::subscribe(Eventable *sender, const std::string &eventname, AEventHandler *handler) {
    handler->setSender(sender);
    handler->setEventName(eventname);
    eventHandlers_.push_back(handler);
}

void Eventable::unsubscribe(const std::string &eventname) {
    eventHandlers_.erase(
        std::remove_if(eventHandlers_.begin(), eventHandlers_.end(),
            [eventname](AEventHandler *handler) { return handler->getEventName().compare(eventname); }),
        eventHandlers_.end());
}

void Eventable::emit(const std::string &eventname, EventBase *event, EmitPredicate_t predicate) {
    for (AEventHandler *handler : eventHandlers_) {
        if (handler->getEventName().compare(eventname) == 0 && predicate(handler)) {
            handler->invoke(event);
        }
    }
}

AEventHandler *Eventable::findEventHandler(const std::string &eventname) {
    bool found = false;
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

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
