#_________________________________________________________________________________
#                                                                      Build stage
FROM --platform=$BUILDPLATFORM gcc:10 AS base

#_________________________________________________________________________________
#                                                                             Info
LABEL Victor Timoshin <victor-timoshin@hotmail.com>

#_________________________________________________________________________________
#                                                                             Args

ARG TARGETPLATFORM
ARG TARGETARCH

ARG GTEST_ROOT_DIR=/usr/src/gtest
ARG GTEST_LIB_DIR=/tmp/lib
ARG ENABLED_TESTS
ARG ENABLED_COVERAGE


#_________________________________________________________________________________
#                                                                          Install
RUN apt-get update -y && apt-get install -y \
    cmake \
    libgtest-dev

RUN `([ $TARGETARCH = arm64/v8 ] && ln -s /usr/lib/aarch64-linux-gnu /tmp/lib ) || \
     ([ $TARGETARCH = arm64 ] && ln -s /usr/lib/aarch64-linux-gnu /tmp/lib ) || \
     ([ $TARGETARCH = amd64 ] && ln -s /usr/lib/x86_64-linux-gnu /tmp/lib )`

#_________________________________________________________________________________
#                                              Copy project files to the workspace
COPY /lib /module_core_workspace/lib
COPY /cmakehelpers /module_core_workspace/cmakehelpers
COPY /CMakeLists.txt /module_core_workspace
COPY /index.html /module_core_workspace

#_________________________________________________________________________________
#                                                          Build development image
FROM base as module_core-debug

WORKDIR /module_core_workspace/build
RUN cmake -DCMAKE_BUILD_TYPE=Debug \
          -DGLOB_GTEST_ROOT_DIR=$GTEST_ROOT_DIR \
          -DGLOB_GTEST_LIB_DIR=$GTEST_LIB_DIR \
          -DMODULE_CORE_ENABLE_TESTS=$ENABLED_TESTS \
          -DMODULE_CORE_ENABLE_COVERAGE=$ENABLED_COVERAGE ../

RUN cmake --build ./

ENTRYPOINT ["/module_core_workspace/bin/dbg/module_core_tests"]

#_________________________________________________________________________________
#                                                           Build production image
FROM base as module_core-release

WORKDIR /module_core_workspace/build
RUN cmake -DCMAKE_BUILD_TYPE=Release \
          -DGLOB_GTEST_ROOT_DIR=$GTEST_ROOT_DIR \
          -DGLOB_GTEST_LIB_DIR=$GTEST_LIB_DIR \
          -DMODULE_CORE_ENABLE_TESTS=$ENABLED_TESTS \
          -DMODULE_CORE_ENABLE_COVERAGE=$ENABLED_COVERAGE ../

RUN cmake --build ./

ENTRYPOINT ["/module_core_workspace/bin/module_core_tests"]
