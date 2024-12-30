#ifndef SWAY_CORE_TIME_TIMERUTIL_HPP
#define SWAY_CORE_TIME_TIMERUTIL_HPP

#include <sway/_stdafx.hpp>
#include <sway/core/misc/format.hpp>
#include <sway/types.hpp>

namespace sway::core {

struct TimerUtil {
  static auto toStr(f64_t ticks) -> std::string {
    ticks /= 1000;
    u32_t seconds = (u32_t)ticks % 60;
    ticks /= 60;
    u32_t minutes = (u32_t)ticks % 60;
    ticks /= 60;
    u32_t hours = ticks;

    // return format("%d:%02d:%02d", hours, minutes, seconds);
    return format("%02d:%02d", minutes, seconds);
  }
};

}  // namespace sway::core

#endif  // SWAY_CORE_TIME_TIMERUTIL_HPP
