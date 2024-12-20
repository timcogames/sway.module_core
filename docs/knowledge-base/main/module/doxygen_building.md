
Генерация html/xml

```console
doxygen doxygen/doxyfile.doxy
```

<p align='right'><sub><sup><i>terminal: PATH/docs %</i></sup></sub></p>


Генерация md

```console
moxygen --anchors --templates ../moxygen/templates/cpp --output api-%s.md ../doxygen/generated/xml
```

<p align='right'><sub><sup><i>terminal: PATH/docs %</i></sup></sub></p>