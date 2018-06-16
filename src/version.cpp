#include <sway/core/version.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

Version::Version()
	: _major(0)
	, _minor(0) {
	// Empty
}

Version::Version(u8_t major, u8_t minor)
	: _major(major)
	, _minor(minor) {
	// Empty
}

Version::Version(const Version & version)
	: _major(version.getMajor())
	, _minor(version.getMinor()) {
	// Empty
}

Version::Version(Version && version)
	: _major(std::move(version.getMajor()))
	, _minor(std::move(version.getMinor())) {
	// Empty
}

u8_t Version::getMajor() const {
	return _major;
}

u8_t Version::getMinor() const {
	return _minor;
}

NAMESPACE_END(core)
NAMESPACE_END(sway)
