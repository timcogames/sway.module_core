#!/usr/bin/env bash

files=$(eval find ${PWD}/wwwroot/dist -false "-o -name libmodule_core.*".{js,wasm})
for file in $files
do
  rm "$file"
done

cp ${PWD}/bin/libmodule_core.*.{js,wasm} ${PWD}/wwwroot/dist/
