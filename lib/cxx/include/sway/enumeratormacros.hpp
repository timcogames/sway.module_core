#ifndef SWAY_ENUMERATORMACROS_HPP
#define SWAY_ENUMERATORMACROS_HPP

#include <sway/common/numeraltypes.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/defines.hpp>
#include <sway/inlinemacros.hpp>

#include <iterator>  // size

#define ENUM_BITMASK(x) (static_cast<sway::u32_t>(1) << (x))

#define DECLARE_ENUM_EXT(NAME, TYPE, INITIAL_VALUE, ...)                                                               \
  namespace NAME {                                                                                                     \
  enum class Enum : TYPE { NONE = INITIAL_VALUE, __VA_ARGS__, Latest };                                                \
                                                                                                                       \
  FORCE_INLINE constexpr auto Latest = sway::core::toBase(NAME::Enum::Latest);                                         \
  FORCE_INLINE constexpr auto None = sway::core::toBase(NAME::Enum::NONE);                                             \
                                                                                                                       \
  static_assert(static_cast<sway::i64_t>(Latest) >= static_cast<sway::i64_t>(None), #NAME ": Latest must be >= NONE"); \
                                                                                                                       \
  FORCE_INLINE constexpr std::size_t CountWithoutNone =                                                                \
      static_cast<std::size_t>(static_cast<sway::i64_t>(Latest) - static_cast<sway::i64_t>(None) - 1);                 \
                                                                                                                       \
  FORCE_INLINE constexpr std::size_t Count =                                                                           \
      static_cast<std::size_t>(static_cast<sway::i64_t>(Latest) - static_cast<sway::i64_t>(None));                     \
  }

#define DECLARE_ENUM(NAME, ...) DECLARE_ENUM_EXT(NAME, sway::u32_t, GLOB_IDX_INITIAL, __VA_ARGS__)
#define DECLARE_ENUM_IDX(NAME, ...) DECLARE_ENUM_EXT(NAME, sway::i32_t, GLOB_IDX_INVALID, __VA_ARGS__)

#endif  // SWAY_ENUMERATORMACROS_HPP
