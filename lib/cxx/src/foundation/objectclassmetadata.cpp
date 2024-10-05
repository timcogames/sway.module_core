#include <sway/core/foundation/objectclassmetadata.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(foundation)

EMSCRIPTEN_BINDING_BEGIN(ObjectClassMetadata)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
emscripten::class_<ObjectClassMetadata>("ObjectClassMetadata")
    .constructor<lpcstr_t, const ObjectClassMetadata *>()
    .function("getSuperclass", &ObjectClassMetadata::getSuperclass, emscripten::allow_raw_pointers())
    .function("getClassname", &ObjectClassMetadata::getClassname);
#endif
EMSCRIPTEN_BINDING_END()

NS_END()  // namespace foundation
NS_END()  // namespace core
NS_END()  // namespace sway
