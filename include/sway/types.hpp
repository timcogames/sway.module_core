#ifndef _SWAY_TYPES_H
#define _SWAY_TYPES_H

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

NAMESPACE_END(sway)

#endif // _SWAY_TYPES_H
