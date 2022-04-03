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

  s32_t getMajor() const { return major_; }

  void setMinor(s32_t minor) { minor_ = minor; }

  s32_t getMinor() const { return minor_; }

  void setPatch(s32_t patch) { patch_ = patch; }

  s32_t getPatch() const { return patch_; }

  void setExtra(lpcstr_t extra) { extra_ = extra; }

  std::string getExtra() const { return extra_; }

  s32_t compare(const Version &version) const;

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
