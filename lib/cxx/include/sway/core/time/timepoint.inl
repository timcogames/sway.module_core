#include <sway/core/time/timepoint.hpp>
#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(time)

inline auto operator-(const TimePoint &lhs, const TimePoint &rhs) -> Duration { return {lhs.raw - rhs.raw}; }

inline auto operator+(const TimePoint &lhs, const TimePoint &rhs) -> Duration { return {lhs.raw + rhs.raw}; }

inline auto operator+(TimePoint lhs, const Duration &rhs) -> TimePoint {
  lhs += rhs;
  return lhs;
}

inline auto operator+(const Duration &lhs, TimePoint rhs) -> TimePoint {
  rhs += lhs;
  return rhs;
}

inline auto operator-(TimePoint lhs, const Duration &rhs) -> TimePoint {
  lhs -= rhs;
  return lhs;
}

inline auto operator-(const Duration &lhs, TimePoint rhs) -> TimePoint {
  rhs -= lhs;
  return rhs;
}

NAMESPACE_END(time)
NAMESPACE_END(core)
NAMESPACE_END(sway)
