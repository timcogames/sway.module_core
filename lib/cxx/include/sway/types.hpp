#ifndef SWAY_TYPES_HPP
#define SWAY_TYPES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/numeraltypes.hpp>

NAMESPACE_BEGIN(sway)

using s8_t = char;

using bool_t = u8_t;
using byte_t = s8_t;

using lpstr_t = s8_t *;
using lpcstr_t = const s8_t *;

NAMESPACE_END(sway)

#endif  // SWAY_TYPES_HPP
