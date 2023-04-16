#include <sway/core/foundation/context.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_PLATFORM_USE_BINDING
#    include <emscripten/bind.h>
#  endif
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

EMSCRIPTEN_BINDING_BEGIN(Context)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDING)
emscripten::class_<Context>("Context").constructor<>();
#endif
EMSCRIPTEN_BINDING_END()

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
