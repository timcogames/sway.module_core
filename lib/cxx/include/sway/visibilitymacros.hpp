#ifndef SWAY_VISIBILITYMACROS_HPP
#define SWAY_VISIBILITYMACROS_HPP

#ifdef __cplusplus
#  define EXTERN_C extern "C"
#  define EXTERN_C_BEGIN EXTERN_C {
#  define EXTERN_C_END }
#else
#  define EXTERN_C
#  define EXTERN_C_BEGIN
#  define EXTERN_C_END
#endif

#define PUBLIC_ATTRIB __attribute__((visibility("default")))
#define HIDDEN_ATTRIB __attribute__((visibility("hidden")))

#endif  // SWAY_VISIBILITYMACROS_HPP
