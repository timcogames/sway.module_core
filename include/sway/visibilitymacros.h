#ifndef SWAY_VISIBILITYMACROS_H
#define SWAY_VISIBILITYMACROS_H

#ifdef __cplusplus
#	define EXTERN_C extern "C"
#	define EXTERN_C_BEGIN EXTERN_C {
#	define EXTERN_C_END }
#else
#	define EXTERN_C
#	define EXTERN_C_BEGIN
#	define EXTERN_C_END
#endif

#define PUBLIC_ATTRIBUTE __attribute__((visibility("default")))
#define HIDDEN_ATTRIBUTE __attribute__((visibility("hidden")))

#ifdef BUILD_DLLAPI_LIBMODULE
#	undef  DLLAPI_EXPORT
#	define DLLAPI_EXPORT PUBLIC_ATTRIBUTE
#else
#	undef  DLLAPI_EXPORT
#	define DLLAPI_EXPORT
#endif

#endif // SWAY_VISIBILITYMACROS_H
