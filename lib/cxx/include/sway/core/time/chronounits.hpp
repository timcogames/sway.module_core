#ifndef SWAY_CORE_TIME_CHRONOUNITS_HPP
#define SWAY_CORE_TIME_CHRONOUNITS_HPP

#include <sway/_stdafx.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/types.hpp>

namespace sway::core {

enum class ChronoUnit : u32_t { MILLIS, SECONDS, MINUTES, HOURS, Latest };

// clang-format off
static FORCE_INLINE std::map<ChronoUnit, f64_t> CHRONO_UNIT_TABLE {{
  {ChronoUnit::MILLIS,  1e+3},
  {ChronoUnit::SECONDS, 1e+6},
  {ChronoUnit::MINUTES, 1e+6 * 60.0},
  {ChronoUnit::HOURS,   1e+6 * 60.0 * 60.0}
}};
// clang-format on

}  // namespace sway::core

#endif  // SWAY_CORE_TIME_CHRONOUNITS_HPP
