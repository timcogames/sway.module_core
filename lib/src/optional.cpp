#include <sway/optional.hpp>

NAMESPACE_BEGIN(sway)

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_PLATFORM_USE_BINDING)
template <typename T>
emscripten::class_<std::optional<T>> register_optional(lpcstr_t *name) {
  using OptionalType = std::optional<T>;

  return emscripten::class_<OptionalType>(name)
      .template constructor<>()
      .function("has_value", OptionalAccess<OptionalType>::has_value)
      .function("value", OptionalAccess<OptionalType>::value)
      .function("reset", OptionalAccess<OptionalType>::reset);
}
#endif

EMSCRIPTEN_BINDING_BEGIN(StringOptional)
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_PLATFORM_USE_BINDING)
emscripten::class_<StringOptional>("StringOptional").constructor<>().class_function("set", &StringOptional::set);
#endif
EMSCRIPTEN_BINDING_END()

NAMESPACE_END(sway)
