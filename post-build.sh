#!/usr/bin/env bash

rm -rf ./wwwroot/dist/{libmodule_core.*.js,libmodule_core.*.wasm}
cp ./bin/libmodule_core.*.js ./bin/libmodule_core.*.wasm ./wwwroot/dist/
