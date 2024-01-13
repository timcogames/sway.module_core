#--------------------------------------------------------------------------------
# CMake version
#--------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

#--------------------------------------------------------------------------------
# Project directories
#--------------------------------------------------------------------------------

set(MODULE_CORE_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(MODULE_CORE_LIST_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(MODULE_CORE_CMAKE_DIR "${MODULE_CORE_ROOT_DIR}/cmake_modules")
set(MODULE_CORE_LIB_DIR "${MODULE_CORE_ROOT_DIR}/lib")
set(MODULE_CORE_BIN_DIR "${CMAKE_SOURCE_DIR}/bin")

#--------------------------------------------------------------------------------
# Include CMake modules
#--------------------------------------------------------------------------------

include("${MODULE_CORE_CMAKE_DIR}/options.cmake")
include("${MODULE_CORE_CMAKE_DIR}/project_metadata.cmake")
include("${MODULE_CORE_CMAKE_DIR}/set_output_dir.cmake")
include("${MODULE_CORE_CMAKE_DIR}/set_compile_definitions.cmake")
include("${MODULE_CORE_CMAKE_DIR}/enable_cxx17.cmake")
include("${MODULE_CORE_CMAKE_DIR}/enable_coverage.cmake")
include("${MODULE_CORE_CMAKE_DIR}/modules/create_object_library.cmake")
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

#--------------------------------------------------------------------------------
# Options
#--------------------------------------------------------------------------------

set_glob_options()

option(MODULE_CORE_LIB_TYPE "Build type library" OFF)
option(MODULE_CORE_ALL_EXPORT "" OFF)
option(MODULE_CORE_ENVIRONMENT "Environment variable" OFF)
option(MODULE_CORE_COMPILATION "Compilation variable" OFF)
option(MODULE_CORE_ENABLE_COVERAGE "Enable coverage builds" OFF)
option(MODULE_CORE_ENABLE_TESTS "Enable test builds" OFF)

#--------------------------------------------------------------------------------
# [EMSCRIPTEN]: Setup
#--------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  emscripten_setup()
endif()

#--------------------------------------------------------------------------------
# Project
#--------------------------------------------------------------------------------

project_metadata("core" 0.2.6)
project(${MODULE_CORE_PROJ_NAME} VERSION ${MODULE_CORE_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=default -fPIE")

#--------------------------------------------------------------------------------
# Coverage
#--------------------------------------------------------------------------------

if(MODULE_CORE_ENABLE_COVERAGE)
  enable_coverage()
endif()

create_logger()

#--------------------------------------------------------------------------------
# Executable output path
#--------------------------------------------------------------------------------

set_output_dir(${MODULE_CORE_BIN_DIR})

#--------------------------------------------------------------------------------
# Library
#--------------------------------------------------------------------------------

add_subdirectory(lib/cxx)

#--------------------------------------------------------------------------------
# Tests
#--------------------------------------------------------------------------------

if(MODULE_CORE_ENABLE_TESTS)
  if(${MODULE_CORE_LIB_TYPE} MATCHES "static")
    message(STATUS "[${MODULE_CORE_PROJ_NAME}]: Tests have been enabled")
    add_subdirectory(lib/cxx/tests/google)
    # add_dependencies(module_core_tests module_core)
  else()
    message(FATAL_ERROR "[${MODULE_CORE_PROJ_NAME}]: Tests are only allowed with a static lib")
  endif()
endif()
