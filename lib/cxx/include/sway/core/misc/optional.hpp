#ifndef SWAY_CORE_MISC_OPTIONAL_HPP
#define SWAY_CORE_MISC_OPTIONAL_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <optional>
#include <string>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_USE_BINDINGS
#    include <emscripten/bind.h>
#  endif
#endif

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(misc)

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)

template <typename T>
struct OptionalAccess {
  static auto value(const T &opt) -> emscripten::val { return emscripten::val(opt.value()); }
  static auto has_value(T &opt) -> bool { return opt.has_value(); }
  static void reset(T &opt) { opt.reset(); }
};

template <typename T>
auto register_optional(lpcstr_t name) -> emscripten::class_<std::optional<T>> {
  using OptionalType = std::optional<T>;

  return emscripten::class_<OptionalType>(name)
      .template constructor<>()
      .function("has_value", OptionalAccess<OptionalType>::has_value)
      .function("value", OptionalAccess<OptionalType>::value)
      .function("reset", OptionalAccess<OptionalType>::reset);
}

#endif  // EMSCRIPTEN_PLATFORM && EMSCRIPTEN_USE_BINDINGS

class StringOptional {
public:
  // DECLARE_EMSCRIPTEN_BINDING()

  static void bindEmscriptenClass() {
#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)
    emscripten::class_<StringOptional>("StringOptional").constructor<>().class_function("set", &StringOptional::set);
#endif
  }

  static auto set(const std::string &val) -> std::optional<std::string> {
    if (val.empty()) {
      return std::nullopt;
    }

    return val;
  }
};

NS_END()  // namespace misc
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_MISC_OPTIONAL_HPP
