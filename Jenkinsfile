import org.jenkinsci.plugins.pipeline.modeldefinition.Utils

def DOCKER_PATH = "/Applications/Docker.app/Contents/Resources/bin"
def CMAKE_PATH = "/opt/homebrew/Cellar/cmake/3.22.1/bin"

def MODULE_CORE_CONTAINER_NAME = "sway"
def MODULE_CORE_CONTAINER_ID = ""

def MODULE_CORE_IMAGE_NAME = "${MODULE_CORE_CONTAINER_NAME}/module_core"
def MODULE_CORE_IMAGE_TAG = "latest"
def MODULE_CORE_IMAGE_ID=""

def SELECTED_BRANCH_NAME = ""
def APPLIED_THIRD_PARTY_DIR = ""
def APPLIED_TEST_ROOT_DIR = ""
def APPLIED_TEST_LIB_DIR = ""
def ENABLED_DOCKER = false
def ENABLED_TESTS = ""
def ENABLED_COVERAGE = ""

def booleanToStr(value) {
  return (value) ? "ON" : "OFF"
}

node {
  try {
    stage("Clone repository") {
      SELECTED_BRANCH_NAME = input(message: "Select active branch", parameters: [
        [$class: "ChoiceParameterDefinition", 
          choices: "develop\nmaster", 
          name: "Active branch", 
          description: "Select option the relevant branch"]
      ])

      git url: "https://github.com/timcogames/sway.module_core.git", branch: "${SELECTED_BRANCH_NAME}"
      sh "git submodule update --init --recursive"
    }

    stage("Build options") {
      def options = input(message: "Build options", ok: "Run", parameters: [
        // choice(name: "BUILD_TYPE", choices: "Release\nDebug", description: "Select build type"),
        string(name: "THIRD_PARTY_DIR", defaultValue: "/Users/<USER_NAME>/Documents/Third-party", description: ""),
        string(name: "TEST_ROOT_DIR", defaultValue: "/Users/<USER_NAME>/Documents/Third-party/googletest/googletest", description: ""),
        string(name: "TEST_LIB_DIR", defaultValue: "/Users/<USER_NAME>/Documents/Third-party/googletest/build/lib", description: ""),
        booleanParam(name: "TESTS", defaultValue: true, description: ""),
        booleanParam(name: "COVERAGE", defaultValue: false, description: "")
      ])

      APPLIED_THIRD_PARTY_DIR = options["THIRD_PARTY_DIR"]
      APPLIED_TEST_ROOT_DIR = options["TEST_ROOT_DIR"]
      APPLIED_TEST_LIB_DIR = options["TEST_LIB_DIR"]
      ENABLED_TESTS = options["TESTS"]
      ENABLED_COVERAGE = options["COVERAGE"]
    }

    stage("Build:with-docker gcc-linux-arm64[TESTS]") {
      def continued
      try {
        continued = input(id: "proceed_id", message: "Build tests without Docker?", parameters: [
          [$class: "BooleanParameterDefinition", defaultValue: true, description: "", name: "Please confirm that you agree to continue"]
        ])
      } catch(err) {
        continued = false
      }

      if (!continued) {
        echo "Skipping stage..."
        Utils.markStageSkippedForConditional("Build:with-docker gcc-linux-arm64[TESTS]")
      } else {
        sh "${DOCKER_PATH}/docker build --no-cache --pull --rm \
          --progress plain \
          --target image-${SELECTED_BRANCH_NAME} \
          --build-arg BUILDPLATFORM=linux/arm64/v8 \
          --build-arg TARGETPLATFORM=linux \
          --build-arg TARGETARCH=arm64/v8 \
          --build-arg ENABLED_TESTS=ON \
          --build-arg ENABLED_COVERAGE=OFF \
          -f gcc-linux-xarch.Dockerfile \
          -t ${MODULE_CORE_IMAGE_NAME}:${MODULE_CORE_IMAGE_TAG} ."
      }
    }

    stage("Build:without-docker gcc-linux-arm64") {
      if (ENABLED_DOCKER) {
        echo "Skipping stage..."
        Utils.markStageSkippedForConditional("Build:without-docker gcc-linux-arm64")
      } else {
        sh "mkdir -p build"
        dir("./build") {
          sh "${CMAKE_PATH}/cmake \
            -DCMAKE_BUILD_TYPE=Debug \
            -DGLOB_GTEST_ROOT_DIR=${APPLIED_TEST_ROOT_DIR} \
            -DGLOB_GTEST_LIB_DIR=${APPLIED_TEST_LIB_DIR} \
            -DMODULE_CORE_ENABLE_TESTS=${booleanToStr(ENABLED_TESTS)} \
            -DMODULE_CORE_ENABLE_COVERAGE=${booleanToStr(ENABLED_COVERAGE)} ../"
          sh "${CMAKE_PATH}/cmake --build ./"
        }
      }
    }

    stage("Build/Push:docker gcc-linux-xarch") {
      if (!ENABLED_DOCKER && SELECTED_BRANCH_NAME != "master") {
        echo "Skipping stage..."
        Utils.markStageSkippedForConditional("Build/Push:docker gcc-linux-xarch")
      } else {
        sh "${DOCKER_PATH}/docker buildx bake --push \
          --set image.args.ENABLED_COVERAGE=\"${booleanToStr(ENABLED_COVERAGE)}\" \
          -f \"gcc-linux-xarch.hcl\" module_core-release"
      }
    }

    // stage("Build:docker alpine-multi-arch") {
    //   sh "${DOCKER_PATH}/docker buildx build --platform linux/amd64,linux/arm64 \
    //     --no-cache \
    //     --progress plain \
    //     --pull --rm \
    //     --target image-${SELECTED_BRANCH_NAME} \
    //     --build-arg ENABLED_TESTS=${booleanToStr(ENABLED_TESTS)} \
    //     --build-arg ENABLED_COVERAGE=${booleanToStr(ENABLED_COVERAGE)} \
    //     -f \"Dockerfile-alpine-multi-arch\" \
    //     -t ${MODULE_CORE_IMAGE_NAME}:${MODULE_CORE_IMAGE_TAG} \".\""

    //   MODULE_CORE_IMAGE_ID = sh(
    //     script: "${DOCKER_PATH}/docker images --filter=reference=${MODULE_CORE_IMAGE_NAME}:${MODULE_CORE_IMAGE_TAG} --format {{.ID}}",
    //     returnStdout: true
    //   ).trim()

    //   def CONTAINER_CREATED = sh(
    //     script: "${DOCKER_PATH}/docker inspect -f {{.State.Status}} ${MODULE_CORE_CONTAINER_NAME}",
    //     returnStatus: true
    //   ) == 0
    //   if (CONTAINER_CREATED == false) {
    //     sh "${DOCKER_PATH}/docker buildx create --use \
    //       --name ${MODULE_CORE_CONTAINER_NAME} node-amd64 ${MODULE_CORE_IMAGE_NAME}:${MODULE_CORE_IMAGE_TAG}"
    //     sh "${DOCKER_PATH}/docker buildx create --append \
    //       --name ${MODULE_CORE_CONTAINER_NAME} node-arm64"
    //   }

    //   MODULE_CORE_CONTAINER_ID = sh(
    //     script: "${DOCKER_PATH}/docker ps -aqf \"name=${MODULE_CORE_CONTAINER_NAME}\"",
    //     returnStdout: true
    //   ).trim()
    // }

    stage("Build:docker wasm") {
      sh "echo Build:Dockerfile-wasm"
      // docker build --no-cache --pull --rm \
      // --progress plain \
      // --target image-develop \
      // --build-arg ENABLED_TESTS=OFF \
      // --build-arg ENABLED_COVERAGE=OFF \
      // -f "Dockerfile-wasm" \
      // -t sway/module_core:latest-wasm "."
    }

    stage("Tests") {
      if (ENABLED_TESTS) {
        if (ENABLED_DOCKER) {
        // [--rm] - to delete the container once finished the process
        // [  -i] - interactive mode
        // [  -e] - entrypoint
        def RESULT = sh(
          script: "${DOCKER_PATH}/docker start -i ${MODULE_CORE_CONTAINER_ID}", 
          returnStdout: true
        ).trim()
        // sh "echo ${RESULT}"
        } else {
          dir("./bin") {
            if (SELECTED_BUILD_TYPE == "debug") {
              sh "./dbg/module_core_tests"
            } else {
              sh "./module_core_tests"
            }
          }
        }
      } else {
        println "echo Tests is disabled"
      }
    }

    stage("Codecov") {
      if (ENABLED_COVERAGE && SELECTED_BRANCH_NAME == "master") {
        sh "/opt/homebrew/opt/lcov/bin/lcov --directory ./build/ --capture --output-file ./code_coverage.info -rc lcov_branch_coverage=1"
        sh "/opt/homebrew/opt/lcov/bin/genhtml code_coverage.info --branch-coverage --output-directory ./code_coverage_report/"
        publishHTML(target: [
          allowMissing: false,
          alwaysLinkToLastBuild: false,
          keepAll: true,
          reportDir: "code_coverage_report",
          reportFiles: "index.html",
          reportName: "LCov Report"
        ])

        withCredentials([string(credentialsId: "MODULE_CORE_CODECOV_TOKEN", variable: "CODECOV")]) {
          sh "curl -s https://codecov.io/bash | bash -s - -t $CODECOV || echo \"Codecov failed to upload\""
        }
      }
    }

    stage("Push") {
      sh "echo Push"
    }

    stage("Deploy") {
      sh "echo Deploy"
    }
  } finally {
    stage("cleanup") {
      sh "${DOCKER_PATH}/docker rm --force ${MODULE_CORE_CONTAINER_ID}"
      sh "${DOCKER_PATH}/docker rmi ${MODULE_CORE_IMAGE_ID}"
    }
  }
}
