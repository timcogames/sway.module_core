#include <boost/test/unit_test.hpp>
#include <sway/core.hpp>

using namespace sway;

BOOST_AUTO_TEST_SUITE(Path_TestSuite)

BOOST_AUTO_TEST_CASE(Path_TestCase_getFilename) {
	BOOST_CHECK_EQUAL(core::generic::io::Path("/foo/bar.txt").getFilename().c_str(), "bar.txt");
}

BOOST_AUTO_TEST_CASE(Path_TestCase_getExtension) {
	BOOST_CHECK_EQUAL(core::generic::io::Path("/foo/bar.txt").getExtension().c_str(), "txt");
}

BOOST_AUTO_TEST_SUITE_END()
