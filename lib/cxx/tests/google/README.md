### Конфигурация сборки для Google тестов

```console
cmake -S . -B build/
cmake --build build
```

```console
cmake -D CMAKE_BUILD_TYPE=Debug \
      -D GLOB_GTEST_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/googletest/googletest \
      -D GLOB_GTEST_LIB_DIR=/Users/<USER_NAME>/Documents/Third-party/googletest/build/lib \
      -D MODULE_CORE_LIB_TYPE=static \
      -D MODULE_CORE_ENABLE_TESTS=ON \
      ../
```

### Запуск сборки

```console
cmake --build ./
```
