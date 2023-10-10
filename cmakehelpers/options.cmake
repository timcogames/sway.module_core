option(GLOB_EMSCRIPTEN_PLATFORM "Using emscripten compiler" OFF)
option(GLOB_EMSCRIPTEN_ENVIRONMENT_WEB "" OFF)
option(GLOB_EMSCRIPTEN_USE_WEB_BINDINGS "Using emscripten binding" OFF)
option(GLOB_EMSCRIPTEN_ENABLE_ASSERTIONS "" OFF)
option(GLOB_EMSCRIPTEN_ROOT_DIR "Emscripten root directory" OFF)
option(GLOB_BOOST_ROOT_DIR "Boost root directory" OFF)
option(GLOB_GTEST_ROOT_DIR "GTest root directory" OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build" FORCE)
endif()
