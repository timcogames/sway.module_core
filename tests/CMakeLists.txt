# Устанавливаем имя проекта/библиотеки
set(MODULE_CORE_TESTS_NAME module_core_tests)
set(MODULE_CORE_TESTS_LIB_NAME lib${MODULE_CORE_TESTS_NAME})
project(${MODULE_CORE_TESTS_NAME} C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(Boost_USE_STATIC_LIBS ON)
set(BOOST_COMPONENTS unit_test_framework)
find_package(Boost 1.58 REQUIRED COMPONENTS ${BOOST_COMPONENTS})
if(NOT Boost_FOUND)
	message(FATAL_ERROR "Fatal error: Boost (version >= 1.58) required.")
else()
	message(STATUS "Boost includes: ${Boost_INCLUDE_DIRS}")
	message(STATUS "Boost libs: ${Boost_LIBRARIES}")

	include_directories(${Boost_INCLUDE_DIRS})
endif()

# Получаем пути ко всем исходникам с тестами
file(GLOB MODULE_CORE_TESTS_SOURCE ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(${MODULE_CORE_TESTS_LIB_NAME} ${MODULE_CORE_TESTS_SOURCE})

target_include_directories(${MODULE_CORE_TESTS_LIB_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${MODULE_CORE_TESTS_LIB_NAME} ${Boost_LIBRARIES} libmodule_core)

add_custom_command(TARGET ${MODULE_CORE_TESTS_LIB_NAME} POST_BUILD COMMAND ${MODULE_CORE_TESTS_LIB_NAME})
