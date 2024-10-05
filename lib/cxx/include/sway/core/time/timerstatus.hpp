#ifndef SWAY_CORE_TIME_TIMERSTATUS_HPP
#define SWAY_CORE_TIME_TIMERSTATUS_HPP

#include <sway/core/detail/enumutils.hpp>
#include <sway/enumeratormacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <type_traits>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(time)

DECLARE_ENUM(TimerStatus, STOPPED, RUNNING, PAUSED)

struct TimerStatusUtil {
  template <typename INPUT_DATA_TYPE, typename = detail::EnableIf_t<std::is_same_v<INPUT_DATA_TYPE, u32_t>>>
  static auto as(INPUT_DATA_TYPE status) -> TimerStatus::Enum {
    return detail::toEnum<TimerStatus::Enum>(status);
  }

  template <typename INPUT_DATA_TYPE, typename = detail::EnableIf_t<std::is_same_v<INPUT_DATA_TYPE, TimerStatus::Enum>>>
  static auto as(INPUT_DATA_TYPE status) -> u32_t {
    return detail::toBase<TimerStatus::Enum>(status);
  }

  static auto has(u32_t lhs, TimerStatus::Enum rhs) -> bool { return lhs == TimerStatusUtil::as(rhs); }

  static auto isRunning(u32_t status) -> bool { return TimerStatusUtil::has(status, TimerStatus::Enum::RUNNING); }

  static auto isPaused(u32_t status) -> bool { return TimerStatusUtil::has(status, TimerStatus::Enum::PAUSED); }

  static auto isStopped(u32_t status) -> bool { return TimerStatusUtil::has(status, TimerStatus::Enum::STOPPED); }
};

NS_END()  // namespace time
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_TIME_TIMERSTATUS_HPP
