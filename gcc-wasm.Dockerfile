#
# Build stage
#
FROM --platform=linux/arm64/v8 gcc:10 AS base

ARG ENABLED_TESTS=ON
ARG ENABLED_COVERAGE=OFF

LABEL Victor Timoshin <victor-timoshin@hotmail.com>

RUN update-ca-certificates -f

RUN apt-get update -y && apt-get install -y software-properties-common && apt-add-repository 'deb http://archive.debian.org/debian stretch main contrib non-free'
RUN apt-get update -y && apt-get install -y \
    cmake \
    python3 \
    wget \
    unzip \
    git

RUN git clone https://github.com/emscripten-core/emsdk.git /opt/.emsdk
WORKDIR /opt/.emsdk
RUN ./emsdk update-tags && \
    ./emsdk install latest && \
    ./emsdk activate latest

# RUN source ./emsdk/emsdk_env.sh

COPY ./lib /module_core_workspace/lib
COPY ./cmakehelpers /module_core_workspace/cmakehelpers
COPY ./CMakeLists.txt /module_core_workspace
COPY ./index.html /module_core_workspace

WORKDIR /module_core_workspace/build

# Build development image

FROM base as image-develop
RUN echo "source /opt/.emsdk/emsdk_env.sh > /dev/null 2>&1" >> ~/.bashrc
RUN cmake -DCMAKE_BUILD_TYPE=Debug \
          -DGLOB_EMSCRIPTEN_ROOT_DIR=/opt/.emsdk/upstream/emscripten \
          -DGLOB_EMSCRIPTEN_PLATFORM=ON \
          -DMODULE_CORE_ENVIRONMENT=web,node \
          -DMODULE_CORE_COMPILATION=async ../

RUN cmake --build .
ENTRYPOINT ["/module_core_workspace/bin/dbg/module_core_tests"]

# Build production image

FROM base as image-master
RUN ls ./
