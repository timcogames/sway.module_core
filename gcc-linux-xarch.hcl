variable "TAG" {
  default = "latest"
}

group "default" {
  targets = ["module_core-debug", "module_core-release"]
}

target "module_core-debug" {
  args = {
    ENABLED_TESTS = "ON"
    ENABLED_COVERAGE = "OFF"
  }

  dockerfile = "gcc-linux-xarch.Dockerfile"
  platforms = ["linux/amd64", "linux/arm64/v8"]
  tags = ["bonus85/sway.module_core:${TAG}"]
}

target "module_core-release-args" {
  args = {
    ENABLED_TESTS = "OFF"
    ENABLED_COVERAGE = ENABLED_COVERAGE
  }
}

target "module_core-release" {
  inherits = ["module_core-debug", "module_core-release-args"]
  platforms = ["linux/amd64", "linux/arm64/v8"]
  tags = ["bonus85/sway.module_core:${TAG}"]
}
