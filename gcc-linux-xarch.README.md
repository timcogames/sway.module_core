### remove

📋 *docker buildx rm --force <__CONTAINER_NAME__>*

```console
docker buildx rm --force sway-cntr
```

### inspect

```console
docker buildx imagetools inspect bonus85/sway.module_core:buildx-latest
```

### run

📋 *docker run --rm <__IMAGE__>*

```console
docker run --rm docker.io/bonus85/sway.module_core:buildx-latest@<DIGEST>
```

##  CMAKE Ручная сборка тестов

```console
cmake -D CMAKE_BUILD_TYPE=Debug \
      -D GLOB_GTEST_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/googletest/googletest \
      -D GLOB_GTEST_LIB_DIR=/Users/<USER_NAME>/Documents/Third-party/googletest/build/lib \
      -D MODULE_CORE_ENABLE_TESTS=ON \
      -D MODULE_CORE_ENABLE_COVERAGE=OFF ../

cmake --build ./
```
