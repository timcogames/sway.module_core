#ifndef _SWAY_CORE_MISC_GUID_H
#define _SWAY_CORE_MISC_GUID_H

#include <sway/core/misc/format.h>
#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <string> // std::string
#include <stdlib.h> // rand

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(misc)

/*!
 * \brief
 *    Генерирует уникальный идентификатор.
 */
inline std::string genUid(const std::vector<s32_t> & format) {
	static const std::string bucket = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	std::string result;
	std::vector<s32_t>::const_iterator iter = format.begin();
	while (iter != format.end()) {
		if (iter != format.begin())
			result += '-';

		for (u32_t i = 0; i < *iter; ++i)
			result += bucket[rand() % bucket.size()];

		++iter;
	}

	return result;
}

NAMESPACE_END(misc)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_MISC_GUID_H
