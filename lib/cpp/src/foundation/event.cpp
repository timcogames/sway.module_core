#include <sway/core/foundation/event.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_WEB_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

EMSCRIPTEN_BINDING_BEGIN(Event)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_WEB_BINDINGS)
emscripten::class_<Event>("Event")
    .allow_subclass<EventWrapper>("EventWrapper")
    .function("getSuperclass", &Event::getSuperclass, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
    .function("getClassname", &Event::getClassname, emscripten::pure_virtual())
    .function("id", &Event::id, emscripten::pure_virtual())
    .function("type", &Event::type, emscripten::pure_virtual())
    .function("data", &Event::data, emscripten::allow_raw_pointers(), emscripten::pure_virtual());
#endif
EMSCRIPTEN_BINDING_END()

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
