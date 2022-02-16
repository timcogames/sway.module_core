## Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

### Конфигурация сборки

```console
cmake -DCUSTOM_EMSCRIPTEN_ROOT_DIR=/Users/apriori85/Documents/Third-party/emsdk/upstream/emscripten -DCMAKE_BUILD_TYPE=Release -DMODULE_CORE_USE_EMSCRIPTEN=ON ../
```

== для тестов

```console
cmake -DCUSTOM_GTEST_ROOT_DIR=/Users/apriori85/Documents/Third-party/googletest -DMODULE_CORE_SHARED_LIB=ON -DMODULE_CORE_ENABLE_TESTS=ON ../
```

Опция сборки | Тип | Описание | По умолчанию
:---|:---|:---|:---:
`MODULE_CORE_SHARED_LIB` | BOOL | Создать общую библиотеку (.so) | `OFF`
`MODULE_CORE_USE_EMSCRIPTEN` | BOOL | Использует Emscripten компилятор | `OFF`
`MODULE_CORE_ENABLE_COVERAGE` | BOOL | Включает поддержку сбора данных о покрытии кода тестами | `OFF`
`MODULE_CORE_ENABLE_TESTS` | BOOL | Включает построение тестов | `OFF`
`CUSTOM_EMSCRIPTEN_ROOT_DIR` | PATH | Путь до корневой директории Emscripten библиотеки | `-`
`CUSTOM_BOOST_ROOT_DIR` | PATH | Путь до корневой директории Boost библиотеки (Не используется) | `-`
`CUSTOM_GTEST_ROOT_DIR` | PATH | Путь до корневой директории GTest библиотеки | `-`

### Запуск сборки

```console
cmake --build .
```
