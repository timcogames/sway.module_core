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
inline std::string guid() {
	return format("%x%x-%x-%x-%x-%x%x%x",
		rand(), rand(),
		rand(),
		((rand() & 0x0fff) | 0x4000),
		rand() % 0x3fff + 0x8000,
		rand(), rand(), rand());
}

NAMESPACE_END(misc)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // _SWAY_CORE_MISC_GUID_H
