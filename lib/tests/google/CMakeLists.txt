# Мета-информация о проекте
set(META_CORE_PRJNAME_TESTS "module_core_tests")
set(META_CORE_EXENAME_TESTS "${META_CORE_PRJNAME_TESTS}")

project(${META_CORE_PRJNAME_TESTS} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")

set(GTest_ROOT "${CUSTOM_GTEST_ROOT_DIR}")
set(GTEST_INCLUDE_DIR "${GTest_ROOT}/googletest/include")
set(GTEST_LIBRARY_DIR "${GTest_ROOT}/build/lib")

# set(GTEST_MAIN_LIBRARY "${GTEST_LIBRARY_DIR}/gtest_main.lib")

# find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})

# Получаем пути ко всем исходникам с тестами
file(GLOB MODULE_CORE_SOURCE_TESTS "${PROJECT_SOURCE_DIR}/*.spec.cpp")

add_executable(${META_CORE_EXENAME_TESTS} ${MODULE_CORE_SOURCE_TESTS} "${GTest_ROOT}/googletest/src/gtest_main.cc")
target_link_libraries(${META_CORE_EXENAME_TESTS} libmodule_core ${GTEST_LIBRARY_DIR}/libgtest.a ${CMAKE_DL_LIBS})

add_custom_command(TARGET ${META_CORE_EXENAME_TESTS} POST_BUILD COMMAND ${META_CORE_EXENAME_TESTS})
