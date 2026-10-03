#include <sway/core.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()

typedef core::TFunctionPointer<void()> TestFunc_t;

TEST(FunctionTest, base) {
  TestFunc_t func;
  ASSERT_FALSE(func);
  func = (core::ProcAddress_t)[](){};
  ASSERT_TRUE(func);
}
