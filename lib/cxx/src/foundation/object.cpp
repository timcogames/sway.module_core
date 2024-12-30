#include <sway/core/foundation/object.hpp>

namespace sway::core {

EMSCRIPTEN_BINDING_BEGIN(Object)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<Object>("Object");
#endif
EMSCRIPTEN_BINDING_END()

}  // namespace sway::core
