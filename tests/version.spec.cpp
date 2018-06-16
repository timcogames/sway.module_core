#include <boost/test/unit_test.hpp>
#include <sway/core.h>

using namespace sway;

BOOST_AUTO_TEST_SUITE(VersionTestSuite)

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(VersionTestCase_DefaultConstructor) {
	const core::Version version;

	BOOST_CHECK_EQUAL(version.getMajor(), 0);
	BOOST_CHECK_EQUAL(version.getMinor(), 0);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(VersionTestCase_ComponentConstructor) {
	const u8_t major = 1, minor = 2;
	const core::Version version(major, minor);

	BOOST_CHECK_EQUAL(version.getMajor(), major);
	BOOST_CHECK_EQUAL(version.getMinor(), minor);
}

/*!
 * \brief
 *    Убеждаемся, что сравнение номеров версий происходит правильно
 */
BOOST_AUTO_TEST_CASE(VersionTestCase_Compare) {
	const core::Version version(1, 1);

	BOOST_CHECK(version > core::Version(0, 0));
	BOOST_CHECK(version < core::Version(2, 0));

	BOOST_CHECK(version >= core::Version(0, 1));
	BOOST_CHECK(version >= core::Version(1, 1));

	BOOST_CHECK(version <= core::Version(1, 1));
	BOOST_CHECK(version <= core::Version(2, 1));

	BOOST_CHECK(version == core::Version(1, 1));
	BOOST_CHECK(version != core::Version(1, 0));
}

BOOST_AUTO_TEST_SUITE_END()
