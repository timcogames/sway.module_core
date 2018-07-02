#ifndef SWAY_TYPES_H
#define SWAY_TYPES_H

#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)

enum Types {
	kType_None, /*!< Неопределенный тип */
	kType_Char, /*!< Тип 8bit целого числа со знаком */
	kType_Short, /*!< Тип 16bit целого числа со знаком */
	kType_Int, /*!< Тип 32bit целого числа со знаком */
	kType_Long, /*!< Тип 64bit целого числа со знаком */
	kType_UChar, /*!< Тип 8bit целого числа без знака */
	kType_UShort, /*!< Тип 16bit целого числа без знака */
	kType_UInt, /*!< Тип 32bit целого числа без знака */
	kType_ULong, /*!< Тип 64bit целого числа без знака */
	kType_Float,
	kType_Double
};

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

NAMESPACE_END(sway)

#endif // SWAY_TYPES_H
