#ifndef SWAY_OPTIONAL_HPP
#define SWAY_OPTIONAL_HPP

#include <sway/namespacemacros.hpp>

#include <optional>

#ifdef _EMSCRIPTEN
#  include <emscripten/bind.h>
#  include <emscripten/emscripten.h>
#  include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)

#ifdef _EMSCRIPTEN
template <typename T>
struct OptionalAccess {
  static emscripten::val value(const T &op) { return emscripten::val(op.value()); }
  static bool has_value(T &op) { return op.has_value(); }
  static void reset(T &op) { op.reset(); }
};

template <typename T>
emscripten::class_<std::optional<T>> register_optional(const char *name) {
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
