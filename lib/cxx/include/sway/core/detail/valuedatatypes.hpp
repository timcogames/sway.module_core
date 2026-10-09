#ifndef SWAY_CORE_DETAIL_VALUEDATATYPES_HPP
#define SWAY_CORE_DETAIL_VALUEDATATYPES_HPP

#include <sway/_stdafx.hpp>
#include <sway/enumeratormacros.hpp>
#include <sway/types.hpp>

namespace sway::core {

// clang-format off
#define VALUE_DATA_TYPE_LIST(ITEM) \
  ITEM(BYTE, 1) \
  ITEM(SHORT, 2) \
  ITEM(INT, 3) \
  ITEM(LONG, 4) \
  ITEM(UBYTE, 5) \
  ITEM(USHORT, 6) \
  ITEM(UINT, 7) \
  ITEM(ULONG, 8) \
  ITEM(FLOAT, 9) \
  ITEM(DOUBLE, 10) \
  ITEM(STRING, 11)
// clang-format on

DECLARE_ENUM_U32(ValueDataType, VALUE_DATA_TYPE_LIST)

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

}  // namespace sway::core

#endif  // SWAY_CORE_DETAIL_VALUEDATATYPES_HPP
