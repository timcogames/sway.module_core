## Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

Конфигурируем проект для сборки

```console
cmake -DBOOST_ROOT=/usr/local -DCMAKE_BUILD_TYPE=Release -DMODULE_CORE_ENABLE_TESTS=ON ../
```

Опция сборки | Тип | Описание | По умолчанию
:---|:---|:---|:---:
`BOOST_ROOT` | PATH | Путь до корневой директории Boost библиотеки | `-`
`CMAKE_BUILD_TYPE` | STRING | Тип сборки | `Debug`
`MODULE_CORE_BUILD_SHARED` | BOOL | Сборка библиотеки общего пользования | `OFF`
`MODULE_CORE_EMSASM` | BOOL | Использует Emscripten компилятор | `OFF`
`MODULE_CORE_ENABLE_COVERAGE` | BOOL | Включает поддержку сбора данных о покрытии кода тестами | `OFF`
`MODULE_CORE_ENABLE_TESTS` | BOOL | Включает построение тестов | `OFF`

Запускаем сборку

```console
cmake --build .
```
