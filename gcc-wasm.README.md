## Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

### Конфигурация сборки

📋 *cmake -DCMAKE_BUILD_TYPE=Release -DGLOB_EMSCRIPTEN_ROOT_DIR=<[__PATH__](#glob_options)> -DGLOB_EMSCRIPTEN_PLATFORM=ON -DMODULE_CORE_ENVIRONMENT=<[__VARS__](#glob_options)>*

```console
cmake -D CMAKE_BUILD_TYPE=Release \
      -D GLOB_EMSCRIPTEN_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/emsdk/upstream/emscripten \
      -D GLOB_EMSCRIPTEN_PLATFORM=ON \
      -D MODULE_CORE_ENVIRONMENT=web,node \
      -D MODULE_CORE_COMPILATION=async ../

python3 -m http.server <PORT>
```

[для Google тестов](./lib/cxx/tests/README.md)

[для Jest тестов](./lib/web/tests/README.md)

# glob_options

[Глобальные опции сборки](./docs/glob-options.README.md)`

Опция сборки | Тип | Описание | По умолчанию
:---|:---|:---|:---:
`MODULE_CORE_SHARED_LIB` | BOOL | Создать общую библиотеку (.dylib/.so) | `OFF`
`MODULE_CORE_ENVIRONMENT` | STRING | Переменная среды (прим.: `web` or `node` or `web,node`) | `OFF`
`MODULE_CORE_ENABLE_COVERAGE` | BOOL | Включает поддержку сбора данных о покрытии кода тестами | `OFF`
`MODULE_CORE_ENABLE_TESTS` | BOOL | Включает построение тестов | `OFF`

### Запуск сборки

```console
cmake --build ./
```
