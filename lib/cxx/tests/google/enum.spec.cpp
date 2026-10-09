#include <sway/common/numeraltypes.hpp>
#include <sway/core/detail/enumutils.hpp>
#include <sway/core/detail/valuedatatypes.hpp>
#include <sway/core/intrusive/priorities.hpp>
#include <sway/core/time/timerstatus.hpp>
#include <sway/defines.hpp>
#include <sway/enumeratormacros.hpp>

#include <gtest/gtest.h>

using namespace sway;
using namespace sway::core;

TEST(EnumTest, priority) {
  ASSERT_TRUE(toBase(Priority::Enum::LOW) == 10);
  ASSERT_TRUE(toBase(Priority::Enum::NORMAL) == 20);
  ASSERT_TRUE(toBase(Priority::Enum::HIGH) == 30);

  ASSERT_TRUE(Priority::EnumInfo::getRange() == 31);
  ASSERT_TRUE(Priority::EnumInfo::getRangeWithoutNone() == 30);

  ASSERT_TRUE(Priority::EnumInfo::getCount() == 4);
  ASSERT_TRUE(Priority::EnumInfo::getCountWithoutNone() == 3);
}

TEST(EnumTest, timer_status) {
  ASSERT_TRUE(toBase(TimerStatus::Enum::STOPPED) == 1);
  ASSERT_TRUE(toBase(TimerStatus::Enum::RUNNING) == 2);
  ASSERT_TRUE(toBase(TimerStatus::Enum::PAUSED) == 3);

  ASSERT_TRUE(TimerStatus::EnumInfo::getRange() == 4);
  ASSERT_TRUE(TimerStatus::EnumInfo::getRangeWithoutNone() == 3);

  ASSERT_TRUE(TimerStatus::EnumInfo::getCount() == 4);
  ASSERT_TRUE(TimerStatus::EnumInfo::getCountWithoutNone() == 3);
}

TEST(EnumTest, unwrap) {
  ASSERT_TRUE(toBase(ValueDataType::Enum::BYTE) == 1);
  ASSERT_TRUE(toEnum<ValueDataType::Enum>(1) == ValueDataType::Enum::BYTE);
}
