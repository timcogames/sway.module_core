## Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

Конфигурируем проект для сборки (Поддерживается два варианта)

```console
cmake -DCUSTOM_GTEST_ROOT_DIR=/Users/apriori85/Documents/Third-party/googletest -DMODULE_CORE_ENABLE_TESTS=ON ../

cmake -DCUSTOM_EMSCRIPTEN_ROOT_DIR=/Users/apriori85/Documents/Third-party/emsdk/upstream/emscripten -DCMAKE_BUILD_TYPE=Release -DMODULE_CORE_ENABLE_EMSCRIPTEN=ON ../
```

Опция сборки | Тип | Описание | По умолчанию
:---|:---|:---|:---:
`CMAKE_BUILD_TYPE` | STRING | Тип сборки | `Debug`
`MODULE_CORE_ENABLE_EMSCRIPTEN` | BOOL | Использует Emscripten компилятор | `OFF`
`MODULE_CORE_ENABLE_COVERAGE` | BOOL | Включает поддержку сбора данных о покрытии кода тестами | `OFF`
`MODULE_CORE_ENABLE_TESTS` | BOOL | Включает построение тестов | `OFF`
`CUSTOM_EMSCRIPTEN_ROOT_DIR` | PATH | Путь до корневой директории Emscripten библиотеки | `-`
`CUSTOM_BOOST_ROOT_DIR` | PATH | Путь до корневой директории Boost библиотеки (Не используется) | `-`
`CUSTOM_GTEST_ROOT_DIR` | PATH | Путь до корневой директории GTest библиотеки | `-`

Запускаем сборку

```console
cmake --build .
```
