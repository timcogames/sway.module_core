#---------------------------------------------------------------------------------
# CMake version
#---------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

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
include("${MODULE_CORE_CMAKE_DIR}/modules/create_object.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/create_interface.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/logger.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/compiler/clang/create_library.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/compiler/emscripten/setup.cmake")
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

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  include_directories("/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include")
endif()

include_directories("${MODULE_CORE_LIST_DIR}/lib/cxx/include")

#---------------------------------------------------------------------------------
# [EMSCRIPTEN] Bitcode
#---------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,-no-whole-archive")

  # create_bitcode_library(${MODULE_CORE_TARGET} ${MODULE_CORE_PROJ_NAME} "${MODULE_CORE_ROOT_DIR}/lib/cxx/src/*.*")
  create_object(${MODULE_CORE_TARGET} "${MODULE_CORE_ROOT_DIR}/lib/cxx/src/*.*")
else()
  if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_CXX_COMPILER "/Library/Developer/CommandLineTools/usr/bin/clang")
  endif()

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
