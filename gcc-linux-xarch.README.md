
### list

```console
docker buildx ls
```

### create

📋 *docker buildx create --use --bootstrap --name <__CONTAINER_NAME__> --platform <__LINUX_ARCHS__> --driver docker-container*

```console
docker buildx create \
       --use \
       --bootstrap \
       --name sway-cntr \
       --platform linux/arm64,linux/arm/v8 \
       --driver docker-container
```

### remove

📋 *docker buildx rm --force <__CONTAINER_NAME__>*

```console
docker buildx rm --force sway-cntr
```

### build

```console
docker buildx build --no-cache --progress plain --pull --rm \
       --builder=sway-cntr \
       --platform=linux/amd64,linux/arm64/v8 \
       --target=image-develop \
       --build-arg=ENABLED_TESTS=ON \
       --build-arg=ENABLED_COVERAGE=OFF \
       --tag=sway/module_core:buildx-latest \
       --file "gcc-linux-xarch.Dockerfile" "."
```

### bake

📋 *docker buildx bake --push -f <__HCL_FILE_PATH__> <__TARGET_NAME__>*

```console
docker buildx bake --push -f "gcc-linux-xarch.hcl" module_core-debug
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
