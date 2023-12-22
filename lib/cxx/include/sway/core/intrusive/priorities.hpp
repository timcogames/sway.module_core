#ifndef SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
#define SWAY_CORE_INTRUSIVE_PRIORITIES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(intrusive)

// clang-format off
enum class Priority : u32_t {
  VERY_LOW = 0,
  LOW = 1,
  NORMAL = 2,
  HIGH = 3,
  VERY_HIGH = 4
};
// clang-format on

NAMESPACE_END(intrusive)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
