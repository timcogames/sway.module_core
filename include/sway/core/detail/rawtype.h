#ifndef SWAY_CORE_DETAIL_RAWTYPE_H
#define SWAY_CORE_DETAIL_RAWTYPE_H

#include <sway/namespacemacros.h>
#include <type_traits>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(detail)

template<typename TYPE>
using unwrap_t = typename std::decay<TYPE>::type;

NAMESPACE_END(detail)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_DETAIL_RAWTYPE_H
