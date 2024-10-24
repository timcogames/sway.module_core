#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

template <>
inline void Uniqueable<std::string>::bindEmscriptenClass() {
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
  emscripten::class_<Uniqueable<std::string>>("Uniqueable")
      .constructor<const std::optional<std::string> &>()
      .function("getUid", &Uniqueable<std::string>::getUid)
      .function("setUid", &Uniqueable<std::string>::setUid);
#endif
}
