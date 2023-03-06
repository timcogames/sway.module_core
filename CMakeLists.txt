# Проверяем версию CMake
cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmakehelpers/custom_enable_cxx17.cmake")

# Мета-информация о проекте
set(META_CORE_PRJNAME "module_core")
set(META_CORE_LIBNAME "lib${META_CORE_PRJNAME}")
set(META_CORE_VERSION_MAJOR 0)
set(META_CORE_VERSION_MINOR 1)
set(META_CORE_VERSION_PATCH 0)
set(META_CORE_VERSION ${META_CORE_VERSION_MAJOR}.${META_CORE_VERSION_MINOR}.${META_CORE_VERSION_PATCH})

# Опции сборки
option(MODULE_CORE_SHARED_LIB "Build shared library (.so)" OFF)
option(MODULE_CORE_ENABLE_COVERAGE "Enable coverage builds" OFF)
option(MODULE_CORE_ENABLE_TESTS "Enable test builds" OFF)
option(GLOBAL_EMSCRIPTEN_PLATFORM "Using emscripten compiler" OFF)
option(GLOBAL_EMSCRIPTEN_USE_BINDING "Using emscripten binding" OFF)
option(CUSTOM_EMSCRIPTEN_ROOT_DIR "Emscripten root directory" OFF)
option(CUSTOM_BOOST_ROOT_DIR "Boost root directory" OFF)
option(CUSTOM_GTEST_ROOT_DIR "GTest root directory" OFF)

set(CMAKE_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk")

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE AND GLOBAL_EMSCRIPTEN_PLATFORM)
  set(CMAKE_TOOLCHAIN_FILE "${CUSTOM_EMSCRIPTEN_ROOT_DIR}/cmake/Modules/Platform/Emscripten.cmake")
  include(${CMAKE_TOOLCHAIN_FILE})
endif ()

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build" FORCE)
endif ()

project(${META_CORE_PRJNAME} VERSION ${META_CORE_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC" )

if (GLOBAL_EMSCRIPTEN_PLATFORM)
  set(CMAKE_CXX_COMPILER "${CUSTOM_EMSCRIPTEN_ROOT_DIR}/em++")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --bind -Os -std=c++17")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-unicode-whitespace \
      -Wno-unused-local-typedef -Wno-invalid-noreturn -Wno-unused-command-line-argument")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEMSCRIPTEN_PLATFORM")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEMSCRIPTEN_PLATFORM_USE_BINDING")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s WASM=1 -s MODULARIZE=1")
endif ()

if (MODULE_CORE_ENABLE_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftest-coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif ()

message("[${META_CORE_PRJNAME}]: ${META_CORE_VERSION}
         compiler | ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}
       build type | ${CMAKE_BUILD_TYPE}
       shared lib | ${MODULE_CORE_SHARED_LIB}
         cxxflags | ${CMAKE_CXX_FLAGS} ${EXTRA_FLAGS}
 build type flags | ${BUILD_TYPE_CXX_FLAGS}
        build dir | ${CMAKE_BINARY_DIR}
   install prefix | ${CMAKE_INSTALL_PREFIX}

   emscripten dir | ${CUSTOM_EMSCRIPTEN_ROOT_DIR}
        boost dir | ${CUSTOM_BOOST_ROOT_DIR}
        gtest dir | ${CUSTOM_GTEST_ROOT_DIR}

       emscripten | ${GLOBAL_EMSCRIPTEN_PLATFORM}
         coverage | ${MODULE_CORE_ENABLE_COVERAGE}
            tests | ${MODULE_CORE_ENABLE_TESTS}
")

# Определяем каталог вывода по умолчанию
if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/dbg")
  set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/dbg")
else ()
  set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")
  set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")
endif ()

set(MODULE_CORE_DIR ${CMAKE_CURRENT_LIST_DIR})

# Добавляем пути для поиска хедеров
include_directories("${CUSTOM_EMSCRIPTEN_ROOT_DIR}/cache/sysroot/include")
include_directories("${MODULE_CORE_DIR}/lib/include")

# Получаем пути ко всем хедерам и исходникам библиотеки
file(GLOB_RECURSE MODULE_CORE_HEADERS "${MODULE_CORE_DIR}/lib/include/*.*")
file(GLOB_RECURSE MODULE_CORE_SOURCE "${MODULE_CORE_DIR}/lib/src/*.*")

if (MODULE_CORE_SHARED_LIB)
    add_executable(${META_CORE_LIBNAME} ${MODULE_CORE_SOURCE})
    set_target_properties(${META_CORE_LIBNAME} PROPERTIES OUTPUT_NAME ${META_CORE_PRJNAME})
    set_target_properties(${META_CORE_LIBNAME} PROPERTIES SUFFIX ".${META_CORE_VERSION}.js")
else ()
    add_library(${META_CORE_LIBNAME} STATIC ${MODULE_CORE_SOURCE})
    set_target_properties(${META_CORE_LIBNAME} PROPERTIES OUTPUT_NAME ${META_CORE_PRJNAME})
    set_target_properties(${META_CORE_LIBNAME} PROPERTIES SUFFIX ".a.${META_CORE_VERSION}")
endif ()

custom_enable_cxx17(${META_CORE_LIBNAME})
target_link_libraries(${META_CORE_LIBNAME})

# Добавляем построение тестов
if (MODULE_CORE_ENABLE_TESTS)
  if (MODULE_CORE_SHARED_LIB)
    message(STATUS "[${META_CORE_PRJNAME}]: Tests are only allowed with a static lib")
  else ()
    message(STATUS "[${META_CORE_PRJNAME}]:Tests have been enabled")
    add_subdirectory(lib/tests/google)
  endif ()
endif ()
