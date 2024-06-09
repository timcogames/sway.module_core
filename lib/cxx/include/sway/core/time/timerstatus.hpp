#ifndef SWAY_CORE_TIME_TIMERSTATUS_HPP
#define SWAY_CORE_TIME_TIMERSTATUS_HPP

#include <sway/core/detail/enumutils.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <type_traits>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(time)

enum class TimerStatus : u32_t { STOPPED = 0, RUNNING, PAUSED, Latest };

struct TimerStatusUtil {
  template <typename INPUT_DATA_TYPE, typename = std::enable_if_t<std::is_same_v<INPUT_DATA_TYPE, u32_t>>>
  static auto as(INPUT_DATA_TYPE status) -> TimerStatus {
    return detail::toEnum<TimerStatus>(status);
  }

  template <typename INPUT_DATA_TYPE, typename = std::enable_if_t<std::is_same_v<INPUT_DATA_TYPE, TimerStatus>>>
  static auto as(INPUT_DATA_TYPE status) -> u32_t {
    return detail::toUnderlying<TimerStatus>(status);
  }

  static auto has(u32_t lhs, TimerStatus rhs) -> bool { return lhs == TimerStatusUtil::as(rhs); }

  static auto isRunning(u32_t status) -> bool { return TimerStatusUtil::has(status, TimerStatus::RUNNING); }

  static auto isPaused(u32_t status) -> bool { return TimerStatusUtil::has(status, TimerStatus::PAUSED); }

  static auto isStopped(u32_t status) -> bool { return TimerStatusUtil::has(status, TimerStatus::STOPPED); }
};

NAMESPACE_END(time)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_TIME_TIMERSTATUS_HPP
