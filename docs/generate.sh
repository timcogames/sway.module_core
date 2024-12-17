#!/usr/bin/env bash

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
pushd $DIR

doxygen ./doxygen/doxyfile.doxy

moxygen --groups --html-anchors --templates ./moxygen/templates/cpp --output ./generated/md/%s.md ./generated/xml

popd
