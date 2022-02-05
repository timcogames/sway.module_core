#include <boost/test/unit_test.hpp>
#include <sway/core.hpp>

using namespace sway;

typedef core::binding::TFunction<void()> TestFunc_t;

BOOST_AUTO_TEST_SUITE(Function_TestSuite)

BOOST_AUTO_TEST_CASE(Function_TestCase) {
	TestFunc_t func;
	BOOST_CHECK_EQUAL(func, false);
	func = (core::binding::ProcAddress_t)[]() {
		// Empty
	};
	BOOST_CHECK_EQUAL(func, true);
}

BOOST_AUTO_TEST_SUITE_END()
