#include <sway/core/misc/dictionary.hpp>
#include <sway/namespacemacros.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()

TEST(Dictionary, add_string) {
  core::misc::Dictionary dict;

  dict.addString("key", "value");
  EXPECT_EQ(dict.getString("key"), "value");
}
