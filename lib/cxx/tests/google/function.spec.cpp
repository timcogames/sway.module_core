#include <sway/core.hpp>

#include <gtest/gtest.h>

using namespace sway;

typedef core::binding::TFunction<void()> TestFunc_t;

TEST(FunctionTest, Base) {
  TestFunc_t func;
  ASSERT_FALSE(func);
  func = (core::binding::ProcAddress_t)[](){};
  ASSERT_TRUE(func);
}
