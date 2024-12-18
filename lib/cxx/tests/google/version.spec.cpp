#include <sway/core.hpp>

#include <gtest/gtest.h>

NS_SHORT_SWAY()

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(VersionTest, ctor_def) {
  const core::Version version;

  ASSERT_EQ(version.getMajor(), GLOB_DONT_CARE);
  ASSERT_EQ(version.getMinor(), GLOB_DONT_CARE);
  ASSERT_EQ(version.getPatch(), GLOB_DONT_CARE);
  ASSERT_TRUE(version.getExtra().empty());
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(VersionTest, ctor_comps) {
  const i32_t major = 1, minor = 2, patch = 3;
  const core::Version version(major, minor, patch, "tmp");

  ASSERT_EQ(version.getMajor(), major);
  ASSERT_EQ(version.getMinor(), minor);
  ASSERT_EQ(version.getPatch(), patch);
  ASSERT_STREQ(version.getExtra().c_str(), "tmp");
}

/**
 * @brief Убеждаемся, что установка всех компонентов версии проходит правильно.
 */
TEST(VersionTest, setters) {
  const i32_t major = 1, minor = 2, patch = 3;
  core::Version version;

  version.setMajor(major);
  ASSERT_EQ(version.getMajor(), major);

  version.setMinor(minor);
  ASSERT_EQ(version.getMinor(), minor);

  version.setPatch(patch);
  ASSERT_EQ(version.getPatch(), patch);

  version.setExtra("tmp");
  ASSERT_STREQ(version.getExtra().c_str(), "tmp");
}

/**
 * @brief Тест для оператора равенства.
 */
TEST(VersionTest, equality_operator) {
  const core::Version version(1, 2, 3);

  ASSERT_TRUE(version == core::Version(1, 2, 3));
}

/**
 * @brief Тест для оператора неравенства.
 */
TEST(VersionTest, non_equality_operator) {
  const core::Version version(1, 2, 3);

  ASSERT_NE(version, core::Version(1));
  ASSERT_NE(version, core::Version(1, 2));
}

/**
 * @brief Убеждаемся, что сравнение номеров версий происходит правильно.
 */
TEST(VersionTest, comparison_operation) {
  const core::Version version(5, 2, 3);

  ASSERT_GE(version, core::Version(4));
  ASSERT_GE(version, core::Version(5, 1));
  ASSERT_GE(version, core::Version(4, 2));
  ASSERT_GE(version, core::Version(5, 2, 2));
  ASSERT_GE(version, core::Version(5, 1, 3));
  ASSERT_GE(version, core::Version(4, 2, 3));

  ASSERT_LE(version, core::Version(6));
  ASSERT_LE(version, core::Version(5, 3));
  ASSERT_LE(version, core::Version(6, 2));
  ASSERT_LE(version, core::Version(5, 2, 4));
  ASSERT_LE(version, core::Version(5, 3, 3));
  ASSERT_LE(version, core::Version(6, 2, 3));
}
