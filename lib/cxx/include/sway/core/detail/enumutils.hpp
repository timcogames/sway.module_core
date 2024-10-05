#ifndef SWAY_CORE_DETAIL_ENUMUTILS_HPP
#define SWAY_CORE_DETAIL_ENUMUTILS_HPP

#include <sway/namespacemacros.hpp>

#include <type_traits>

NS_BEGIN_SWAY()
NS_BEGIN(core)
NS_BEGIN(detail)

// clang-format off
template <typename DATA_TYPE> using IsEnum_t = std::is_enum<DATA_TYPE>;
template <typename DATA_TYPE> using IsIntegral_t = std::is_integral<DATA_TYPE>;
// clang-format on

template <bool CONDITION, typename DATA_TYPE = void>
using EnableIf_t = typename std::enable_if_t<CONDITION, DATA_TYPE>;

template <typename ENUM>
using BaseEnumType_t = typename std::underlying_type<ENUM>::type;

template <typename ENUM>
constexpr inline auto toBase(ENUM key) noexcept -> EnableIf_t<IsEnum_t<ENUM>::value, BaseEnumType_t<ENUM>> {
  return static_cast<BaseEnumType_t<ENUM>>(key);
}

template <typename ENUM, typename DATA_TYPE>
constexpr inline auto toEnum(
    DATA_TYPE val) noexcept -> EnableIf_t<IsEnum_t<ENUM>::value && IsIntegral_t<DATA_TYPE>::value, ENUM> {
  return static_cast<ENUM>(val);
}

NS_END()  // namespace detail
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_DETAIL_ENUMUTILS_HPP
