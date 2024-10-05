#include <sway/core/foundation/object.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

EMSCRIPTEN_BINDING_BEGIN(Object)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<Object>("Object");
#endif
EMSCRIPTEN_BINDING_END()

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway
