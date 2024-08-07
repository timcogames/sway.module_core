#include <sway/core.hpp>

#include <gtest/gtest.h>

using namespace sway;

TEST(FormatTest, base) { ASSERT_STREQ(core::misc::format("Hello %s", "world").c_str(), "Hello world"); }
