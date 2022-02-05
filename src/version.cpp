#include <sway/core/version.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

Version::Version() {
	_major = _minor = _patch = DONT_CARE;
	_extra = "\0";
}

Version::Version(s32_t major, s32_t minor, s32_t patch, lpcstr_t extra)
	: _major(major), _minor(minor), _patch(patch), _extra(extra) { }

Version::Version(const Version & version)
	: _major(version.getMajor())
	, _minor(version.getMinor())
	, _patch(version.getPatch())
	, _extra(version.getExtra()) {
	// Empty
}

s32_t Version::compare(const Version & version) const {
	if (_major < version.getMajor()) return -1;
	if (_major > version.getMajor()) return 1;
	if (_minor < version.getMinor()) return -1;
	if (_minor > version.getMinor()) return 1;
	if (_patch < version.getPatch()) return -1;
	if (_patch > version.getPatch()) return 1;

	return 0;
}

NAMESPACE_END(core)
NAMESPACE_END(sway)
