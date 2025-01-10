#include <sway/core/utilities/date/timestamp.hpp>
#include <sway/namespacemacros.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()
NS_SHORT(core)

TEST(TimestampTest, toStr) {
  Timestamp timestamp;
  printf("Timestamp Now: %lld\n", timestamp.now());
  std::cout << Timestamp::toStr(timestamp, false) << std::endl;
}
