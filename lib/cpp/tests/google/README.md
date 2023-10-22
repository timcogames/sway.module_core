### Конфигурация сборки для Google тестов

```console
cmake -DGLOB_GTEST_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/googletest \
      -DMODULE_CORE_ENABLE_TESTS=ON ../
```

### Запуск сборки

```console
cmake --build ./
```
