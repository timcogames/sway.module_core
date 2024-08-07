#ifndef SWAY_CORE_DETAIL_VALUEDATATYPES_HPP
#define SWAY_CORE_DETAIL_VALUEDATATYPES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

enum class ValueDataType : u32_t {
  BYTE = 0,
  SHORT,
  INT,
  LONG,
  UBYTE,
  USHORT,
  UINT,
  ULONG,
  FLOAT,
  DOUBLE,
  STRING,

  Latest
};

NAMESPACE_BEGIN(detail)

template <typename TYPE>
struct ValueDataTypeToEnum {};

template <ValueDataType KEY>
struct EnumToValueDataType {};

#include <sway/core/detail/valuedatatypemacros.hpp>

DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::BYTE, s8_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::SHORT, i16_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::INT, i32_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::LONG, i64_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::UBYTE, u8_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::USHORT, u16_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::UINT, u32_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::ULONG, u64_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::FLOAT, f32_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::DOUBLE, f64_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::STRING, std::string)

#undef DECLARE_VALUEDATA_TYPE_RELATSP

NAMESPACE_END(detail)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif  // SWAY_CORE_DETAIL_VALUEDATATYPES_HPP
