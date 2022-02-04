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

#endif // _SWAY_CORE_MISC_GUID_HPP
