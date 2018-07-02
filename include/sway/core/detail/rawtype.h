#ifndef SWAY_CORE_DETAIL_RAWTYPE_H
#define SWAY_CORE_DETAIL_RAWTYPE_H

#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(detail)

template <typename TYPE>
struct RawType {
	using type = TYPE;
};

NAMESPACE_END(detail)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_DETAIL_RAWTYPE_H
