#include <sway/core/time/clock.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

TEST(ClockTest, since) {
  const std::size_t NUM_ITERATIONS = 1000000;
  auto now = Clock::now();

  for (auto i = 0; i < NUM_ITERATIONS; i++) {
    // TODO
  }

  auto dur = Clock::since(now);
  printf("duration (us): %f\n", dur.getRaw());
  printf("duration (ms): %f\n", dur.asMillis());
}
