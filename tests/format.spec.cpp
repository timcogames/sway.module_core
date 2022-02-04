#include <boost/test/unit_test.hpp>
#include <sway/core.hpp>

using namespace sway;

BOOST_AUTO_TEST_SUITE(Format_TestSuite)

BOOST_AUTO_TEST_CASE(Format_TestCase) {
	BOOST_CHECK_EQUAL(core::misc::format("Hello %s", "world").c_str(), "Hello world");
}

BOOST_AUTO_TEST_SUITE_END()
