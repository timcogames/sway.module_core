#ifndef _SWAY_CORE_DETAIL_DATATYPES_HPP
#define _SWAY_CORE_DETAIL_DATATYPES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(core)
NAMESPACE_BEGIN(detail)

enum class DataType_t : u32_t {
	kChar, /*!< Тип 8bit целого числа со знаком */
	kShort, /*!< Тип 16bit целого числа со знаком */
	kInt, /*!< Тип 32bit целого числа со знаком */
	kLong, /*!< Тип 64bit целого числа со знаком */
	kUChar, /*!< Тип 8bit целого числа без знака */
	kUShort, /*!< Тип 16bit целого числа без знака */
	kUInt, /*!< Тип 32bit целого числа без знака */
	kULong, /*!< Тип 64bit целого числа без знака */
	kFloat,
	kDouble
};

template<typename Type>
struct DataTypeToEnum { };

template<DataType_t Key>
struct EnumToDataType { };

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

#endif // _SWAY_CORE_DETAIL_DATATYPES_HPP
