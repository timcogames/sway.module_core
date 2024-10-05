#ifndef SWAY_CORE_TIME_CLOCK_HPP
#define SWAY_CORE_TIME_CLOCK_HPP

#include <sway/core/time/duration.hpp>
#include <sway/core/time/timepoint.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten.h>
#else
#  include <chrono>  // std::chrono
using namespace std::chrono;
#endif

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(time)

class Clock {
public:
  static auto now() -> TimePoint {
#ifdef EMSCRIPTEN_PLATFORM
    return TimePoint(static_cast<f64_t>(emscripten_get_now() * 1e+3));
#else
    auto now = high_resolution_clock::now();
    return TimePoint(static_cast<f64_t>(duration_cast<microseconds>(now.time_since_epoch()).count()));
#endif
  }

  static auto since(const TimePoint &pnt) -> Duration { return Clock::now().since(pnt); }
};

NS_END()  // namespace time
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_TIME_CLOCK_HPP
