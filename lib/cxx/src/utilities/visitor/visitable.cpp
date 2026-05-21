#include <sway/core/utilities/visitor/visitable.hpp>

namespace sway::core {

EMSCRIPTEN_BINDING_BEGIN(Visitable)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<Visitable>("Visitable")
    .smart_ptr<std::shared_ptr<Visitable>>("VisitableSmartPtr")
    .function("traverse", emscripten::select_overload<u32_t(typedefs::TraverserSharedPtr_t)>(&Visitable::traverse),
        emscripten::allow_raw_pointer<emscripten::arg<0>>());
#endif
EMSCRIPTEN_BINDING_END()

}  // namespace sway::core
