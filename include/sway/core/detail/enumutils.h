#ifndef SWAY_CORE_DETAIL_ENUMUTILS_H
#define SWAY_CORE_DETAIL_ENUMUTILS_H

#include <sway/namespacemacros.h>
#include <type_traits>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(detail)

template<typename Enum>
using enableEnum_t = typename std::enable_if<std::is_enum<Enum>::value, typename std::underlying_type<Enum>::type>::type;

template<typename Enum>
constexpr inline enableEnum_t<Enum> toUnderlying(Enum key) noexcept {
	return static_cast<typename std::underlying_type<Enum>::type>(key);
}   

template<typename Enum, typename Type>
constexpr inline typename std::enable_if<std::is_enum<Enum>::value && std::is_integral<Type>::value, Enum>::type toEnum(Type value) noexcept {
	return static_cast<Enum>(value);
}

NAMESPACE_END(detail)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif // SWAY_CORE_DETAIL_ENUMUTILS_H
