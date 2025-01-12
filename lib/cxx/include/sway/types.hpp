#ifndef SWAY_TYPES_HPP
#define SWAY_TYPES_HPP

#include <sway/common/numeraltypes.hpp>

namespace sway {

using s8_t = char;
using utf16_t = u16_t;

using bool_t = u8_t;
using byte_t = s8_t;

using lpstr_t = s8_t *;
using lpcstr_t = const s8_t *;

}  // namespace sway

#endif  // SWAY_TYPES_HPP
