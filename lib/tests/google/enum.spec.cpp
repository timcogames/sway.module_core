#include <sway/core.hpp>

#include <gtest/gtest.h>

using namespace sway;

TEST(EnumTest, Unwrap) {
  ASSERT_TRUE(core::detail::toUnderlying(core::detail::DataType_t::kChar) == 0);
  ASSERT_TRUE(core::detail::toEnum<core::detail::DataType_t>(0) == core::detail::DataType_t::kChar);
}
