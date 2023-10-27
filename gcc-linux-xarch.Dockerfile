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
ARG GTEST_LIB_DIR
ARG ENABLED_TESTS
ARG ENABLED_COVERAGE

RUN if [ "$TARGETARCH" = "arm64/v8" ]; then \
      $GTEST_LIB_DIR=/usr/lib/aarch64-linux-gnu; \
    elif [ "$TARGETARCH" = "amd64" ]; then \
      $GTEST_LIB_DIR=/usr/lib/x86_64-linux-gnu; \
    else \
      echo "Unsupported architecture: $TARGETPLATFORM/$TARGETARCH"; \
    fi

#_________________________________________________________________________________
#                                                                          Install
RUN apt-get update -y && apt-get install -y \
    cmake \
    libgtest-dev

#_________________________________________________________________________________
#                                              Copy project files to the workspace
COPY /lib /module_core_workspace/lib
COPY /cmakehelpers /module_core_workspace/cmakehelpers
COPY /CMakeLists.txt /module_core_workspace
COPY /index.html /module_core_workspace

#_________________________________________________________________________________
#                                                          Build development image
FROM base as image-develop

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
FROM base as image-master

WORKDIR /module_core_workspace/build
RUN cmake -DCMAKE_BUILD_TYPE=Release \
          -DGLOB_GTEST_ROOT_DIR=$GTEST_ROOT_DIR \
          -DGLOB_GTEST_LIB_DIR=$GTEST_LIB_DIR \
          -DMODULE_CORE_ENABLE_TESTS=$ENABLED_TESTS \
          -DMODULE_CORE_ENABLE_COVERAGE=$ENABLED_COVERAGE ../

RUN cmake --build ./

ENTRYPOINT ["/module_core_workspace/bin/module_core_tests"]
