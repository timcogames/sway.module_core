#ifndef SWAY_ENUMERATORMACROS_HPP
#define SWAY_ENUMERATORMACROS_HPP

#include <sway/core/detail/enumutils.hpp>
#include <sway/defines.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/numeraltypes.hpp>

#include <iterator>  // size

#define ENUM_BITMASK(x) (1 << (x))

// clang-format off
#define DECLARE_ENUM_EXT(NAME, TYPE, INITIAL_VALUE, ...)                                        \
  namespace NAME {                                                                              \
    enum class Enum : TYPE { NONE = INITIAL_VALUE, __VA_ARGS__, Latest };                       \
  }                                                                                             \
                                                                                                \
  static FORCE_INLINE auto NAME##CountWithoutNone = []() -> const size_t {                      \
    static TYPE __VA_ARGS__; return std::size({__VA_ARGS__});                                   \
  }();                                                                                          \
                                                                                                \
  static FORCE_INLINE auto NAME##Count = []() -> const size_t {                                 \
    static TYPE __VA_ARGS__; return std::size({__VA_ARGS__}) + 1;                               \
  }();                                                                                          \
                                                                                                \
  static constexpr sway::u32_t NAME##Latest = sway::core::detail::toBase(NAME::Enum::Latest);
// clang-format on

#define DECLARE_ENUM(NAME, ...) DECLARE_ENUM_EXT(NAME, sway::u32_t, GLOB_IDX_INITIAL, __VA_ARGS__)
#define DECLARE_ENUM_IDX(NAME, ...) DECLARE_ENUM_EXT(NAME, sway::i32_t, GLOB_IDX_INVALID, __VA_ARGS__)

#endif  // SWAY_ENUMERATORMACROS_HPP
