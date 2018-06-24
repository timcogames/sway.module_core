# sway.module_core

[![Build Status](https://travis-ci.com/timcogames/sway.module_core.svg?branch=master)](https://travis-ci.com/timcogames/sway.module_core)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/15977/badge.svg)](https://scan.coverity.com/projects/15977)
[![codecov](https://codecov.io/gh/timcogames/sway.module_core/branch/master/graph/badge.svg)](https://codecov.io/gh/timcogames/sway.module_core)
[![BCH compliance](https://bettercodehub.com/edge/badge/timcogames/sway.module_core?branch=master)](https://bettercodehub.com/)
[![Coverage Status](https://coveralls.io/repos/github/timcogames/sway.module_core/badge.svg?branch=master)](https://coveralls.io/github/timcogames/sway.module_core?branch=master)
[![Documentation](https://codedocs.xyz/timcogames/sway.module_core.svg)](https://codedocs.xyz/timcogames/sway.module_core/)

### Клонирование проекта

```console
git clone https://github.com/timcogames/sway.module_core.git
```

### Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

Конфигурируем проект для сборки

```console
cmake -DCMAKE_BUILD_TYPE=Release ../
```

Опция сборки | Описание | По умолчанию
:---|:---|:---:
`BUILD_SHARED_LIBS` | Сборка библиотеки общего пользования | `OFF`
`ENABLE_COVERAGE` | Включает поддержку сбора данных о покрытии кода тестами | `OFF`
`ENABLE_TESTS` | Включает построение тестов | `OFF`

Запускаем сборку

```console
cmake --build .
```
