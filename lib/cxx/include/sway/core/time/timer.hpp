#ifndef SWAY_CORE_TIME_TIMER_HPP
#define SWAY_CORE_TIME_TIMER_HPP

#include <sway/core/time/clock.hpp>
#include <sway/core/time/timerstatus.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(time)

class Timer {
public:
  Timer()
      : status_(0) {}

  ~Timer() = default;

  void start() {
    started_ = Clock::now();
    paused_ = {0};
    status_ = TimerStatusUtil::as(TimerStatus::RUNNING);
  }

  void pause() {
    if (!TimerStatusUtil::isRunning(status_) || TimerStatusUtil::isPaused(status_)) {
      return;
    }

    paused_ = Clock::now();
    status_ = TimerStatusUtil::as(TimerStatus::PAUSED);
  }

  void resume() {
    if (!TimerStatusUtil::isPaused(status_)) {
      return;
    }

    started_ = started_ + Clock::since(paused_);
    status_ = TimerStatusUtil::as(TimerStatus::RUNNING);
  }

  void stop() {
    if (!TimerStatusUtil::isRunning(status_)) {
      return;
    }

    status_ = TimerStatusUtil::as(TimerStatus::STOPPED);
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

NAMESPACE_END(time)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_TIME_TIMER_HPP