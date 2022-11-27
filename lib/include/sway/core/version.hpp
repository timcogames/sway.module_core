#ifndef SWAY_CORE_VERSION_HPP
#define SWAY_CORE_VERSION_HPP

#include <sway/defines.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>
#include <utility>  // std::move

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

/*!
 * \brief Класс для хранения информации о версии.
 */
class Version {
public:
  Version();

  Version(const Version &version);

  explicit Version(s32_t major, s32_t minor = DONT_CARE, s32_t patch = DONT_CARE, lpcstr_t extra = "\0");

  ~Version() = default;

  void setMajor(s32_t major) { major_ = major; }

  auto getMajor() const -> s32_t { return major_; }

  void setMinor(s32_t minor) { minor_ = minor; }

  auto getMinor() const -> s32_t { return minor_; }

  void setPatch(s32_t patch) { patch_ = patch; }

  auto getPatch() const -> s32_t { return patch_; }

  void setExtra(lpcstr_t extra) { extra_ = extra; }

  auto getExtra() const -> std::string { return extra_; }

  auto compare(const Version &version) const -> s32_t;

  inline Version &operator=(const Version &version) {
    major_ = version.getMajor();
    minor_ = version.getMinor();
    patch_ = version.getPatch();
    extra_ = version.getExtra();

    return *this;
  }

  inline bool operator<(const Version &version) const { return compare(version) < 0; }

  inline bool operator>(const Version &version) const { return compare(version) > 0; }

  inline bool operator==(const Version &version) const { return compare(version) == 0; }

  inline bool operator!=(const Version &version) const { return compare(version) != 0; }

  inline bool operator>=(const Version &version) const { return *this > version || *this == version; }

  inline bool operator<=(const Version &version) const { return *this < version || *this == version; }

private:
  s32_t major_; /*!< Главный номер версии. */
  s32_t minor_; /*!< Вспомогательный номер версии. */
  s32_t patch_; /*!< Уровень исправлений. */
  std::string extra_; /*!< Дополнительные символы. */
};

NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
