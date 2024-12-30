#ifndef SWAY_CORE_TIME_CLOCK_HPP
#define SWAY_CORE_TIME_CLOCK_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/time/duration.hpp>
#include <sway/core/time/timepoint.hpp>
#include <sway/types.hpp>

#ifdef EMSCRIPTEN_PLATFORM
#  include <emscripten.h>
#else
#  include <chrono>  // std::chrono
using namespace std::chrono;
#endif

namespace sway::core {

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

}  // namespace sway::core

#endif  // SWAY_CORE_TIME_CLOCK_HPP
