#include <sway/core/time/duration.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

TEST(Duration, ctor_def) {
  const Duration dur0;

  EXPECT_DOUBLE_EQ(dur0.asSeconds(), 0.0);
  EXPECT_DOUBLE_EQ(dur0.asMillis(), 0.0);
}

TEST(Duration, ctor_comps) {
  const Duration dur0(1000);
  const Duration dur1(dur0);

  EXPECT_DOUBLE_EQ(dur1.asSeconds(), 0.001);
  EXPECT_DOUBLE_EQ(dur1.asMillis(), 1.0);
}
