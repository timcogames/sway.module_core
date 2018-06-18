#include <sway/core/version.h>
#include <utility> // std::move

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

Version & Version::operator=(const Version & version) {
	_major = version.getMajor();
	_minor = version.getMinor();
	_patch = version.getPatch();
	_extra = version.getExtra();

	return *this;
}

Version & Version::operator=(Version && version) {
	_major = std::move(version.getMajor());
	_minor = std::move(version.getMinor());
	_patch = std::move(version.getPatch());
	_extra = std::move(version.getExtra());

	return *this;
}

bool Version::operator<(const Version & version) const {
	return compare(version) < 0;
}

bool Version::operator>(const Version & version) const {
	return compare(version) > 0;
}

bool Version::operator==(const Version & version) const {
	return compare(version) == 0;
}

bool Version::operator!=(const Version & version) const {
	return compare(version) != 0;
}

bool Version::operator>=(const Version & version) const {
	return *this > version || *this == version;
}

bool Version::operator<=(const Version & version) const {
	return *this < version || *this == version;
}

NAMESPACE_END(core)
NAMESPACE_END(sway)
