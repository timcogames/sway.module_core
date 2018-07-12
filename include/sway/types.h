#ifndef SWAY_TYPES_H
#define SWAY_TYPES_H

#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)

typedef char s8_t;
typedef short s16_t;
typedef int s32_t;
typedef float f32_t;
typedef long s64_t;
typedef double f64_t;

typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned int u32_t;
typedef unsigned long u64_t;

typedef s8_t * lpstr_t;
typedef const s8_t * lpcstr_t;

enum class Type_t : u8_t {
	kNone, /*!< Неопределенный тип */
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

NAMESPACE_END(sway)

#endif // SWAY_TYPES_H
