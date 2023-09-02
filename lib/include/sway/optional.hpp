#ifndef SWAY_OPTIONAL_HPP
#define SWAY_OPTIONAL_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <optional>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#  ifdef EMSCRIPTEN_PLATFORM_USE_BINDING
#    include <emscripten/bind.h>
#  endif
#endif

NAMESPACE_BEGIN(sway)

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_PLATFORM_USE_BINDING)

template <typename T>
struct OptionalAccess {
  static auto value(const T &op) -> emscripten::val { return emscripten::val(op.value()); }
  static auto has_value(T &op) -> bool { return op.has_value(); }
  static void reset(T &op) { op.reset(); }
};

class StringOptional {
public:
  DECLARE_EMSCRIPTEN_BINDING()

  static auto set(std::string val) -> std::optional<std::string> {
    if (val.empty()) {
      return std::nullopt;
    } else {
      return val;
    }
  }
};

template <typename T>
emscripten::class_<std::optional<T>> register_optional(lpcstr_t name) {
  using OptionalType = std::optional<T>;

  return emscripten::class_<OptionalType>(name)
      .template constructor<>()
      .function("has_value", OptionalAccess<OptionalType>::has_value)
      .function("value", OptionalAccess<OptionalType>::value)
      .function("reset", OptionalAccess<OptionalType>::reset);
}

#endif

NAMESPACE_END(sway)

#endif  // SWAY_OPTIONAL_HPP
