#include <sway/core/version.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

Version::Version() {
  major_ = minor_ = patch_ = DONT_CARE;
  extra_ = "\0";
}

Version::Version(const Version &version)
    : major_(version.getMajor())
    , minor_(version.getMinor())
    , patch_(version.getPatch())
    , extra_(version.getExtra()) {}

Version::Version(s32_t major, s32_t minor, s32_t patch, lpcstr_t extra)
    : major_(major)
    , minor_(minor)
    , patch_(patch)
    , extra_(extra) {}

auto Version::compare(const Version &version) const -> s32_t {
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

NAMESPACE_END(core)
NAMESPACE_END(sway)
