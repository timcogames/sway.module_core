#ifndef SWAY_CORE_DETAIL_RAWTYPE_HPP
#define SWAY_CORE_DETAIL_RAWTYPE_HPP

#include <sway/namespacemacros.hpp>

#include <type_traits>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(detail)

template <typename DATA_TYPE>
using Unwrap_t = typename std::decay<DATA_TYPE>::type;

NAMESPACE_END(detail)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_DETAIL_RAWTYPE_HPP
