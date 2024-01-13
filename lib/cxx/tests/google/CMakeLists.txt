#--------------------------------------------------------------------------------
# CMake version
#--------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

enable_testing()

#--------------------------------------------------------------------------------
# Set dependency paths
#--------------------------------------------------------------------------------

set(GTEST_ROOT "${GLOB_GTEST_ROOT_DIR}")
set(GTEST_INC_DIR "${GTEST_ROOT}/include")
set(GTEST_SRC_DIR "${GTEST_ROOT}/src")

#--------------------------------------------------------------------------------
# Include dependency headers
#--------------------------------------------------------------------------------

include_directories("${GTEST_INC_DIR}")
include_directories("${MODULE_CORE_LIST_DIR}/lib/cxx/include")

#--------------------------------------------------------------------------------
# Find project test files
#--------------------------------------------------------------------------------

file(GLOB MODULE_CORE_TEST_SOURCES "${MODULE_CORE_ROOT_DIR}/lib/cxx/tests/*/*.spec.cpp")

#--------------------------------------------------------------------------------
# Build tests
#--------------------------------------------------------------------------------

add_executable(${MODULE_CORE_TEST_TARGET} ${MODULE_CORE_TEST_SOURCES} "${GTEST_SRC_DIR}/gtest_main.cc")
target_link_libraries(${MODULE_CORE_TEST_TARGET} module_core pthread ${GLOB_GTEST_LIB_DIR}/libgtest.a)
enable_cxx17(${MODULE_CORE_TEST_TARGET})

add_test(NAME ${MODULE_CORE_TEST_TARGET} COMMAND ${MODULE_CORE_TEST_TARGET})
