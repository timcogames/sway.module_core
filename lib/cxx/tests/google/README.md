### Конфигурация сборки для Google тестов

```console
cmake -D GLOB_GTEST_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/googletest \
      -D MODULE_CORE_ENABLE_TESTS=ON \
      ../
```

### Запуск сборки

```console
cmake --build ./
```
