#ifndef SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
#define SWAY_CORE_INTRUSIVE_PRIORITIES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(intrusive)

enum class Priority : u32_t { VERY_LOW = 0, LOW, NORMAL, HIGH, VERY_HIGH };

NAMESPACE_END(intrusive)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_INTRUSIVE_PRIORITIES_HPP
