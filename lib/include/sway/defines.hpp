#ifndef SWAY_DEFINES_HPP
#define SWAY_DEFINES_HPP

#define DONT_CARE (-1)

#define STRINGIFY_HELPER(x) #x
#define STRINGIFY(x) STRINGIFY_HELPER(x)

#define ENUM_BITMASK(x) (1 << (x))

#endif  // SWAY_DEFINES_HPP
