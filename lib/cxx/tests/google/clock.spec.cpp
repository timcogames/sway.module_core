#include <sway/core.hpp>

#include <gtest/gtest.h>

using namespace sway;

TEST(ClockTest, since) {
  const std::size_t NUM_ITERATIONS = 1000000;
  auto t = core::time::Clock::now();

  for (int i = 0; i < NUM_ITERATIONS; i++) {
    // TODO
  }

  auto d = core::time::Clock::since(t);
  printf("duration (us): %f\n", d.getRaw());
  printf("duration (ms): %f\n", d.asMillis());
}
