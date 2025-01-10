
Генерация html/xml

```console
doxygen doxygen/doxyfile.doxy
```

<p align='right'><sub><sup><i>terminal: PATH/docs %</i></sup></sub></p>


Генерация md

```console
moxygen --anchors --groups --templates ./moxygen/templates/cpp --output ./generated/md/api-%s.md ./generated/xml
```

<p align='right'><sub><sup><i>terminal: PATH/docs %</i></sup></sub></p>