# Проверяем версию CMake
cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

# Устанавливаем имя проекта/библиотеки
set(MODULE_CORE_NAME module_core)
set(MODULE_CORE_LIB_NAME lib${MODULE_CORE_NAME})
project(${MODULE_CORE_NAME} C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Флаги сборки
option(BUILD_SHARED "Build shared library" OFF)
option(ENABLE_COVERAGE "Enable coverage builds" OFF)
option(ENABLE_EXAMPLES "Enable example builds" OFF)
option(ENABLE_TESTS "Enable test builds" OFF)

# Устанавливаем версию библиотеки
set(MODULE_CORE_VERSION_MAJOR 0)
set(MODULE_CORE_VERSION_MINOR 1)
set(MODULE_CORE_VERSION_PATCH 0)
set(MODULE_CORE_VERSION_STRING ${MODULE_CORE_VERSION_MAJOR}.${MODULE_CORE_VERSION_MINOR}.${MODULE_CORE_VERSION_PATCH})

if(ENABLE_COVERAGE)
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

if(BUILD_SHARED)
	# Добавляем в проект цель для сборки статической библиотеки
	add_library(${MODULE_CORE_LIB_NAME} SHARED ${MODULE_CORE_SOURCE})
	set_target_properties(${MODULE_CORE_LIB_NAME} PROPERTIES OUTPUT_NAME ${MODULE_CORE_NAME})
	set_target_properties(${MODULE_CORE_LIB_NAME} PROPERTIES PREFIX "")
	set_target_properties(${MODULE_CORE_LIB_NAME} PROPERTIES SUFFIX ".so.${MODULE_CORE_VERSION_STRING}")
else()
	# Добавляем в проект цель для сборки динамической библиотеки
	add_library(${MODULE_CORE_LIB_NAME} STATIC ${MODULE_CORE_SOURCE})
	set_target_properties(${MODULE_CORE_LIB_NAME} PROPERTIES OUTPUT_NAME ${MODULE_CORE_NAME})
	set_target_properties(${MODULE_CORE_LIB_NAME} PROPERTIES PREFIX "")
	set_target_properties(${MODULE_CORE_LIB_NAME} PROPERTIES SUFFIX ".a.${MODULE_CORE_VERSION_STRING}")
endif()

# Добавляем построение тестов
if(ENABLE_TESTS)
	message(STATUS "Tests have been enabled")
	add_subdirectory(tests)
endif()
