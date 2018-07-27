#include <boost/test/unit_test.hpp>
#include <sway/core.h>

using namespace sway;

BOOST_AUTO_TEST_SUITE(Enum_TestSuite_Unwrap)

BOOST_AUTO_TEST_CASE(Enum_TestCase) {
	BOOST_CHECK_EQUAL(core::detail::toUnderlying(Type_t::kChar) == 1, true);
	BOOST_CHECK_EQUAL(core::detail::toEnum<Type_t>(1) == Type_t::kChar, true);
}

BOOST_AUTO_TEST_SUITE_END()
