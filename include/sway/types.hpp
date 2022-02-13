#ifndef SWAY_TYPES_HPP
#define SWAY_TYPES_HPP

#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)

using s8_t = char;
using s16_t = short;
using s32_t = int;
using f32_t = float;
using s64_t = long;
using f64_t = double;

using u8_t = unsigned char;
constexpr int U8_ALIGN = 8;
using u16_t = unsigned short;
using u32_t = unsigned int;
using u64_t = unsigned long;

using lpstr_t = s8_t *;
using lpcstr_t = const s8_t *;

NAMESPACE_END(sway)

#endif
