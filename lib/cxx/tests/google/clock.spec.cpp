#include <sway/core/time/clock.hpp>
#include <sway/namespacemacros.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()

TEST(ClockTest, since) {
  const std::size_t NUM_ITERATIONS = 1000000;
  auto now = core::Clock::now();

  for (auto i = 0; i < NUM_ITERATIONS; i++) {
    // TODO
  }

  auto dur = core::Clock::since(now);
  printf("duration (us): %f\n", dur.getRaw());
  printf("duration (ms): %f\n", dur.asMillis());
}
