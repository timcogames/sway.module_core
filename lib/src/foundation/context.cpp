#include <sway/core/foundation/context.hpp>

#ifdef _EMSCRIPTEN
#  include <emscripten/bind.h>
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

EMSCRIPTEN_BINDING_BEGIN(Context)
#ifdef _EMSCRIPTEN
emscripten::class_<Context>("Context").constructor<>();
#endif
EMSCRIPTEN_BINDING_END()

Context::Context() {}

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
