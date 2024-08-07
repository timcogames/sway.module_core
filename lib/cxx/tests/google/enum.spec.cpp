#include <sway/core.hpp>

#include <gtest/gtest.h>

using namespace sway;

TEST(EnumTest, unwrap) {
  ASSERT_TRUE(core::detail::toBase(core::ValueDataType::BYTE) == 0);
  ASSERT_TRUE(core::detail::toEnum<core::ValueDataType>(0) == core::ValueDataType::BYTE);
}
