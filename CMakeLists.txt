#---------------------------------------------------------------------------------
# CMake version
#---------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

#---------------------------------------------------------------------------------
# Project directories
#---------------------------------------------------------------------------------

set(MODULE_CORE_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(MODULE_CORE_LIST_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(MODULE_CORE_CMAKE_DIR "${MODULE_CORE_ROOT_DIR}/cmake_modules")
set(MODULE_CORE_LIB_DIR "${MODULE_CORE_ROOT_DIR}/lib")
set(MODULE_CORE_BIN_DIR "${CMAKE_SOURCE_DIR}/bin")

#---------------------------------------------------------------------------------
# Include CMake modules
#---------------------------------------------------------------------------------

include("${MODULE_CORE_CMAKE_DIR}/options.cmake")
include("${MODULE_CORE_CMAKE_DIR}/project_metadata.cmake")
include("${MODULE_CORE_CMAKE_DIR}/set_output_dir.cmake")
include("${MODULE_CORE_CMAKE_DIR}/set_compile_definitions.cmake")
include("${MODULE_CORE_CMAKE_DIR}/enable_cxx17.cmake")
include("${MODULE_CORE_CMAKE_DIR}/enable_coverage.cmake")
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

#---------------------------------------------------------------------------------
# Build options
#---------------------------------------------------------------------------------

option(MODULE_CORE_BUILD_TYPE "" "module") # module, bitcode
option(MODULE_CORE_SHARED_LIB "Build shared library" OFF)
option(MODULE_CORE_ENVIRONMENT "Environment variable" OFF)
option(MODULE_CORE_COMPILATION "Compilation variable" OFF)
option(MODULE_CORE_ENABLE_COVERAGE "Enable coverage builds" OFF)
option(MODULE_CORE_ENABLE_TESTS "Enable test builds" OFF)

#---------------------------------------------------------------------------------
# [EMSCRIPTEN]: Setup
#---------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  emscripten_setup()
endif()

#---------------------------------------------------------------------------------
# Project
#---------------------------------------------------------------------------------

project_metadata("core" 0.2.6)
project(${MODULE_CORE_PROJ_NAME} VERSION ${MODULE_CORE_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=default -fPIE")

#---------------------------------------------------------------------------------
# Coverage
#---------------------------------------------------------------------------------

if(MODULE_CORE_ENABLE_COVERAGE)
  enable_coverage()
endif()

create_logger()

#---------------------------------------------------------------------------------
# Executable output path
#---------------------------------------------------------------------------------

set_output_dir(${MODULE_CORE_BIN_DIR})

#---------------------------------------------------------------------------------
# Include project headers
#---------------------------------------------------------------------------------

include_directories("${MODULE_CORE_LIST_DIR}/lib/cxx/include")

#---------------------------------------------------------------------------------
# [EMSCRIPTEN] Bitcode
#---------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,-no-whole-archive")

  # create_bitcode_library(${MODULE_CORE_TARGET} ${MODULE_CORE_PROJ_NAME} "${MODULE_CORE_ROOT_DIR}/lib/cxx/src/*.*")
  create_bitcode(${MODULE_CORE_TARGET} "${MODULE_CORE_ROOT_DIR}/lib/cxx/src/*.*")
else()
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc")
  create_library(${MODULE_CORE_TARGET} "${MODULE_CORE_ROOT_DIR}/lib/cxx/src/*.*")
endif()

enable_cxx17(${MODULE_CORE_TARGET})

#---------------------------------------------------------------------------------
# Definitions
#---------------------------------------------------------------------------------

set_compile_definitions(${MODULE_CORE_TARGET})

#---------------------------------------------------------------------------------
# Logger
#---------------------------------------------------------------------------------

printf_compiler_name(${MODULE_CORE_TARGET})
printf_compile_definitions(${MODULE_CORE_TARGET})
message("[module_core]: arch=${CMAKE_HOST_SYSTEM_PROCESSOR}")

#---------------------------------------------------------------------------------
# Build libraries
#---------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM AND MODULE_CORE_BUILD_TYPE STREQUAL "module")
  create_emscripten_library(${MODULE_CORE_TARGET} ${MODULE_CORE_ENVIRONMENT} ${MODULE_CORE_COMPILATION} OUTPUT_TARGET_NAME_LIST)

  foreach(target IN LISTS OUTPUT_TARGET_NAME_LIST)
    target_link_options(${target} PUBLIC 
      "SHELL:-s STRICT=1"
      "SHELL:-s MODULARIZE=1"
      "SHELL:-s EXPORT_NAME=\"create_core_module\""
      "SHELL:-s EXPORTED_FUNCTIONS=@${MODULE_CORE_LIB_DIR}/exports.json"
      "SHELL:-s EXPORTED_RUNTIME_METHODS=@${MODULE_CORE_LIB_DIR}/runtime-exports.json")
    printf_link_options(${target})
  endforeach()
else()
  # create_library(${MODULE_CORE_TARGET} "${MODULE_CORE_ROOT_DIR}/lib/cxx/src/*.*")
endif()

# target_compile_options(${MODULE_CORE_TARGET} PRIVATE
#   -O0        # no optimization
#   -g         # generate debug info
#   -fprofile-arcs -ftest-coverage
#   --coverage # sets all required flags
# )
# # set_target_properties(${MODULE_CORE_TARGET} PROPERTIES COMPILE_FLAGS "--coverage")
# # set_target_properties(${MODULE_CORE_TARGET} PROPERTIES LINK_FLAGS "--coverage")
# set_target_properties(${MODULE_CORE_TARGET} PROPERTIES LINK_FLAGS "-lgcov")


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

#---------------------------------------------------------------------------------
# Tests
#---------------------------------------------------------------------------------

if(MODULE_CORE_ENABLE_TESTS)
  if(MODULE_CORE_SHARED_LIB)
    message(STATUS "[${MODULE_CORE_PROJ_NAME}]: Tests are only allowed with a static lib")
  else()
    message(STATUS "[${MODULE_CORE_PROJ_NAME}]:Tests have been enabled")
    add_subdirectory(lib/cxx/tests/google)
  endif()
endif()
