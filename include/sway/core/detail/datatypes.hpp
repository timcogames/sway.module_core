#ifndef SWAY_CORE_DETAIL_DATATYPES_HPP
#define SWAY_CORE_DETAIL_DATATYPES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(detail)

enum class DataType_t : u32_t { kChar, kShort, kInt, kLong, kUChar, kUShort, kUInt, kULong, kFloat, kDouble };

template <typename Type>
struct DataTypeToEnum {};

template <DataType_t Key>
struct EnumToDataType {};

#include <sway/core/detail/datatypemacros.hpp>

ENUM_DATATYPE(DataType_t::kChar, s8_t)
ENUM_DATATYPE(DataType_t::kShort, s16_t)
ENUM_DATATYPE(DataType_t::kInt, s32_t)
ENUM_DATATYPE(DataType_t::kLong, s64_t)
ENUM_DATATYPE(DataType_t::kUChar, u8_t)
ENUM_DATATYPE(DataType_t::kUShort, u16_t)
ENUM_DATATYPE(DataType_t::kUInt, u32_t)
ENUM_DATATYPE(DataType_t::kULong, u64_t)
ENUM_DATATYPE(DataType_t::kFloat, f32_t)
ENUM_DATATYPE(DataType_t::kDouble, f64_t)

#undef ENUM_DATATYPE

NAMESPACE_END(detail)
NAMESPACE_END(core)
NAMESPACE_END(sway)

#endif
