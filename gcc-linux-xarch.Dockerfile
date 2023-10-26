#_________________________________________________________________________________
#                                                                      Build stage
FROM --platform=$BUILDPLATFORM gcc:10 AS base

#_________________________________________________________________________________
#                                                                             Args
ARG TARGETARCH
RUN if [ "$TARGETARCH" = "amd64" ]; then  \
        echo "Target arch:amd64" ;  \
    fi

ARG TARGETPLATFORM
RUN if [ "$TARGETPLATFORM" = "linux" ]; then  \
        echo "Target platform:linux" ;  \
    fi

ARG ENABLED_TESTS
ARG ENABLED_COVERAGE

#_________________________________________________________________________________
#                                                                             Info
LABEL Victor Timoshin <victor-timoshin@hotmail.com>

#_________________________________________________________________________________
#                                                                          Install
RUN apt-get update -y && apt-get install -y software-properties-common && apt-add-repository 'deb http://archive.debian.org/debian stretch main contrib non-free'
RUN apt-get update -y && apt-get install -y \
    cmake \
    libgtest-dev

#_________________________________________________________________________________
#                                              Copy project files to the workspace
COPY ./lib /module_core_workspace/lib
COPY ./cmakehelpers /module_core_workspace/cmakehelpers
COPY ./CMakeLists.txt /module_core_workspace
COPY ./index.html /module_core_workspace

WORKDIR /module_core_workspace/build

#_________________________________________________________________________________
#                                                          Build development image
FROM base as image-develop
RUN cmake -DCMAKE_BUILD_TYPE=Debug \
          -DGLOB_GTEST_ROOT_DIR=/usr/src/gtest \
          -DMODULE_CORE_ENABLE_TESTS=${ENABLED_TESTS} \
          -DMODULE_CORE_ENABLE_COVERAGE=${ENABLED_COVERAGE} ../

RUN cmake --build .
ENTRYPOINT ["/module_core_workspace/bin/dbg/module_core_tests"]

#_________________________________________________________________________________
#                                                           Build production image
FROM base as image-master
RUN cmake -DCMAKE_BUILD_TYPE=Release \
          -DGLOB_GTEST_ROOT_DIR=/usr/src/gtest \
          -DMODULE_CORE_ENABLE_TESTS=${ENABLED_TESTS} \
          -DMODULE_CORE_ENABLE_COVERAGE=${ENABLED_COVERAGE} ../

RUN cmake --build .
ENTRYPOINT ["/module_core_workspace/bin/module_core_tests"]
