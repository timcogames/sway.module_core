#_________________________________________________________________________________
#                                                                    CMake version
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

#_________________________________________________________________________________
#                                                              Project directories
set(MODULE_CORE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MODULE_CORE_LIST_DIR ${CMAKE_CURRENT_LIST_DIR})
set(MODULE_CORE_CMAKE_DIR ${MODULE_CORE_ROOT_DIR}/cmakehelpers)
set(MODULE_CORE_LIB_DIR ${MODULE_CORE_ROOT_DIR}/lib)
set(MODULE_CORE_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

#_________________________________________________________________________________
#                                                            Include CMake modules
include("${MODULE_CORE_CMAKE_DIR}/options.cmake")
include("${MODULE_CORE_CMAKE_DIR}/set_output_dir.cmake")
include("${MODULE_CORE_CMAKE_DIR}/project_metadata.cmake")
# include("${MODULE_CORE_CMAKE_DIR}/emscripten/compiler.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/logger.cmake")

include("${MODULE_CORE_CMAKE_DIR}/modules/compiler/clang/create_library.cmake")

include("${MODULE_CORE_CMAKE_DIR}/modules/compiler/emscripten/setup.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/compiler/emscripten/create_bitcode.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/compiler/emscripten/create_library.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/compiler/emscripten/gen_target_name.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/compiler/emscripten/set_optimization.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/compiler/emscripten/set_environment.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/compiler/emscripten/set_compilation.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/compiler/emscripten/set_modularize.cmake")
# include("${MODULE_CORE_CMAKE_DIR}/emscripten/compiler_flags/set_optimization.cmake")
# include("${MODULE_CORE_CMAKE_DIR}/emscripten/compiler_flags/set_config.cmake")
# include("${MODULE_CORE_CMAKE_DIR}/emscripten/compiler_flags/set_exports.cmake")
# include("${MODULE_CORE_CMAKE_DIR}/detect_library_extension.cmake")
# include("${MODULE_CORE_CMAKE_DIR}/create_library.cmake")
include("${MODULE_CORE_CMAKE_DIR}/enable_cxx17.cmake")
include("${MODULE_CORE_CMAKE_DIR}/enable_coverage.cmake")

# set(CMAKE_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk")

#_________________________________________________________________________________
#                                                                    Build options
option(MODULE_CORE_SHARED_LIB "Build shared library" OFF)
option(MODULE_CORE_ENVIRONMENT "Environment variable" OFF)
option(MODULE_CORE_COMPILATION "Compilation variable" OFF)
option(MODULE_CORE_ENABLE_COVERAGE "Enable coverage builds" OFF)
option(MODULE_CORE_ENABLE_TESTS "Enable test builds" OFF)

#_________________________________________________________________________________
#                                                              [EMSCRIPTEN]: Setup
if(GLOB_EMSCRIPTEN_PLATFORM)
  emscripten_setup()
endif()

#_________________________________________________________________________________
#                                                                          Project
project_metadata("core" 0.2.6)
project(${MODULE_CORE_PROJ_NAME} VERSION ${MODULE_CORE_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=default -fPIE")

# if(GLOB_EMSCRIPTEN_PLATFORM)
#   set(CMAKE_CXX_COMPILER "${EMSCRIPTEN_COMPILER}")
#   # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--whole-archive")
#   # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-unicode-whitespace \
#   #   -Wno-unused-local-typedef -Wno-invalid-noreturn -Wno-unused-command-line-argument")
# endif()

# if((GLOB_EMSCRIPTEN_PLATFORM AND NOT GLOB_EMSCRIPTEN_USE_BINDINGS) OR MODULE_CORE_SHARED_LIB)
#   add_definitions(-DMODULE_CORE_EXPORT_API)
#   # target_compile_definitions(${MODULE_CORE_TARGET} PUBLIC -DMODULE_CORE_EXPORT_API)
# endif()

#_________________________________________________________________________________
#                                                                         Coverage
if(MODULE_CORE_ENABLE_COVERAGE)
  enable_coverage()
endif()

create_logger()

#_________________________________________________________________________________
#                                                           Executable output path
set_output_dir(${MODULE_CORE_BIN_DIR})

#_________________________________________________________________________________
#                                                          Include project headers
include_directories("${MODULE_CORE_LIST_DIR}/lib/cxx/include")

#_________________________________________________________________________________
#                                                             [EMSCRIPTEN] Bitcode
if(GLOB_EMSCRIPTEN_PLATFORM)
  # create_bitcode_library(${MODULE_CORE_TARGET} ${MODULE_CORE_PROJ_NAME} "${MODULE_CORE_ROOT_DIR}/lib/cxx/src/*.*")
  create_bitcode(${MODULE_CORE_TARGET} "${MODULE_CORE_ROOT_DIR}/lib/cxx/src/*.*")
else()
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc")
  create_library(${MODULE_CORE_TARGET} "${MODULE_CORE_ROOT_DIR}/lib/cxx/src/*.*")
endif()

enable_cxx17(${MODULE_CORE_TARGET})

#_________________________________________________________________________________
#                                                                      Definitions
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_definitions(${MODULE_CORE_TARGET} PUBLIC -DMODULE_CORE_DEBUG_BUILD)
endif()

if((GLOB_EMSCRIPTEN_PLATFORM AND NOT GLOB_EMSCRIPTEN_USE_BINDINGS) OR MODULE_CORE_SHARED_LIB)
  target_compile_definitions(${MODULE_CORE_TARGET} PUBLIC -DMODULE_CORE_EXPORT_API)
endif()

#_________________________________________________________________________________
#                                                                           Logger
printf_compiler_name(${MODULE_CORE_TARGET})
printf_compile_definitions(${MODULE_CORE_TARGET})
message("[module_core]: arch=${CMAKE_HOST_SYSTEM_PROCESSOR}")

#_________________________________________________________________________________
#                                                                  Build libraries
if(GLOB_EMSCRIPTEN_PLATFORM)
  create_emscripten_library(${MODULE_CORE_TARGET} ${MODULE_CORE_ENVIRONMENT} ${MODULE_CORE_COMPILATION} OUTPUT_TARGET_NAME_LIST)

  foreach(target IN LISTS OUTPUT_TARGET_NAME_LIST)
    target_link_options(${target} PUBLIC 
      "SHELL:-s STRICT=1"
      "SHELL:-s MODULARIZE=1"
      "SHELL:-s EXPORT_NAME=\"create_core_module\""
      "SHELL:-s EXPORTED_FUNCTIONS=@${MODULE_CORE_LIB_DIR}/exports.json"
      "SHELL:-s EXPORTED_RUNTIME_METHODS=@${MODULE_CORE_LIB_DIR}/runtime_exports.json")
    printf_link_options(${target})
  endforeach()
else()
  # create_library(${MODULE_CORE_TARGET} "${MODULE_CORE_ROOT_DIR}/lib/cxx/src/*.*")
endif()

# if(GLOB_EMSCRIPTEN_PLATFORM)
#   set(LIB_NAME_LIST ${MODULE_CORE_LIB_NAME})

#   emscripten_set_compiler_javascript(#[[CONFIG_NAME]] MODULE_CORE_COMPILER_WEBJS_CONFIG
#     #[[BINARY_DIR]] ${MODULE_CORE_BIN_DIR} #[[LIB_NAME_LIST]] LIB_NAME_LIST #[[VERSION]] ${MODULE_CORE_VERSION})
#   emscripten_set_config(#[[PROJ_NAME]] ${MODULE_CORE_PROJ_NAME} #[[CONFIG_NAME]] MODULE_CORE_COMPILER_WEBJS_CONFIG)
#   emscripten_set_exports(#[[CONFIG]] MODULE_CORE_COMPILER_WEBJS_CONFIG #[[JSON_FILE]] ${MODULE_CORE_LIB_DIR}/exports.json)
#   emscripten_set_runtime_exports(#[[CONFIG]] MODULE_CORE_COMPILER_WEBJS_CONFIG #[[JSON_FILE]] ${MODULE_CORE_LIB_DIR}/runtime_exports.json 0)

#   add_custom_command(TARGET ${MODULE_CORE_TARGET} POST_BUILD
#     COMMAND ${MODULE_CORE_COMPILER_WEBJS_CONFIG}

#     # COMMAND rm "${MODULE_CORE_BIN_DIR}/${MODULE_CORE_LIB_NAME}.bc"
#   )
# endif()

#_________________________________________________________________________________
#                                                                            Tests
if(MODULE_CORE_ENABLE_TESTS)
  if(MODULE_CORE_SHARED_LIB)
    message(STATUS "[${MODULE_CORE_PROJ_NAME}]: Tests are only allowed with a static lib")
  else()
    message(STATUS "[${MODULE_CORE_PROJ_NAME}]:Tests have been enabled")
    add_subdirectory(lib/cxx/tests/google)
  endif()
endif()
