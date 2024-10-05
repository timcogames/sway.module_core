#ifndef SWAY_CORE_TIME_TIMERUTIL_HPP
#define SWAY_CORE_TIME_TIMERUTIL_HPP

#include <sway/core/misc/format.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(time)

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

NS_END()  // namespace time
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_TIME_TIMERUTIL_HPP
