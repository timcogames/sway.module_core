#ifndef SWAY_CORE_DETAIL_ENUMUTILS_H
#define SWAY_CORE_DETAIL_ENUMUTILS_H

#include <sway/namespacemacros.h>
#include <type_traits>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(detail)

template<typename ENUM>
using enableEnum_t = typename std::enable_if<std::is_enum<ENUM>::value, typename std::underlying_type<ENUM>::type>::type;

template<typename ENUM>
constexpr inline enableEnum_t<ENUM> toUnderlying(ENUM value) noexcept {
	return static_cast<typename std::underlying_type<ENUM>::type>(value);
}   

template<typename ENUM, typename TYPE>
constexpr inline typename std::enable_if<std::is_enum<ENUM>::value && std::is_integral<TYPE>::value, ENUM>::type toEnum(TYPE value) noexcept {
	return static_cast<ENUM>(value);
}

NAMESPACE_END(detail)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_DETAIL_ENUMUTILS_H
