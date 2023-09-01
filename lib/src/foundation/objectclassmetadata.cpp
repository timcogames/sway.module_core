#include <sway/core/foundation/objectclassmetadata.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(foundation)

EMSCRIPTEN_BINDING_BEGIN(ObjectClassMetadata)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_PLATFORM_USE_BINDING)
emscripten::class_<ObjectClassMetadata>("ObjectClassMetadata")
    .constructor<lpcstr_t, const ObjectClassMetadata *>()
    .function("getSuperclass", &ObjectClassMetadata::getSuperclass, emscripten::allow_raw_pointers())
    .function("getClassname", &ObjectClassMetadata::getClassname);
#endif
EMSCRIPTEN_BINDING_END()

NAMESPACE_END(foundation)
NAMESPACE_END(core)
NAMESPACE_END(sway)
