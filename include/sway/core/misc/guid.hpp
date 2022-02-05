#ifndef _SWAY_CORE_MISC_GUID_HPP
#define _SWAY_CORE_MISC_GUID_HPP

#include <sway/core/misc/format.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string> // std::string
#include <stdlib.h> // rand

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(misc)

#define UID_ROOT ("root")
#define UID_ZERO ("00000000-0000-0000-0000-000000000000")

inline std::string randomUid(const std::vector<int> & format) {
	static const std::string bucket = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	std::string result;
	std::vector<int>::const_iterator iter = format.begin();
	while (iter != format.end()) {
		if (iter != format.begin())
			result += '-';

		for (int i = 0; i < *iter; ++i)
			result += bucket[rand() % bucket.size()];

		++iter;
	}

	return result;
}

NAMESPACE_END(misc)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_MISC_GUID_HPP
