#include <sway/core/time/timepoint.hpp>
#include <sway/inlinemacros.hpp>
#include <sway/namespacemacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(time)

FORCE_INLINE auto operator-(const TimePoint &lhs, const TimePoint &rhs) -> Duration { return {lhs.raw - rhs.raw}; }

FORCE_INLINE auto operator+(const TimePoint &lhs, const TimePoint &rhs) -> Duration { return {lhs.raw + rhs.raw}; }

FORCE_INLINE auto operator+(TimePoint lhs, const Duration &rhs) -> TimePoint {
  lhs += rhs;
  return lhs;
}

FORCE_INLINE auto operator+(const Duration &lhs, TimePoint rhs) -> TimePoint {
  rhs += lhs;
  return rhs;
}

FORCE_INLINE auto operator-(TimePoint lhs, const Duration &rhs) -> TimePoint {
  lhs -= rhs;
  return lhs;
}

FORCE_INLINE auto operator-(const Duration &lhs, TimePoint rhs) -> TimePoint {
  rhs -= lhs;
  return rhs;
}

NS_END()  // namespace time
NS_END()  // namespace core
NS_END()  // namespace sway
