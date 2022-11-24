#ifndef SWAY_CORE_DETAIL_VALUEDATATYPES_HPP
#define SWAY_CORE_DETAIL_VALUEDATATYPES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)

enum class ValueDataType : u32_t {
  Char,
  Short,
  Int,
  Long,
  UChar,
  UShort,
  UInt,
  ULong,
  Float,
  Double,
  // STD
  String
};

NAMESPACE_BEGIN(detail)

template <typename TValueType>
struct ValueDataTypeToEnum {};

template <ValueDataType TKey>
struct EnumToValueDataType {};

#include <sway/core/detail/valuedatatypemacros.hpp>

DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Char, s8_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Short, s16_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Int, s32_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Long, s64_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::UChar, u8_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::UShort, u16_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::UInt, u32_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::ULong, u64_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Float, f32_t)
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::Double, f64_t)
// STD
DECLARE_VALUEDATA_TYPE_RELATSP(ValueDataType::String, std::string)

#undef DECLARE_VALUEDATA_TYPE_RELATSP

NAMESPACE_END(detail)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
