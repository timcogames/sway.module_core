#include <sway/core/time/timepoint.hpp>
#include <sway/namespacemacros.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(time)

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

NS_END()  // namespace time
NS_END()  // namespace core
NS_END()  // namespace sway
