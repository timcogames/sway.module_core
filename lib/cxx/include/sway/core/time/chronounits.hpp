#ifndef SWAY_CORE_TIME_CHRONOUNITS_HPP
#define SWAY_CORE_TIME_CHRONOUNITS_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <map>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(time)

enum class ChronoUnit : u32_t { MILLIS, SECONDS, MINUTES, HOURS, Latest };

// clang-format off
static inline std::map<ChronoUnit, f64_t> CHRONO_UNIT_TABLE {{
  {ChronoUnit::MILLIS,  1e+3},
  {ChronoUnit::SECONDS, 1e+6},
  {ChronoUnit::MINUTES, 1e+6 * 60.0},
  {ChronoUnit::HOURS,   1e+6 * 60.0 * 60.0}
}};
// clang-format on

NAMESPACE_END(time)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_TIME_CHRONOUNITS_HPP
