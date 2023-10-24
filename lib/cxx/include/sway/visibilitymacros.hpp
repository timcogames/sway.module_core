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

#undef EXPORT_API
#ifdef MODULE_CORE_EXPORT_API
#  if defined(EMSCRIPTEN_PLATFORM)
#    include <emscripten.h>
#    define EXPORT_API EMSCRIPTEN_KEEPALIVE
#  else
#    define EXPORT_API PUBLIC_ATTRIB
#  endif
#else
#  define EXPORT_API
#endif

#endif  // SWAY_VISIBILITYMACROS_HPP
