```console
cmake -D CMAKE_BUILD_TYPE=Release \
    -D GLOB_EMSCRIPTEN_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/emsdk/upstream/emscripten \
    -D GLOB_EMSCRIPTEN_PLATFORM=ON \
    -D GLOB_EMSCRIPTEN_USE_BINDINGS=OFF \
    -D MODULE_CORE_SHARED_LIB=ON \
    -D MODULE_CORE_BUILD_TYPE=module \
    -D MODULE_CORE_ALL_EXPORT=OFF \
    -D MODULE_CORE_ENVIRONMENT=web \
    -D MODULE_CORE_COMPILATION=async \
    ../
```
