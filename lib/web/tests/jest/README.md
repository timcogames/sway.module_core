#### для Jest тестов

```console
cmake -D CMAKE_BUILD_TYPE=Release \
      -D GLOB_EMSCRIPTEN_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/emsdk/upstream/emscripten \
      -D GLOB_EMSCRIPTEN_PLATFORM=ON \
      -D GLOB_EMSCRIPTEN_USE_BINDINGS=OFF \
      -D MODULE_CORE_LIB_TYPE=shared \
      -D MODULE_CORE_ALL_EXPORT=OFF \
      -D MODULE_CORE_ENVIRONMENT=node \
      -D MODULE_CORE_COMPILATION=async \
      ../
```

### Запуск сборки

```console
cmake --build ./
```

[↩️](../README.md)
