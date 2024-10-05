#ifndef SWAY_CORE_TIME_TIMER_HPP
#define SWAY_CORE_TIME_TIMER_HPP

#include <sway/core/time/clock.hpp>
#include <sway/core/time/timerstatus.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(time)

class Timer {
public:
  Timer()
      : status_(0) {}

  ~Timer() = default;

  void start() {
    started_ = Clock::now();
    paused_ = {0};
    status_ = TimerStatusUtil::as(TimerStatus::Enum::RUNNING);
  }

  void pause() {
    if (!TimerStatusUtil::isRunning(status_) || TimerStatusUtil::isPaused(status_)) {
      return;
    }

    paused_ = Clock::now();
    status_ = TimerStatusUtil::as(TimerStatus::Enum::PAUSED);
  }

  void resume() {
    if (!TimerStatusUtil::isPaused(status_)) {
      return;
    }

    started_ = started_ + Clock::since(paused_);
    status_ = TimerStatusUtil::as(TimerStatus::Enum::RUNNING);
  }

  void stop() {
    if (!TimerStatusUtil::isRunning(status_)) {
      return;
    }

    status_ = TimerStatusUtil::as(TimerStatus::Enum::STOPPED);
  }

  [[nodiscard]]
  auto getElapsed() -> Duration {
    if (TimerStatusUtil::isStopped(status_)) {
      return {0};
    }

    if (TimerStatusUtil::isPaused(status_)) {
      return paused_ - started_;
    }

    return Clock::since(started_);
  }

  [[nodiscard]]
  auto getStatus() const -> u32_t {
    return status_;
  }

private:
  TimePoint started_;
  TimePoint paused_;
  u32_t status_;
};

NS_END()  // namespace time
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_TIME_TIMER_HPP
