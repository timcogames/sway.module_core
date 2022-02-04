#include <boost/test/unit_test.hpp>
#include <sway/core.hpp>

using namespace sway;

BOOST_AUTO_TEST_SUITE(Version_TestSuite)

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(Version_TestCase_DefaultConstructor) {
	const core::Version version;

	BOOST_CHECK_EQUAL(version.getMajor(), DONT_CARE);
	BOOST_CHECK_EQUAL(version.getMinor(), DONT_CARE);
	BOOST_CHECK_EQUAL(version.getPatch(), DONT_CARE);
	BOOST_CHECK_EQUAL(version.getExtra().empty(), true);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(Version_TestCase_ComponentConstructor) {
	const s32_t major = 1, minor = 2, patch = 3;
	const core::Version version(major, minor, patch, "tmp");

	BOOST_CHECK_EQUAL(version.getMajor(), major);
	BOOST_CHECK_EQUAL(version.getMinor(), minor);
	BOOST_CHECK_EQUAL(version.getPatch(), patch);
	BOOST_CHECK_EQUAL(version.getExtra(), "tmp");
}

/*!
 * \brief
 *    Убеждаемся, что установка всех компонентов версии проходит правильно.
 */
BOOST_AUTO_TEST_CASE(Version_TestCase_Setters) {
	const s32_t major = 1, minor = 2, patch = 3;
	core::Version version;

	version.setMajor(major);
	BOOST_CHECK_EQUAL(version.getMajor(), major);

	version.setMinor(minor);
	BOOST_CHECK_EQUAL(version.getMinor(), minor);

	version.setPatch(patch);
	BOOST_CHECK_EQUAL(version.getPatch(), patch);

	version.setExtra("tmp");
	BOOST_CHECK_EQUAL(version.getExtra(), "tmp");
}

/*!
 * \brief
 *    Тест для оператора равенства
 */
BOOST_AUTO_TEST_CASE(Version_TestCase_EqualityOperator) {
	const core::Version version(1, 2, 3);

	BOOST_CHECK(version == core::Version(1, 2, 3));
}

/*!
 * \brief
 *    Тест для оператора неравенства.
 */
BOOST_AUTO_TEST_CASE(Version_TestCase_NonEqualityOperator) {
	const core::Version version(1, 2, 3);

	BOOST_CHECK(version != core::Version(1));
	BOOST_CHECK(version != core::Version(1, 2));
}

/*!
 * \brief
 *    Убеждаемся, что сравнение номеров версий происходит правильно
 */
BOOST_AUTO_TEST_CASE(Version_TestCase_ComparisonOperation) {
	const core::Version version(5, 2, 3);

	BOOST_CHECK(version >= core::Version(4));
	BOOST_CHECK(version >= core::Version(5, 1));
	BOOST_CHECK(version >= core::Version(4, 2));
	BOOST_CHECK(version >= core::Version(5, 2, 2));
	BOOST_CHECK(version >= core::Version(5, 1, 3));
	BOOST_CHECK(version >= core::Version(4, 2, 3));

	BOOST_CHECK(version <= core::Version(6));
	BOOST_CHECK(version <= core::Version(5, 3));
	BOOST_CHECK(version <= core::Version(6, 2));
	BOOST_CHECK(version <= core::Version(5, 2, 4));
	BOOST_CHECK(version <= core::Version(5, 3, 3));
	BOOST_CHECK(version <= core::Version(6, 2, 3));
}

BOOST_AUTO_TEST_SUITE_END()
