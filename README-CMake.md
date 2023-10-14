## Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

### Конфигурация сборки

📋 *cmake -DCMAKE_BUILD_TYPE=Release -DGLOB_EMSCRIPTEN_ROOT_DIR=<[__PATH__](#glob_options)> -DGLOB_EMSCRIPTEN_PLATFORM=ON -DGLOB_EMSCRIPTEN_ENVIRONMENT_WEB=<[__USED__](#glob_options)>*

```console
cmake -DCMAKE_BUILD_TYPE=Release \
      -DGLOB_EMSCRIPTEN_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/emsdk/upstream/emscripten \
      -DGLOB_EMSCRIPTEN_PLATFORM=ON \
      -DGLOB_EMSCRIPTEN_WEB_ENVIRONMENT=ON ../

python3 -m http.server <PORT>
```

#### для Google тестов

```console
cmake -DGLOB_GTEST_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/googletest \
      -DMODULE_CORE_ENABLE_TESTS=ON ../
```

#### для Jest тестов

```console
cmake -DCMAKE_BUILD_TYPE=Release \
      -DGLOB_EMSCRIPTEN_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/emsdk/upstream/emscripten \
      -DGLOB_EMSCRIPTEN_PLATFORM=ON \
      -DGLOB_EMSCRIPTEN_WEB_ENVIRONMENT=OFF \
      -DGLOB_EMSCRIPTEN_USE_BINDINGS=ON \
      -DMODULE_CORE_SHARED_LIB=ON ../
```

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
`MODULE_CORE_SHARED_LIB` | BOOL | Создать общую библиотеку (.dylib|.so) | `OFF`
`MODULE_CORE_ENABLE_COVERAGE` | BOOL | Включает поддержку сбора данных о покрытии кода тестами | `OFF`
`MODULE_CORE_ENABLE_TESTS` | BOOL | Включает построение тестов | `OFF`

### Запуск сборки

```console
cmake --build ./
```
