# Проверяем версию CMake
cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

set(MODULE_CORE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MODULE_CORE_CMAKE_DIR ${MODULE_CORE_ROOT_DIR}/cmakehelpers)
set(MODULE_CORE_BINARY_DIR ${MODULE_CORE_ROOT_DIR}/bin)

include("${MODULE_CORE_CMAKE_DIR}/options.cmake")
include("${MODULE_CORE_CMAKE_DIR}/set_output_dir.cmake")
include("${MODULE_CORE_CMAKE_DIR}/project_metadata.cmake")
include("${MODULE_CORE_CMAKE_DIR}/emscripten/setup.cmake")
include("${MODULE_CORE_CMAKE_DIR}/emscripten/compiler.cmake")
include("${MODULE_CORE_CMAKE_DIR}/emscripten/compiler_flags/set_config.cmake")
include("${MODULE_CORE_CMAKE_DIR}/emscripten/compiler_flags/set_exports.cmake")
include("${MODULE_CORE_CMAKE_DIR}/detect_library_extension.cmake")
include("${MODULE_CORE_CMAKE_DIR}/create_library.cmake")
include("${MODULE_CORE_CMAKE_DIR}/enable_cxx17.cmake")
include("${MODULE_CORE_CMAKE_DIR}/enable_coverage.cmake")

set(CMAKE_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk")

# Опции сборки
option(MODULE_CORE_SHARED_LIB "Build shared library (.dylib|.so)" OFF)
option(MODULE_CORE_ENABLE_COVERAGE "Enable coverage builds" OFF)
option(MODULE_CORE_ENABLE_TESTS "Enable test builds" OFF)

if(GLOB_EMSCRIPTEN_PLATFORM)
  emscripten_setup()
endif()

project_metadata("core" 0.1.0)
project(${MODULE_CORE_PROJ_NAME} VERSION ${MODULE_CORE_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=default -fPIE")

if(GLOB_EMSCRIPTEN_PLATFORM)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --no-entry")

  set(CMAKE_CXX_COMPILER "${EMSCRIPTEN_COMPILER}")
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--whole-archive")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-unicode-whitespace \
    -Wno-unused-local-typedef -Wno-invalid-noreturn -Wno-unused-command-line-argument")
endif()

if(MODULE_CORE_ENABLE_COVERAGE)
  enable_coverage()
endif()

# set(CMAKE_OSX_ARCHITECTURES "arm64")

# message("ARH ${CMAKE_CXX_PLATFORM_ID}")
# message("${EMSCRIPTEN_GENERATE_BITCODE_STATIC_LIBRARIES}")
# message("${CMAKE_STATIC_LIBRARY_SUFFIX}")

message("[${MODULE_CORE_PROJ_NAME}]: ${META_CORE_VERSION}
           system | ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION}
         platform | ${CMAKE_CXX_PLATFORM_ID}
         compiler | ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}
       build type | ${CMAKE_BUILD_TYPE}
       shared lib | ${MODULE_CORE_SHARED_LIB}
         cxxflags | ${CMAKE_CXX_FLAGS} ${EXTRA_FLAGS}
 build type flags | ${BUILD_TYPE_CXX_FLAGS}
        build dir | ${CMAKE_BINARY_DIR}
   install prefix | ${CMAKE_INSTALL_PREFIX}

   emscripten dir | ${GLOB_EMSCRIPTEN_ROOT_DIR}
        boost dir | ${GLOB_BOOST_ROOT_DIR}
        gtest dir | ${GLOB_GTEST_ROOT_DIR}

       emscripten | ${GLOB_EMSCRIPTEN_PLATFORM}
         coverage | ${MODULE_CORE_ENABLE_COVERAGE}
            tests | ${MODULE_CORE_ENABLE_TESTS}
")

# Определяем каталог вывода по умолчанию
set_output_dir("${CMAKE_SOURCE_DIR}/bin")

set(MODULE_CORE_DIR ${CMAKE_CURRENT_LIST_DIR})

# Добавляем пути для поиска хедеров
include_directories("${MODULE_CORE_DIR}/lib/include")

# Получаем пути ко всем хедерам и исходникам библиотеки
file(GLOB_RECURSE MODULE_CORE_HEADERS "${MODULE_CORE_DIR}/lib/include/*.*")
file(GLOB_RECURSE MODULE_CORE_SOURCES "${MODULE_CORE_DIR}/lib/src/*.*")

create_bitcode_library(#[[TARGET_NAME]] ${MODULE_CORE_PROJ_NAME} #[[SOURCE_DIR]] "${MODULE_CORE_ROOT_DIR}/lib/src/*.*")
enable_cxx17(${MODULE_CORE_PROJ_NAME})

if(GLOB_EMSCRIPTEN_PLATFORM)
  emscripten_set_compiler_javascript(#[[CONFIG_NAME]] MODULE_CORE_COMPILER_WEBJS_CONFIG
    #[[BINARY_DIR]] ${MODULE_CORE_BINARY_DIR} #[[IO_LIBNAME]] ${MODULE_CORE_LIB_NAME} #[[VERSION]] ${MODULE_CORE_VERSION})
  emscripten_set_config(#[[TARGET_NAME]] ${MODULE_CORE_PROJ_NAME} #[[CONFIG_NAME]] MODULE_CORE_COMPILER_WEBJS_CONFIG)
  emscripten_set_exports(#[[CONFIG]] MODULE_CORE_COMPILER_WEBJS_CONFIG #[[JSON_FILE]] ${MODULE_CORE_BINARY_DIR}/exports.json)
  emscripten_set_runtime_exports(#[[CONFIG]] MODULE_CORE_COMPILER_WEBJS_CONFIG #[[JSON_FILE]] ${MODULE_CORE_BINARY_DIR}/runtime_exports.json)

  # message("FLAGS ${EMSCRIPTEN_COMPILER_FLAGS}")
  message("CONFIG ${MODULE_CORE_COMPILER_WEBJS_CONFIG}")

  add_custom_command(TARGET ${MODULE_CORE_PROJ_NAME} POST_BUILD
    COMMAND #${EMSCRIPTEN_COMPILER}
      ${MODULE_CORE_COMPILER_WEBJS_CONFIG}
      # ${EMSCRIPTEN_COMPILER_FLAGS}
      --no-entry
  )
endif()

# Добавляем построение тестов
if(MODULE_CORE_ENABLE_TESTS)
  if(MODULE_CORE_SHARED_LIB)
    message(STATUS "[${MODULE_CORE_PROJ_NAME}]: Tests are only allowed with a static lib")
  else()
    message(STATUS "[${MODULE_CORE_PROJ_NAME}]:Tests have been enabled")
    add_subdirectory(lib/tests/google)
  endif()
endif()
