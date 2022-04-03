#include <sway/core/foundation/context.hpp>

#ifdef _EMSCRIPTEN
#  include <emscripten/bind.h>
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

void Context::registerEmsClass() {
#ifdef _EMSCRIPTEN
  emscripten::class_<Context>("Context").constructor<>();
#endif
}

Context::Context() {}

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
