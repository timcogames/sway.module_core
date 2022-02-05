#include <boost/test/unit_test.hpp>
#include <sway/core.hpp>

using namespace sway;

template<typename T, typename U>
struct DecayEquiv : std::is_same<core::detail::unwrap_t<T>, U>::type {
	// Empty
};

BOOST_AUTO_TEST_SUITE(RawType_TestSuite_Unwrap)

BOOST_AUTO_TEST_CASE(RawType_TestCase) {
	BOOST_CHECK((DecayEquiv<s32_t, int>::value));
	BOOST_CHECK_EQUAL((DecayEquiv<s32_t, u32_t>::value), false);
}

BOOST_AUTO_TEST_SUITE_END()
