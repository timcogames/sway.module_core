ARG TARGET_PLATFORM=

#_________________________________________________________________________________
#                                                                      Build stage

FROM --platform=$TARGET_PLATFORM gcc:10 AS base

#_________________________________________________________________________________
#                                                                             Info

LABEL Victor Timoshin <victor-timoshin@hotmail.com>

#_________________________________________________________________________________
#                                                                             Args

# ARG TARGET_PLATFORM_OS==<not used>
ARG TARGET_PLATFORM_ARCH=

ARG GTEST_ROOT_DIR=/usr/src/gtest
ARG GTEST_LIB_DIR=/tmp/lib
# ARG ENABLED_TESTS=<not used>
ARG ENABLED_COVERAGE=

#_________________________________________________________________________________
#                                                                          Install

RUN apt-get update -y && apt-get install -y \
    cmake \
    lcov \
    libgtest-dev

RUN `([ $TARGET_PLATFORM_ARCH = arm64/v8 ] && ln -s /usr/lib/aarch64-linux-gnu /tmp/lib ) || \
     ([ $TARGET_PLATFORM_ARCH = arm64 ] && ln -s /usr/lib/aarch64-linux-gnu /tmp/lib ) || \
     ([ $TARGET_PLATFORM_ARCH = amd64 ] && ln -s /usr/lib/x86_64-linux-gnu /tmp/lib )`

#_________________________________________________________________________________
#                                              Copy project files to the workspace

COPY /lib /module_core_workspace/lib
COPY /cmake_modules /module_core_workspace/cmake_modules
COPY /CMakeLists.txt /module_core_workspace
COPY /index.html /module_core_workspace

RUN mkdir /module_core_workspace/lcov_report

#_________________________________________________________________________________
#                                                           Build production image

FROM base as module_core-release

WORKDIR /module_core_workspace/build

RUN cmake -D CMAKE_BUILD_TYPE=Release \
          -D GLOB_GTEST_ROOT_DIR= \
          -D GLOB_GTEST_LIB_DIR= \
          -D MODULE_CORE_ENABLE_TESTS=OFF \
          -D MODULE_CORE_ENABLE_COVERAGE=$ENABLED_COVERAGE ../
RUN cmake --build ./

WORKDIR /module_core_workspace

ENTRYPOINT ["tail"]
CMD ["-f", "/dev/null"]

#_________________________________________________________________________________
#                                                          Build development image

FROM base as module_core-debug

WORKDIR /module_core_workspace/build

RUN cmake -D CMAKE_BUILD_TYPE=Debug \
          -D GLOB_GTEST_ROOT_DIR=$GTEST_ROOT_DIR \
          -D GLOB_GTEST_LIB_DIR=$GTEST_LIB_DIR \
          -D MODULE_CORE_ENABLE_TESTS=ON \
          -D MODULE_CORE_ENABLE_COVERAGE=$ENABLED_COVERAGE ../
RUN cmake --build ./

WORKDIR /module_core_workspace

ENTRYPOINT ["tail"]
CMD ["-f", "/dev/null"]
