# Мета-информация о проекте
set(META_CORE_PROJNAME_TESTS module_core_tests)
set(META_CORE_LIBNAME_TESTS lib${META_CORE_PROJNAME_TESTS})

project(${META_CORE_PROJNAME_TESTS} C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BOOST_USE_STATIC_LIBS ON)
set(BOOST_NO_SYSTEM_PATHS TRUE)

set(Boost_INCLUDE_DIR "${BOOST_ROOT}")

find_package(Boost 1.78.0 REQUIRED COMPONENTS ${BOOST_COMPONENTS})
if(NOT BOOST_FOUND)
	message(FATAL_ERROR "Fatal error: Boost (version >= 1.78.0) required.")
else()
	message(STATUS "Boost includes: ${Boost_INCLUDE_DIR}")
	include_directories(${Boost_INCLUDE_DIR})
endif()

# Получаем пути ко всем исходникам с тестами
file(GLOB MODULE_CORE_SOURCE_TESTS ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(${META_CORE_LIBNAME_TESTS} ${MODULE_CORE_SOURCE_TESTS})

target_include_directories(${META_CORE_LIBNAME_TESTS} PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(${META_CORE_LIBNAME_TESTS} libmodule_core ${BOOST_LIBRARIES} ${CMAKE_DL_LIBS})

add_custom_command(TARGET ${META_CORE_LIBNAME_TESTS} POST_BUILD COMMAND ${META_CORE_LIBNAME_TESTS})
