#include <sway/core/utilities/visitor/traverser.hpp>

namespace sway::core {

EMSCRIPTEN_BINDING_BEGIN(Traverser)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<Traverser>("Traverser")
    .smart_ptr<std::shared_ptr<Traverser>>("TraverserSmartPtr")
    .function("visit", emscripten::select_overload<u32_t(typedefs::VisitablePtr_t)>(&Traverser::visit),
        emscripten::allow_raw_pointer<emscripten::arg<0>>());
#endif
EMSCRIPTEN_BINDING_END()

}  // namespace sway::core
