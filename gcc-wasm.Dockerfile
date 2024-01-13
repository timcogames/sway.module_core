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

ARG EMSCRIPTEN_SDK_DIR=/opt/.emsdk
ARG EMSCRIPTEN_VERSION=latest

RUN git clone https://github.com/emscripten-core/emsdk.git $EMSCRIPTEN_SDK_DIR
RUN ./$EMSCRIPTEN_SDK_DIR/emsdk update-tags && \
    ./$EMSCRIPTEN_SDK_DIR/emsdk install $EMSCRIPTEN_VERSION && \
    ./$EMSCRIPTEN_SDK_DIR/emsdk activate $EMSCRIPTEN_VERSION

# RUN source ./emsdk/emsdk_env.sh

COPY ./lib /module_core_workspace/lib
COPY ./cmake_modules /module_core_workspace/cmake_modules
COPY ./CMakeLists.txt /module_core_workspace
COPY ./index.html /module_core_workspace

# Build development image

FROM base as module_core-debug
WORKDIR /module_core_workspace/build

RUN echo "source /opt/.emsdk/emsdk_env.sh > /dev/null 2>&1" >> ~/.bashrc
RUN cmake -D CMAKE_BUILD_TYPE=Debug \
          -D GLOB_EMSCRIPTEN_ROOT_DIR=/opt/.emsdk/upstream/emscripten \
          -D GLOB_EMSCRIPTEN_PLATFORM=ON \
          -D MODULE_CORE_ENVIRONMENT=web,node \
          -D MODULE_CORE_COMPILATION=async \
          ../
RUN cmake --build ./

WORKDIR /module_core_workspace

ENTRYPOINT ["tail"]
CMD ["-f", "/dev/null"]

# Build production image

FROM base as module_core-release
RUN ls ./
