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
  # sudo ln -s /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/* /Library/Developer/CommandLineTools/usr/include/c++/v1
  # sudo ln -s /usr/local/include/c++/v1/* /Library/Developer/CommandLineTools/usr/include/c++/v1

  # include_directories("/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include")
  include_directories("/usr/local/include/c++/v1")
endif()

include_directories("${MODULE_CORE_LIST_DIR}/lib/cxx/include")

#--------------------------------------------------------------------------------
# Build object library
#
# Создаём объектную библиотеку в зависимости от MODULE_CORE_ENABLE_EMBINDS:
#
#   MODULE_CORE_ENABLE_EMBINDS=ON
#     - Создаётся одна объектная библиотека module_core_obj,
#       в которую попадает _embinds.cpp.
#     - Bindings core компилируются вместе с логикой core.
#
#   MODULE_CORE_ENABLE_EMBINDS=OFF
#     - Создаётся module_core_obj БЕЗ _embinds.cpp (EXCLUDE).
#     - Создаётся отдельная объектная библиотека module_core_obj_bindings,
#       содержащая только _embinds.cpp.
#     - Bindings core компилируются отдельно, чтобы потребитель мог
#       подключить их ровно один раз в свой финальный Wasm-модуль.
#--------------------------------------------------------------------------------

if(NOT TARGET ${MODULE_CORE_OBJ_TARGET})
  set(MODULE_CORE_LIB_SOURCES "${MODULE_CORE_LIB_DIR}/cxx/src")

  if(MODULE_CORE_ENABLE_EMBINDS)
    create_object_library(${MODULE_CORE_OBJ_TARGET} ${MODULE_CORE_LIB_SOURCES} EXPORT)
  else()
    # Логика core без _embinds.cpp
    create_object_library(${MODULE_CORE_OBJ_TARGET} ${MODULE_CORE_LIB_SOURCES} EXPORT EXCLUDE "_embinds.cpp")

    # Только bindings core
    set(MODULE_CORE_BINDINGS_OBJ_TARGET "${MODULE_CORE_OBJ_TARGET}_bindings")
    if(NOT TARGET ${MODULE_CORE_BINDINGS_OBJ_TARGET})
      create_object_library(${MODULE_CORE_BINDINGS_OBJ_TARGET} "${MODULE_CORE_LIB_DIR}/cxx/src/_embinds.cpp" EXPORT)
      enable_cxx17(${MODULE_CORE_BINDINGS_OBJ_TARGET})
    endif()
  endif()

  enable_cxx17(${MODULE_CORE_OBJ_TARGET})
endif()

#--------------------------------------------------------------------------------
# Unified interface
#
# module_core_iface — единственная точка входа для потребителей.
#
# Интерфейс уже содержит:
#   - объекты логики core (module_core_obj)
#   - объекты bindings core (module_core_obj_bindings), если они вынесены
#--------------------------------------------------------------------------------

set(MODULE_CORE_IFACE_TARGET "module_core_iface")

if(NOT TARGET ${MODULE_CORE_IFACE_TARGET})
  set(MODULE_CORE_IFACE_OBJECTS $<TARGET_OBJECTS:${MODULE_CORE_OBJ_TARGET}>)

  if(NOT MODULE_CORE_ENABLE_EMBINDS)
    if(NOT TARGET ${MODULE_CORE_BINDINGS_OBJ_TARGET})
      message(FATAL_ERROR "[module_core]: ${MODULE_CORE_BINDINGS_OBJ_TARGET} not found")
    endif()
    list(APPEND MODULE_CORE_IFACE_OBJECTS $<TARGET_OBJECTS:${MODULE_CORE_BINDINGS_OBJ_TARGET}>)
  endif()

  create_interface(${MODULE_CORE_IFACE_TARGET} ${MODULE_CORE_IFACE_OBJECTS})
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
