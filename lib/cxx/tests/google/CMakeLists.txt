# Мета-информация о проекте
set(META_CORE_PRJNAME_TESTS "module_core_tests")
set(META_CORE_EXENAME_TESTS "${META_CORE_PRJNAME_TESTS}")

project(${META_CORE_PRJNAME_TESTS} CXX)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
# set(CMAKE_HAVE_THREADS_LIBRARY 1)
# set(CMAKE_USE_WIN32_THREADS_INIT 0)
# set(CMAKE_USE_PTHREADS_INIT 1)
# set(THREADS_PREFER_PTHREAD_FLAG ON)

# set(GTest_ROOT "${GLOB_GTEST_ROOT_DIR}")
# set(GTEST_INCLUDE_DIR "${GTest_ROOT}/googletest/include")
# set(GTEST_INCLUDE_DIR "${GTest_ROOT}/include")
# set(GTEST_LIBRARY_DIR "${GTest_ROOT}/build/lib")

# set(GTEST_MAIN_LIBRARY "${GTEST_LIBRARY_DIR}/gtest_main.lib")

enable_testing()

find_package(GTest REQUIRED) # /usr/lib/aarch64-linux-gnu/libgtest.a
# find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

# Получаем пути ко всем исходникам с тестами
file(GLOB MODULE_CORE_SOURCE_TESTS "${PROJECT_SOURCE_DIR}/*.spec.cpp")
# add_executable(${META_CORE_EXENAME_TESTS} ${MODULE_CORE_SOURCE_TESTS} "${GTest_ROOT}/googletest/src/gtest_main.cc")

add_executable(${META_CORE_EXENAME_TESTS} ${MODULE_CORE_SOURCE_TESTS} "/usr/src/gtest/src/gtest_main.cc")
# add_executable(${META_CORE_EXENAME_TESTS} ${MODULE_CORE_SOURCE_TESTS} "/opt/.gtest/googletest/src/gtest_main.cc")

# target_link_libraries(${META_CORE_EXENAME_TESTS} module_core ${GTEST_LIBRARY_DIR}/libgtest.a ${CMAKE_DL_LIBS})
target_link_libraries(${META_CORE_EXENAME_TESTS} module_core ${GTEST_LIBRARIES} pthread)

# add_custom_command(TARGET ${META_CORE_EXENAME_TESTS} POST_BUILD COMMAND ${META_CORE_EXENAME_TESTS})
add_test(NAME HelloWorldTest COMMAND ${META_CORE_EXENAME_TESTS})
