#include <sway/core.hpp>

#include <gtest/gtest.h>

using namespace sway;

template <typename T, typename U>
struct DecayEquiv : std::is_same<core::detail::unwrap_t<T>, U>::type {};

TEST(RawTypeTest, Unwrap) {
    ASSERT_TRUE((DecayEquiv<s32_t, int>::value));
    ASSERT_FALSE((DecayEquiv<s32_t, u32_t>::value));
}
