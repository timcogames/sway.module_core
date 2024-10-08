#include <sway/core.hpp>

#include <gtest/gtest.h>

#include <type_traits>  // std::is_same

NS_SHORT_SWAY()

template <typename T, typename U>
struct DecayEquiv : std::is_same<core::detail::Unwrap_t<T>, U>::type {};

TEST(RawTypeTest, unwrap) {
  ASSERT_TRUE((DecayEquiv<i32_t, int>::value));
  ASSERT_FALSE((DecayEquiv<i32_t, u32_t>::value));
}
