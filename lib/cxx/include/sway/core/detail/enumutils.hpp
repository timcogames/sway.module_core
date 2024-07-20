#ifndef SWAY_CORE_DETAIL_ENUMUTILS_HPP
#define SWAY_CORE_DETAIL_ENUMUTILS_HPP

#include <sway/namespacemacros.hpp>

#include <type_traits>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(detail)

// clang-format off
template <typename TDataType> using IsEnum_t = std::is_enum<TDataType>;
template <typename TDataType> using IsIntegral_t = std::is_integral<TDataType>;
// clang-format on

template <bool TCondition, typename TDataType = void>
using EnableIf_t = typename std::enable_if_t<TCondition, TDataType>;

template <typename TEnum>
using BaseEnumType_t = typename std::underlying_type<TEnum>::type;

template <typename TEnum>
constexpr inline auto toBase(TEnum key) noexcept -> EnableIf_t<IsEnum_t<TEnum>::value, BaseEnumType_t<TEnum>> {
  return static_cast<BaseEnumType_t<TEnum>>(key);
}

template <typename TEnum, typename TDataType>
constexpr inline auto toEnum(
    TDataType val) noexcept -> EnableIf_t<IsEnum_t<TEnum>::value && IsIntegral_t<TDataType>::value, TEnum> {
  return static_cast<TEnum>(val);
}

NAMESPACE_END(detail)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_DETAIL_ENUMUTILS_HPP
