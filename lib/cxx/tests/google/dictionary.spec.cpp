#include <sway/core/misc/dictionary.hpp>
#include <sway/namespacemacros.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

TEST(Dictionary, add_string) {
  Dictionary dict;

  dict.addString("key", "value");
  EXPECT_EQ(dict.getString("key"), "value");
}
