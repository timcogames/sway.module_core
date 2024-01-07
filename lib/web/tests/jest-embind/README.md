#### для Jest тестов

```console
cmake -D CMAKE_BUILD_TYPE=Release \
      -D GLOB_EMSCRIPTEN_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/emsdk/upstream/emscripten \
      -D GLOB_EMSCRIPTEN_PLATFORM=ON \
      -D GLOB_EMSCRIPTEN_USE_BINDINGS=ON \
      -D MODULE_CORE_SHARED_LIB=ON \
      -D MODULE_CORE_ENVIRONMENT=node \
      ../
```

### Запуск сборки

```console
cmake --build ./
```

[↩️](../README.md)
