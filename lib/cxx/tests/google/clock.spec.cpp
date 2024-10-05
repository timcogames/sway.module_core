#include <sway/core/time/clock.hpp>
#include <sway/namespacemacros.hpp>

#include <gtest/gtest.h>

#include <cstdio>

NS_ALIAS(tm_, core::time)

TEST(ClockTest, since) {
  const std::size_t NUM_ITERATIONS = 1000000;
  auto now = tm_::Clock::now();

  for (auto i = 0; i < NUM_ITERATIONS; i++) {
    // TODO
  }

  auto dur = tm_::Clock::since(now);
  printf("duration (us): %f\n", dur.getRaw());
  printf("duration (ms): %f\n", dur.asMillis());
}
