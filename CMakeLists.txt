# Проверяем версию CMake
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmakehelpers/custom_enable_cxx17.cmake)

# Мета-информация о проекте
set(META_CORE_PROJNAME module_core)
set(META_CORE_LIBNAME lib${META_CORE_PROJNAME})
set(META_VERSION_MAJOR 0)
set(META_VERSION_MINOR 1)
set(META_VERSION_PATCH 0)
set(META_VERSION ${META_VERSION_MAJOR}.${META_VERSION_MINOR}.${META_VERSION_PATCH})
set(META_LANGUAGES C CXX)

# Опции сборки
option(BOOST_ROOT "Path to build Boost" OFF)
message("BOOST_ROOT " ${BOOST_ROOT})
option(MODULE_CORE_EMSCRIPTEN "Using emscripten compiler" OFF)
message("MODULE_CORE_EMSCRIPTEN " ${MODULE_CORE_EMSCRIPTEN})
option(MODULE_CORE_ENABLE_COVERAGE "Enable coverage builds" OFF)
message("MODULE_CORE_ENABLE_COVERAGE " ${MODULE_CORE_ENABLE_COVERAGE})
option(MODULE_CORE_ENABLE_TESTS "Enable test builds" OFF)
message("MODULE_CORE_ENABLE_TESTS " ${MODULE_CORE_ENABLE_TESTS})

project(${META_CORE_PROJNAME} VERSION ${META_VERSION} LANGUAGES ${META_LANGUAGES})

if(MODULE_CORE_EMSCRIPTEN)
	set(EMSCRIPTEN_PREFIX "/Users/apriori85/Documents/Third-party/emsdk/upstream/emscripten")
	set(EMSCRIPTEN_TOOLCHAIN_PATH "${EMSCRIPTEN_PREFIX}/system")
	set(CMAKE_CXX_COMPILER "${EMSCRIPTEN_PREFIX}/emcc")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --bind -Os")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_EMSCRIPTEN")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-unicode-whitespace \
		-Wno-unused-local-typedef -Wno-invalid-noreturn -Wno-unused-command-line-argument")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s WASM=1 -s MODULARIZE=1")
endif()

#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MODULE_CORE_ENABLE_COVERAGE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftest-coverage")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Определяем каталог вывода по умолчанию
if(CMAKE_BUILD_TYPE MATCHES Debug)
	set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dbg)
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dbg)
else()
	set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
endif()

set(MODULE_CORE_DIR ${CMAKE_CURRENT_LIST_DIR})

# Добавляем пути для поиска хедеров
include_directories(${MODULE_CORE_DIR}/include)

# Получаем пути ко всем хедерам и исходникам библиотеки
file(GLOB_RECURSE MODULE_CORE_HEADERS ${MODULE_CORE_DIR}/include/*.*)
file(GLOB_RECURSE MODULE_CORE_SOURCE ${MODULE_CORE_DIR}/src/*.*)

if(MODULE_CORE_EMSCRIPTEN)
	add_executable(${META_CORE_LIBNAME} ${MODULE_CORE_SOURCE})
	set_target_properties(${META_CORE_LIBNAME} PROPERTIES OUTPUT_NAME ${META_CORE_PROJNAME})
	set_target_properties(${META_CORE_LIBNAME} PROPERTIES COMPILE_FLAGS "-x c++")
	set_target_properties(${META_CORE_LIBNAME} PROPERTIES PREFIX "")
	set_target_properties(${META_CORE_LIBNAME} PROPERTIES SUFFIX ".${META_VERSION}.js")
else()
	add_library(${META_CORE_LIBNAME} STATIC ${MODULE_CORE_SOURCE})
	set_target_properties(${META_CORE_LIBNAME} PROPERTIES OUTPUT_NAME ${META_CORE_PROJNAME})
	set_target_properties(${META_CORE_LIBNAME} PROPERTIES PREFIX "")
	set_target_properties(${META_CORE_LIBNAME} PROPERTIES SUFFIX ".a.${META_VERSION}")
endif()

custom_enable_cxx17(${META_CORE_LIBNAME})
target_link_libraries(${META_CORE_LIBNAME})

# Добавляем построение тестов
if(MODULE_CORE_ENABLE_TESTS)
	message(STATUS "Tests have been enabled")
	add_subdirectory(tests/boost)
endif()
