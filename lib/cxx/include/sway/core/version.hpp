#ifndef SWAY_CORE_VERSION_HPP
#define SWAY_CORE_VERSION_HPP

#include <sway/_stdafx.hpp>
#include <sway/defines.hpp>
#include <sway/types.hpp>

namespace sway::core {

/**
 * \~english @brief Class for storing version information.
 * \~russian @brief Класс для хранения информации о версии.
 */
class Version {
public:
#pragma region "Ctors/Dtor"

  Version();

  Version(const Version &version);

  explicit Version(i32_t major, i32_t minor = GLOB_DONT_CARE, i32_t patch = GLOB_DONT_CARE, lpcstr_t extra = "\0");

  ~Version() = default;

#pragma endregion

  void setMajor(i32_t major) { major_ = major; }

  [[nodiscard]] auto getMajor() const -> i32_t { return major_; }

  void setMinor(i32_t minor) { minor_ = minor; }

  [[nodiscard]] auto getMinor() const -> i32_t { return minor_; }

  void setPatch(i32_t patch) { patch_ = patch; }

  [[nodiscard]] auto getPatch() const -> i32_t { return patch_; }

  void setExtra(lpcstr_t extra) { extra_ = extra; }

  [[nodiscard]] auto getExtra() const -> std::string { return extra_; }

  [[nodiscard]] auto compare(const Version &version) const -> i32_t;

  Version &operator=(const Version &version) {
    major_ = version.getMajor();
    minor_ = version.getMinor();
    patch_ = version.getPatch();
    extra_ = version.getExtra();

    return *this;
  }

  auto operator<(const Version &version) const -> bool { return compare(version) < 0; }

  auto operator>(const Version &version) const -> bool { return compare(version) > 0; }

  auto operator==(const Version &version) const -> bool { return compare(version) == 0; }

  auto operator!=(const Version &version) const -> bool { return compare(version) != 0; }

  auto operator>=(const Version &version) const -> bool { return *this > version || *this == version; }

  auto operator<=(const Version &version) const -> bool { return *this < version || *this == version; }

private:
  i32_t major_;  //!< \~english Main version number. \~russian Главный номер версии.
  i32_t minor_;  //!< \~english Secondary version number. \~russian Вспомогательный номер версии.
  i32_t patch_;  //!< \~english Revision level. \~russian Уровень исправлений.
  std::string extra_;  //!< \~english Additional characters. \~russian Дополнительные символы.
};

}  // namespace sway::core

#endif  // SWAY_CORE_VERSION_HPP
