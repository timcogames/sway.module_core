#include <sway/core/foundation/context.hpp>

namespace sway::core {

EMSCRIPTEN_BINDING_BEGIN(Context)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<Context>("Context").constructor<>();
#endif
EMSCRIPTEN_BINDING_END()

}  // namespace sway::core
