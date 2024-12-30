#ifndef SWAY_CORE_TIME_TIMEPOINT_HPP
#define SWAY_CORE_TIME_TIMEPOINT_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/time/duration.hpp>
#include <sway/types.hpp>

namespace sway::core {

struct TimePoint {
  f64_t raw;

  TimePoint()
      : raw(0) {}

  TimePoint(f64_t val)
      : raw(val) {}

  [[nodiscard]] auto since(const TimePoint &rhs) const -> Duration { return {raw - rhs.raw}; }

  void operator+=(const Duration &rhs) { raw += rhs.getRaw(); }

  void operator-=(const Duration &rhs) { raw -= rhs.getRaw(); }
};

}  // namespace sway::core

#include <sway/core/time/timepoint.inl>

#endif  // SWAY_CORE_TIME_TIMEPOINT_HPP
