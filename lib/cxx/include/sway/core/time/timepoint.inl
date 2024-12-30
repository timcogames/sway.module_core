#include <sway/inlinemacros.hpp>

namespace sway::core {

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

}  // namespace sway::core
