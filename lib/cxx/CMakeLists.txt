#--------------------------------------------------------------------------------
# CMake version
#--------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

#--------------------------------------------------------------------------------
# [EMSCRIPTEN]: Setup
#--------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  emscripten_setup()
endif()

#--------------------------------------------------------------------------------
# Include project headers
#--------------------------------------------------------------------------------

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  include_directories("/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include")
endif()

include_directories("${MODULE_CORE_LIST_DIR}/lib/cxx/include")

#--------------------------------------------------------------------------------
# Build object library
#--------------------------------------------------------------------------------

if(NOT TARGET ${MODULE_CORE_OBJ_TARGET})
  set(MODULE_CORE_LIB_SOURCES "${MODULE_CORE_ROOT_DIR}/lib/cxx/src/*.*")
  set(MODULE_CORE_ENABLE_FILE_EXPORT TRUE)

  create_object_library(${MODULE_CORE_OBJ_TARGET} ${MODULE_CORE_LIB_SOURCES} ${MODULE_CORE_ENABLE_FILE_EXPORT})
  enable_cxx17(${MODULE_CORE_OBJ_TARGET})
endif()

#--------------------------------------------------------------------------------
# Definitions
#--------------------------------------------------------------------------------

set_compile_definitions(${MODULE_CORE_PROJ_NAME} ${MODULE_CORE_OBJ_TARGET})

#--------------------------------------------------------------------------------
# Logger
#--------------------------------------------------------------------------------

printf_compiler_name(${MODULE_CORE_OBJ_TARGET})
printf_compile_definitions(${MODULE_CORE_OBJ_TARGET})
message("[module_core]: arch=${CMAKE_HOST_SYSTEM_PROCESSOR}")

#--------------------------------------------------------------------------------
# Build libraries
#--------------------------------------------------------------------------------

if(NOT MODULE_CORE_LIB_TYPE STREQUAL "object")
  if(GLOB_EMSCRIPTEN_PLATFORM)
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,-no-whole-archive")
    create_emscripten_library(${MODULE_CORE_LIB_TARGET} ${MODULE_CORE_ENVIRONMENT} ${MODULE_CORE_COMPILATION} OUTPUT_TARGET_NAME_LIST)

    foreach(target IN LISTS OUTPUT_TARGET_NAME_LIST)
      target_link_options(${target} PUBLIC 
        "SHELL:-s STRICT=1"
        "SHELL:-s MODULARIZE=1"
        "SHELL:-s EXPORT_NAME=\"create_core_module\""
        "SHELL:-s EXPORTED_RUNTIME_METHODS=@${MODULE_CORE_LIB_DIR}/runtime-exports.json")

      if(NOT GLOB_EMSCRIPTEN_USE_BINDINGS)
        if(MODULE_CORE_ALL_EXPORT)
          target_link_options(${target} PUBLIC "SHELL:-s LINKABLE=1") # Полный экспорт
        else()
          target_link_options(${target} PUBLIC "SHELL:-s EXPORTED_FUNCTIONS=@${MODULE_CORE_LIB_DIR}/exports.json") # Частичный экспорт
        endif()
      endif()

      printf_link_options(${target})
    endforeach()
  else()
    if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
      set(CMAKE_CXX_COMPILER "/Library/Developer/CommandLineTools/usr/bin/clang")
    endif()

    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc")
    create_clang_library(${MODULE_CORE_LIB_TARGET})
  endif()
endif()

# target_compile_options(${MODULE_CORE_LIB_TARGET} PRIVATE
#   -O0        # no optimization
#   -g         # generate debug info
#   -fprofile-arcs -ftest-coverage
#   --coverage # sets all required flags
# )
# # set_target_properties(${MODULE_CORE_LIB_TARGET} PROPERTIES COMPILE_FLAGS "--coverage")
# # set_target_properties(${MODULE_CORE_LIB_TARGET} PROPERTIES LINK_FLAGS "--coverage")
# set_target_properties(${MODULE_CORE_LIB_TARGET} PROPERTIES LINK_FLAGS "-lgcov")
