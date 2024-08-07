#ifndef SWAY_CORE_TIME_TIMERUTIL_HPP
#define SWAY_CORE_TIME_TIMERUTIL_HPP

#include <sway/core/misc/format.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(time)

struct TimerUtil {
  static auto toStr(f64_t ticks) -> std::string {
    ticks /= 1000;
    u32_t seconds = (u32_t)ticks % 60;
    ticks /= 60;
    u32_t minutes = (u32_t)ticks % 60;
    ticks /= 60;
    u32_t hours = ticks;

    // return misc::format("%d:%02d:%02d", hours, minutes, seconds);
    return misc::format("%02d:%02d", minutes, seconds);
  }
};

NAMESPACE_END(time)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_TIME_TIMERUTIL_HPP
