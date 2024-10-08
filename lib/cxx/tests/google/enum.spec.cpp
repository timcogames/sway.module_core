#include <sway/core/detail/enumutils.hpp>
#include <sway/core/detail/valuedatatypes.hpp>
#include <sway/defines.hpp>
#include <sway/enumeratormacros.hpp>
#include <sway/numeraltypes.hpp>

#include <gtest/gtest.h>

NS_SHORT(core)

TEST(EnumTest, unwrap) {
  ASSERT_TRUE(detail::toBase(ValueDataType::Enum::BYTE) == 1);
  ASSERT_TRUE(detail::toEnum<ValueDataType::Enum>(1) == ValueDataType::Enum::BYTE);
}

DECLARE_ENUM(DefType, AAAA, BBBB, CCCC)
TEST(EnumTest, macros_def) {
  ASSERT_TRUE(detail::toBase(DefType::Enum::NONE) == 0);
  ASSERT_TRUE(detail::toBase(DefType::Enum::AAAA) == 1);
  ASSERT_TRUE(detail::toBase(DefType::Enum::BBBB) == 2);
  ASSERT_TRUE(detail::toBase(DefType::Enum::CCCC) == 3);
  ASSERT_TRUE(DefTypeLatest == 4);
  ASSERT_TRUE(DefTypeCount == 4);
  ASSERT_TRUE(DefTypeCountWithoutNone == 3);
}

DECLARE_ENUM_IDX(IdxType, AAAA, BBBB = 6, CCCC)
TEST(EnumTest, macros_idx) {
  ASSERT_TRUE(detail::toBase(IdxType::Enum::NONE) == -1);
  ASSERT_TRUE(detail::toBase(IdxType::Enum::AAAA) == 0);
  ASSERT_TRUE(detail::toBase(IdxType::Enum::BBBB) == 6);
  ASSERT_TRUE(detail::toBase(IdxType::Enum::CCCC) == 7);
  ASSERT_TRUE(IdxTypeLatest == 8);
  ASSERT_TRUE(IdxTypeCount == 4);
  ASSERT_TRUE(IdxTypeCountWithoutNone == 3);
}
