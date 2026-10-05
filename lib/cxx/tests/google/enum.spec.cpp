#include <sway/common/numeraltypes.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/core/detail/valuedatatypes.hpp>
#include <sway/defines.hpp>
#include <sway/enumeratormacros.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

DECLARE_ENUM(DefType, AAAA, BBBB, CCCC)
DECLARE_ENUM_IDX(IdxType, AAAA, BBBB, CCCC)

TEST(EnumTest, unwrap) {
  ASSERT_TRUE(toBase(ValueDataType::Enum::BYTE) == 1);
  ASSERT_TRUE(toEnum<ValueDataType::Enum>(1) == ValueDataType::Enum::BYTE);
}

TEST(EnumTest, macros_def) {
  ASSERT_TRUE(toBase(DefType::Enum::NONE) == 0);
  ASSERT_TRUE(toBase(DefType::Enum::AAAA) == 1);
  ASSERT_TRUE(toBase(DefType::Enum::BBBB) == 2);
  ASSERT_TRUE(toBase(DefType::Enum::CCCC) == 3);
  ASSERT_TRUE(DefType::Latest == 4);
  ASSERT_TRUE(DefType::Count == 4);
  ASSERT_TRUE(DefType::CountWithoutNone == 3);
}

TEST(EnumTest, macros_idx) {
  ASSERT_TRUE(toBase(IdxType::Enum::NONE) == -1);
  ASSERT_TRUE(toBase(IdxType::Enum::AAAA) == 0);
  ASSERT_TRUE(toBase(IdxType::Enum::BBBB) == 1);
  ASSERT_TRUE(toBase(IdxType::Enum::CCCC) == 2);
  ASSERT_TRUE(IdxType::Latest == 3);
  ASSERT_TRUE(IdxType::Count == 4);
  ASSERT_TRUE(IdxType::CountWithoutNone == 3);
}
