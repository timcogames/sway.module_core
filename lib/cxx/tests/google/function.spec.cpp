#include <sway/core.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()

typedef core::binding::TFunction<void()> TestFunc_t;

TEST(FunctionTest, base) {
  TestFunc_t func;
  ASSERT_FALSE(func);
  func = (core::binding::ProcAddress_t)[](){};
  ASSERT_TRUE(func);
}
