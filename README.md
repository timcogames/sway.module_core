# sway.module_core

[![Build Status][travis-svg]][travis-url] [![Coverity Scan Build Status][coverity-svg]][coverity-url] [![codecov][codecov-svg]][codecov-url] [![Coverage Status][coverage-svg]][coverage-url] [![BCH compliance][bettercodehub-svg]][bettercodehub-url] [![Documentation][codedocs-svg]][codedocs-url] [![License][license-svg]][license-url]

## Клонирование проекта

```console
git clone https://github.com/timcogames/sway.module_core.git
```

## Сборка проекта

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

## Contributing

См. [CONTRIBUTING](./github/CONTRIBUTING.md)

[travis-svg]: https://travis-ci.com/timcogames/sway.module_core.svg?branch=master
[travis-url]: https://travis-ci.com/timcogames/sway.module_core
[coverity-svg]: https://scan.coverity.com/projects/15977/badge.svg
[coverity-url]: https://scan.coverity.com/projects/15977
[coverage-svg]: https://coveralls.io/repos/github/timcogames/sway.module_core/badge.svg?branch=master
[coverage-url]: https://coveralls.io/github/timcogames/sway.module_core?branch=master
[bettercodehub-svg]: https://bettercodehub.com/edge/badge/timcogames/sway.module_core?branch=master
[bettercodehub-url]: https://bettercodehub.com/
[codecov-svg]: https://codecov.io/gh/timcogames/sway.module_core/branch/master/graph/badge.svg
[codecov-url]: https://codecov.io/gh/timcogames/sway.module_core
[codedocs-svg]: https://codedocs.xyz/timcogames/sway.module_core.svg
[codedocs-url]: https://codedocs.xyz/timcogames/sway.module_core/
[license-svg]: https://img.shields.io/github/license/mashape/apistatus.svg
[license-url]: LICENSE
