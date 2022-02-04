#include <boost/test/unit_test.hpp>
#include <sway/core.hpp>

using namespace sway;

BOOST_AUTO_TEST_SUITE(Enum_TestSuite_Unwrap)

BOOST_AUTO_TEST_CASE(Enum_TestCase) {
	BOOST_CHECK_EQUAL(core::detail::toUnderlying(core::detail::DataType_t::kChar) == 0, true);
	BOOST_CHECK_EQUAL(core::detail::toEnum<core::detail::DataType_t>(0) == core::detail::DataType_t::kChar, true);
}

BOOST_AUTO_TEST_SUITE_END()
