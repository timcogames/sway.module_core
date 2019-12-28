#ifndef _SWAY_DEFINES_H
#define _SWAY_DEFINES_H

#define DONT_CARE (-1)

#define STRINGIFY_HELPER(x) #x
#define STRINGIFY(x) STRINGIFY_HELPER(x)

#define ENUM_BITMASK(x) (1 << x)

#endif // _SWAY_DEFINES_H
