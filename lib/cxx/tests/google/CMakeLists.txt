set(META_CORE_PRJNAME_TESTS "module_core_tests")
set(META_CORE_EXENAME_TESTS "${META_CORE_PRJNAME_TESTS}")

project(${META_CORE_PRJNAME_TESTS} CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)

set(GTEST_ROOT "${GLOB_GTEST_ROOT_DIR}")
set(GTEST_INC_DIR "${GTEST_ROOT}/include")
set(GTEST_SRC_DIR "${GTEST_ROOT}/src")

include_directories("${GTEST_INC_DIR}")

file(GLOB MODULE_CORE_SOURCE_TESTS "${PROJECT_SOURCE_DIR}/*.spec.cpp")

add_executable(${META_CORE_EXENAME_TESTS} ${MODULE_CORE_SOURCE_TESTS} "${GTEST_SRC_DIR}/gtest_main.cc")
target_link_libraries(${META_CORE_EXENAME_TESTS} module_core pthread ${GLOB_GTEST_LIB_DIR}/libgtest.a)

add_test(NAME ${META_CORE_EXENAME_TESTS} COMMAND ${META_CORE_EXENAME_TESTS})
