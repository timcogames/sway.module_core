#include <sway/core/foundation/context.hpp>
#include <sway/core/foundation/object.hpp>
#include <sway/core/misc/guid.hpp>

#ifdef _EMSCRIPTEN
#    include <emscripten/bind.h>
#    include <emscripten/emscripten.h>
#    include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

void Object::registerEmsClass() {
#ifdef _EMSCRIPTEN
    emscripten::class_<Object>("Object")
        .constructor<Context *>()
        .function("subscribe", &Object::subscribe, emscripten::allow_raw_pointers())
        .function("unsubscribe", &Object::unsubscribe)
        .function("emit", &Object::emit, emscripten::allow_raw_pointers())
        .function("findEventHandler", &Object::findEventHandler, emscripten::allow_raw_pointers())
        .function("getUid", &Object::getUid)
        .function("setUid", &Object::setUid);
#endif
}

Object::Object(Context *context)
    : context_(context)
    , uniqueid_(misc::randomUid<UUID_NBR_OF_GROUPS>(UUID_MAGIC)) {}

void Object::subscribe(Object *sender, const std::string &eventname, AEventHandler *handler) {
    handler->setSender(sender);
    handler->setEventName(eventname);
    eventHandlers_.push_back(handler);
}

void Object::unsubscribe(const std::string &eventname) {
    eventHandlers_.erase(
        std::remove_if(eventHandlers_.begin(), eventHandlers_.end(),
            [eventname](AEventHandler *handler) { return handler->getEventName().compare(eventname); }),
        eventHandlers_.end());
}

void Object::emit(const std::string &eventname, EventBase *event) {
    for (AEventHandler *handler : eventHandlers_) {
        if (handler->getEventName().compare(eventname) == 0 && handler->getSender()->getUid().compare(getUid()) == 0) {
            handler->invoke(event);
        }
    }
}

AEventHandler *Object::findEventHandler(const std::string &eventname) {
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

void Object::setUid(const std::string &id) { uniqueid_ = id; }

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
