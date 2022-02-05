## Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

Конфигурируем проект для сборки (Поддерживается два варианта)

```console
cmake -DBOOST_ROOT=/Users/apriori85/Documents/Third-party/boost_1_78_0 -DCMAKE_BUILD_TYPE=Release -DMODULE_CORE_ENABLE_TESTS=ON ../

cmake -DCMAKE_BUILD_TYPE=Release -DMODULE_CORE_EMSCRIPTEN=ON -DCMAKE_TOOLCHAIN_FILE=/Users/apriori85/Documents/Third-party/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake ../
```

Опция сборки | Тип | Описание | По умолчанию
:---|:---|:---|:---:
`BOOST_ROOT` | PATH | Путь до корневой директории Boost библиотеки | `-`
`CMAKE_BUILD_TYPE` | STRING | Тип сборки | `Debug`
`CMAKE_TOOLCHAIN_FILE` | STRING | Магия | `-`
`MODULE_CORE_EMSCRIPTEN` | BOOL | Использует Emscripten компилятор | `OFF`
`MODULE_CORE_ENABLE_COVERAGE` | BOOL | Включает поддержку сбора данных о покрытии кода тестами | `OFF`
`MODULE_CORE_ENABLE_TESTS` | BOOL | Включает построение тестов | `OFF`

Запускаем сборку

```console
cmake --build .
```
