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

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(time)

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

NAMESPACE_END(time)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_TIME_CLOCK_HPP
