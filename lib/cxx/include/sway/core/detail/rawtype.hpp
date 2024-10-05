#ifndef SWAY_CORE_DETAIL_RAWTYPE_HPP
#define SWAY_CORE_DETAIL_RAWTYPE_HPP

#include <sway/namespacemacros.hpp>

#include <type_traits>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(detail)

template <typename DATA_TYPE>
using Unwrap_t = typename std::decay<DATA_TYPE>::type;

NS_END()  // namespace detail
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_DETAIL_RAWTYPE_HPP
