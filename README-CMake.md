## Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

### Конфигурация сборки

📋 *cmake -DCMAKE_BUILD_TYPE=Release -DGLOB_EMSCRIPTEN_ROOT_DIR=<[__PATH__](#glob_options)> -DGLOB_EMSCRIPTEN_PLATFORM=ON -DMODULE_CORE_ENVIRONMENT=<[__VARS__](#glob_options)>*

```console
cmake -DCMAKE_BUILD_TYPE=Release \
      -DGLOB_EMSCRIPTEN_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/emsdk/upstream/emscripten \
      -DGLOB_EMSCRIPTEN_PLATFORM=ON \
      -DMODULE_CORE_ENVIRONMENT=web,node \
      -DMODULE_CORE_COMPILATION=ON ../

docker build \
      --no-cache \
      --progress plain \
      --pull --rm \
      --build-arg selected_build_type=Release \
      --build-arg enabled_google_tests=ON \
      --build-arg enabled_coverage=OFF \
      -f "Dockerfile-ARM64" \
      -t sway/module_core:latest "."

python3 -m http.server <PORT>
```

[для Google тестов](./lib/cxx/tests/README.md)

[для Jest тестов](./lib/web/tests/README.md)

# glob_options

Опция сборки | Тип | Описание | По умолчанию
:---|:---|:---|:---:
`GLOB_THIRD_PARTY_DIR` | PATH | Путь до корневой директории Other библиотек | `-`
`GLOB_EMSCRIPTEN_PLATFORM` | BOOL | Использует Emscripten компилятор | `OFF`
`GLOB_EMSCRIPTEN_USE_BINDINGS` | BOOL | Использует Emscripten привязки для функций | `OFF`
`GLOB_EMSCRIPTEN_ROOT_DIR` | PATH | Путь до корневой директории Emscripten библиотеки | `-`
`GLOB_BOOST_ROOT_DIR` | PATH | Путь до корневой директории Boost библиотеки (Не используется) | `-`
`GLOB_GTEST_ROOT_DIR` | PATH | Путь до корневой директории GTest библиотеки | `-`

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
