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
        .function("getUid", &Object::getUid)
        .function("setUid", &Object::setUid);
#endif
}

Object::Object(Context *context)
    : context_(context)
    , uniqueid_(misc::randomUid<UUID_NBR_OF_GROUPS>(UUID_MAGIC)) {}

void Object::setUid(const std::string &id) { uniqueid_ = id; }

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
