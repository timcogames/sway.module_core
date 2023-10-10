#include <sway/core/foundation/uniqueable.hpp>

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

template <>
EMSCRIPTEN_BINDING_BEGIN(Uniqueable<std::string>)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_WEB_BINDINGS)
emscripten::class_<Uniqueable<std::string>>("Uniqueable")
    .constructor<const std::optional<std::string> &>()
    .function("getUid", &Uniqueable<std::string>::getUid)
    .function("setUid", &Uniqueable<std::string>::setUid);
#endif
EMSCRIPTEN_BINDING_END()

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
