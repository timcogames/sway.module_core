#ifndef SWAY_NUMERALTYPES_HPP
#define SWAY_NUMERALTYPES_HPP

#include <sway/namespacemacros.hpp>

#include <stdint.h>

NAMESPACE_BEGIN(sway)

using i8_t = int8_t;  // Signed 8-bit integer
using i16_t = int16_t;  // Signed 16-bit integer
using i32_t = int32_t;  // Signed 32-bit integer
using i64_t = int64_t;  // Signed 64-bit integer

using u8_t = uint8_t;  // Unsigned 8-bit integer
using u16_t = uint16_t;  // Unsigned 16-bit integer
using u32_t = uint32_t;  // Unsigned 32-bit integer
using u64_t = uint64_t;  // Unsigned 64-bit integer

using f32_t = float;  // 32-bit floating point
using f64_t = double;  // 64-bit floating point

NAMESPACE_END(sway)

#endif  // SWAY_NUMERALTYPES_HPP
