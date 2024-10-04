#ifndef SWAY_ENUMERATORMACROS_HPP
#define SWAY_ENUMERATORMACROS_HPP

#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)

// clang-format off
#define ENUM_BEGIN(NAME, TYPE, INITIAL_VALUE) \
  namespace NAME {                            \
    enum class Enum : TYPE {                  \
      NONE = INITIAL_VALUE,

#define ENUM_DEF_BEGIN(NAME) ENUM_BEGIN(NAME, u32_t, 0)
#define ENUM_IDX_BEGIN(NAME) ENUM_BEGIN(NAME, i32_t, GLOB_IDX_INVALID)

#define ENUM_END()             \
      , Latest                 \
    };                         \
  }
// clang-format on

#define ENUM_MAX_ELEMENTS(NAME) core::detail::toBase(NAME::Enum::Latest)

NAMESPACE_END(sway)

#endif  // SWAY_ENUMERATORMACROS_HPP
