#include <sway/inlinemacros.hpp>

template <>
FORCE_INLINE void Uniqueable<std::string>::bindEmscriptenClass() {
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
  emscripten::class_<Uniqueable<std::string>>("Uniqueable")
      .constructor<const std::optional<std::string> &>()
      .function("getUniqueId", &Uniqueable<std::string>::getUniqueId)
      .function("setUniqueId", &Uniqueable<std::string>::setUniqueId);
#endif
}
