#ifndef SWAY_ENUMERATORMACROS_HPP
#define SWAY_ENUMERATORMACROS_HPP

#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)

#define ENUM_MAX_ELEMENTS(NAME) core::detail::toBase(NAME::Enum::Latest)

// clang-format off
#define ENUM_BEGIN(NAME, TYPE) \
  namespace NAME {             \
    enum class Enum : TYPE {

#define ENUM_END()             \
    };                         \
  }
// clang-format on

NAMESPACE_END(sway)

#endif  // SWAY_ENUMERATORMACROS_HPP
