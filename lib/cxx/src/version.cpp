#include <sway/core/version.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(core)

Version::Version() {
  major_ = minor_ = patch_ = GLOB_DONT_CARE;
  extra_ = "\0";
}

Version::Version(const Version &version)
    : major_(version.getMajor())
    , minor_(version.getMinor())
    , patch_(version.getPatch())
    , extra_(version.getExtra()) {}

Version::Version(i32_t major, i32_t minor, i32_t patch, lpcstr_t extra)
    : major_(major)
    , minor_(minor)
    , patch_(patch)
    , extra_(extra) {}

auto Version::compare(const Version &version) const -> i32_t {
  if (major_ < version.getMajor()) {
    return -1;
  }
  if (major_ > version.getMajor()) {
    return 1;
  }
  if (minor_ < version.getMinor()) {
    return -1;
  }
  if (minor_ > version.getMinor()) {
    return 1;
  }
  if (patch_ < version.getPatch()) {
    return -1;
  }
  if (patch_ > version.getPatch()) {
    return 1;
  }

  return 0;
}

NS_END()  // namespace core
NS_END()  // namespace sway
