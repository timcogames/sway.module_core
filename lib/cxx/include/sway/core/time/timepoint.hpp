#ifndef SWAY_CORE_TIME_TIMEPOINT_HPP
#define SWAY_CORE_TIME_TIMEPOINT_HPP

#include <sway/core/time/duration.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(time)

struct TimePoint {
  f64_t raw;

  TimePoint()
      : raw(0) {}

  TimePoint(f64_t val)
      : raw(val) {}

  [[nodiscard]]
  auto since(const TimePoint &rhs) const -> Duration {
    return {raw - rhs.raw};
  }

  void operator+=(const Duration &rhs) { raw += rhs.asMillis(); }

  void operator-=(const Duration &rhs) { raw -= rhs.asMillis(); }
};

NAMESPACE_END(time)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_TIME_TIMEPOINT_HPP
