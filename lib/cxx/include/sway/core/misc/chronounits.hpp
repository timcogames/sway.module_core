#ifndef SWAY_CORE_MISC_CHRONOUNITS_HPP
#define SWAY_CORE_MISC_CHRONOUNITS_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <map>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(misc)

enum class ChronoUnit : u32_t { MILLIS, SECONDS, MINUTES, HOURS };

// clang-format off
static inline std::map<ChronoUnit, f64_t> CHRONO_UNIT_TABLE {{
  {ChronoUnit::MILLIS,  1.0},
  {ChronoUnit::SECONDS, 1000.0},
  {ChronoUnit::MINUTES, 1000.0 * 60.0},
  {ChronoUnit::HOURS,   1000.0 * 60.0 * 60.0}
}};
// clang-format on

NAMESPACE_END(misc)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_MISC_CHRONOUNITS_HPP
