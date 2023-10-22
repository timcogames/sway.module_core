#### для Jest тестов

```console
cmake -DCMAKE_BUILD_TYPE=Release \
      -DGLOB_EMSCRIPTEN_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/emsdk/upstream/emscripten \
      -DGLOB_EMSCRIPTEN_PLATFORM=ON \
      -DGLOB_EMSCRIPTEN_USE_BINDINGS=ON \
      -DMODULE_CORE_SHARED_LIB=ON \
      -DMODULE_CORE_ENVIRONMENT=node ../
```

### Запуск сборки

```console
cmake --build ./
```
