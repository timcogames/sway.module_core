#include <sway/core.hpp>

#include <gtest/gtest.h>

using namespace sway;

TEST(Duration, DefaultConstructor) {
  core::time::Duration d0;

  EXPECT_DOUBLE_EQ(d0.asSeconds(), 0.0);
  EXPECT_DOUBLE_EQ(d0.asMillis(), 0.0);
}

TEST(Duration, ComponentConstructor) {
  core::time::Duration d0(1000);
  core::time::Duration d1(d0);

  EXPECT_DOUBLE_EQ(d1.asSeconds(), 0.001);
  EXPECT_DOUBLE_EQ(d1.asMillis(), 1.0);
}
