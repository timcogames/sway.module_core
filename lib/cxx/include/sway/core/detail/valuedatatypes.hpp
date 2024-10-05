#ifndef SWAY_CORE_DETAIL_VALUEDATATYPES_HPP
#define SWAY_CORE_DETAIL_VALUEDATATYPES_HPP

#include <sway/enumeratormacros.hpp>
#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NS_BEGIN_SWAY()
NS_BEGIN(core)

// clang-format off
DECLARE_ENUM(ValueDataType, 
  BYTE, 
  SHORT, 
  INT, 
  LONG, 
  UBYTE, 
  USHORT, 
  UINT, 
  ULONG, 
  FLOAT, 
  DOUBLE, 
  STRING
)
// clang-format on

NS_BEGIN(detail)

template <typename TYPE>
struct ValueDataTypeToEnum {};

template <ValueDataType::Enum KEY>
struct EnumToValueDataType {};

#include <sway/core/detail/valuedatatypemacros.hpp>

DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Enum::BYTE, s8_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Enum::SHORT, i16_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Enum::INT, i32_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Enum::LONG, i64_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Enum::UBYTE, u8_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Enum::USHORT, u16_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Enum::UINT, u32_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Enum::ULONG, u64_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Enum::FLOAT, f32_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Enum::DOUBLE, f64_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Enum::STRING, std::string)

#undef DECLARE_VALUEDATA_TYPE_RELATSP

NS_END()  // namespace detail
NS_END()  // namespace core
NS_END()  // namespace sway

#endif  // SWAY_CORE_DETAIL_VALUEDATATYPES_HPP
