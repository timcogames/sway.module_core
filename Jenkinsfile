@Library("sway_jenkins_pipeline_docker") _

import org.jenkinsci.plugins.pipeline.modeldefinition.Utils

import java.util.Optional
import sway.jenkins_pipeline.docker.model.OSType
import sway.jenkins_pipeline.docker.model.ArchitectureType
import sway.jenkins_pipeline.docker.model.TargetPlatform
import sway.jenkins_pipeline.docker.entity.Entity
import sway.jenkins_pipeline.docker.entity.ImageEntity
import sway.jenkins_pipeline.docker.command.Command
import sway.jenkins_pipeline.docker.command.BuildImageCommand
import sway.jenkins_pipeline.docker.command.CommandHandler
import sway.jenkins_pipeline.docker.command.BuildImageCommandHandler
import sway.jenkins_pipeline.docker.command.CommandResult
import sway.jenkins_pipeline.docker.shell.Executor
import sway.jenkins_pipeline.docker.shell.ScriptExecutor

def base
def dockerContainer
def dockerImage

def DOCKER_PATH = "/Applications/Docker.app/Contents/Resources/bin"
def CMAKE_PATH = "/opt/homebrew/Cellar/cmake/3.22.1/bin"

def MODULE_CORE_CONTAINER_NAME = "sway"
def MODULE_CORE_CONTAINER_ID = ""

def MODULE_CORE_IMAGE_BUILD_CACHE_TAG = "buildcache"
def MODULE_CORE_IMAGE_TAG = "latest"
def MODULE_CORE_IMAGE_NAME = "${MODULE_CORE_CONTAINER_NAME}/module_core"
def MODULE_CORE_IMAGE_FULLNAME = "${MODULE_CORE_IMAGE_NAME}:${MODULE_CORE_IMAGE_TAG}"
def MODULE_CORE_IMAGE_ID = ""

def SELECTED_BRANCH_NAME = ""
def SELECTED_BUILD_TYPE = ""
def SELECTED_PLATFORN_LIST = []
def SELECTED_PLATFORN_LIST_STR = ""
def MULTIPLE_PLATFORN = false
def APPLIED_THIRD_PARTY_DIR = ""
def ENABLED_TESTS = ""
def ENABLED_COVERAGE = ""

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

      // ImageEntityCall()
      dir("scripts") {
        // def request = libraryResource "request.json"
        base = load "sway.jenkins_pipeline-docker/vars/Utils.groovy"
        base.approveSignatures([
          // "method groovy.json.JsonBuilder call java.util.List",
          // "method groovy.json.JsonSlurper parseText java.lang.String",
          // "method groovy.json.JsonSlurperClassic parseText",
          // "method groovy.lang.Binding getVariable java.lang.String",
          // "method groovy.lang.Binding getVariables"
        ])
      }
    }

    stage("Build options") {
      def optionParams = [ choice(name: "BUILD_TYPE", choices: "debug\nrelease", description: "Select the build type") ]

      def archVariants = [ "arm64/v8": true, "amd64": false ]
      archVariants.each { arch -> 
        optionParams.add(booleanParam(name: arch.key, defaultValue: arch.value))
      }

      optionParams.add(string(name: "THIRD_PARTY_DIR", defaultValue: "/opt/third_party", description: ""))
      optionParams.add(booleanParam(name: "TESTS", defaultValue: true, description: ""))
      optionParams.add(booleanParam(name: "COVERAGE", defaultValue: false, description: ""))

      def options = input(message: "Build options", ok: "Run", parameters: optionParams)

      archVariants.each {
        if (options."${it.key}") {
          SELECTED_PLATFORN_LIST.add("linux/${it.key}");
        }
      }

      SELECTED_BUILD_TYPE = options["BUILD_TYPE"]
      SELECTED_PLATFORN_LIST_STR = SELECTED_PLATFORN_LIST.join(",")
      MULTIPLE_PLATFORN = SELECTED_PLATFORN_LIST.size() > 1
      APPLIED_THIRD_PARTY_DIR = options["THIRD_PARTY_DIR"]
      ENABLED_TESTS = options["TESTS"]
      ENABLED_COVERAGE = options["COVERAGE"]
    }

    stage("Prebuild:docker gcc-linux-xarch") {
      if (MULTIPLE_PLATFORN) {
        // def containerExists = dockerContainer.isBuildxExists(DOCKER_PATH, MODULE_CORE_CONTAINER_NAME)
        // if (containerExists) {
        //   echo "${MODULE_CORE_CONTAINER_NAME}-cntr already exists..."
        // } else {
        //   dockerContainer.createBuildx(DOCKER_PATH, MODULE_CORE_CONTAINER_NAME, SELECTED_PLATFORN_LIST_STR)
        // }
      }
    }

    stage("Build:docker gcc-linux-xarch") {
      if (MULTIPLE_PLATFORN) {
        if (SELECTED_BRANCH_NAME != "master") {
          echo "Skipping stage..."
          Utils.markStageSkippedForConditional("Build/Push:docker gcc-linux-xarch")
        } else {
          sh "${DOCKER_PATH}/docker buildx bake \
            --builder ${MODULE_CORE_CONTAINER_NAME}-cntr \
            --set image.args.ENABLED_COVERAGE=${base.booleanToCMakeStr(ENABLED_COVERAGE)} \
            -f \"gcc-linux-xarch.hcl\" module_core-${SELECTED_BUILD_TYPE}"
        }
      } else {
        def targetPlatform = SELECTED_PLATFORN_LIST_STR.tokenize("/")[0];
        def targetArch = SELECTED_PLATFORN_LIST_STR.substring(targetPlatform.size() + 1)


        // def reference = "${MODULE_CORE_IMAGE_BUILD_CACHE_TAG}-${targetArch.replace("/", "_")}"
        def platform = new TargetPlatform(OSType.LINUX, ArchitectureType.AARCH64)

        String dockerFile = "/gcc-linux-xarch.dockerfile"
        String dockerEnvFile = "" // "/docker.env"
        Map<String, String> envs = []
        Map<String, String> args = [
          "ENABLED_COVERAGE": base.booleanToCMakeStr(ENABLED_COVERAGE),
          "ENABLED_TESTS": base.booleanToCMakeStr(ENABLED_TESTS)
        ]

        Entity imageEntity = new ImageEntity(MODULE_CORE_IMAGE_NAME, "${MODULE_CORE_IMAGE_TAG}-${targetArch.replace("/", "_")}", platform)
        Command imageCommand = new BuildImageCommand(imageEntity, 
          "$WORKSPACE", dockerFile, dockerEnvFile, envs, args, "module_core-${SELECTED_BUILD_TYPE}")

        Executor executor = ScriptExecutor(DOCKER_PATH)
        CommandHandler imageCommandHandler = new BuildImageCommandHandler(executor)
        imageCommandHandler.handle(imageCommand)

        // def image = new ImageEntity(MODULE_CORE_IMAGE_NAME, reference, platform)
        // def imageCommand = new BuildImageCommand(image.nameWithTag(), image.platform, "$WORKSPACE/gcc-linux-xarch.Dockerfile", [
        //   "ENABLED_TESTS": base.booleanToCMakeStr(ENABLED_TESTS), "ENABLED_COVERAGE": base.booleanToCMakeStr(ENABLED_COVERAGE) ],
        //   "$WORKSPACE")

        // imageCommand.line.addTarget("module_core-${SELECTED_BUILD_TYPE}")

        // def imageCommandHandler = new BuildImageCommandHandler(DOCKER_PATH)

        // def result = imageCommandHandler.execute(imageCommand)
        // echo result.message



        // MODULE_CORE_IMAGE_ID = dockerImageObject.id(this)
        // echo dockerImage.id(this)
      }
    }

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
        def RESULT = sh(
          script: "${DOCKER_PATH}/docker start -i ${MODULE_CORE_CONTAINER_ID}", 
          returnStdout: true
        ).trim()
        // sh "echo ${RESULT}"
      } else {
        echo "Skipping stage..."
        Utils.markStageSkippedForConditional("Tests")
      }
    }

    stage("Push:docker") {
      if (MULTIPLE_PLATFORN) {
        def cacheFromSet = []
        for (platform in SELECTED_PLATFORN_LIST) {
          def targetPlatform = platform.tokenize("/")[0];
          def targetArch = platform.substring(targetPlatform.size() + 1)

          cacheFromSet.add("--cache-from ${MODULE_CORE_IMAGE_NAME}:${MODULE_CORE_IMAGE_BUILD_CACHE_TAG}-${targetArch}")
        }

        sh "${DOCKER_PATH}/docker buildx --push ${cacheFromSet.join(" ")} \
          --platform ${SELECTED_PLATFORN_LIST_STR} \
          -t ${MODULE_CORE_IMAGE_NAME}:${MODULE_CORE_IMAGE_TAG} \".\""
      } else {
        def targetPlatform = SELECTED_PLATFORN_LIST_STR.tokenize("/")[0];
        def targetArch = SELECTED_PLATFORN_LIST_STR.substring(targetPlatform.size() + 1)

        sh "${DOCKER_PATH}/docker build \
          --cache-from ${MODULE_CORE_IMAGE_NAME}:${MODULE_CORE_IMAGE_BUILD_CACHE_TAG}-${targetArch.replace("/", "_")} \
          --target module_core-${SELECTED_BUILD_TYPE} \
          -f \"gcc-linux-xarch.Dockerfile\" \
          -t ${MODULE_CORE_IMAGE_NAME}:${MODULE_CORE_IMAGE_TAG} \".\""

        // def containerExists = dockerContainer.isExists(DOCKER_PATH, MODULE_CORE_CONTAINER_NAME)
        // if (containerExists) {
        //   echo "${MODULE_CORE_CONTAINER_NAME} already exists..."
        // } else {
        //   dockerContainer.create(DOCKER_PATH, MODULE_CORE_CONTAINER_NAME, MODULE_CORE_IMAGE_FULLNAME)
        // }

        // MODULE_CORE_CONTAINER_ID = dockerContainer.getId(DOCKER_PATH, MODULE_CORE_CONTAINER_NAME)
        // // MODULE_CORE_IMAGE_ID = dockerImage.getId(DOCKER_PATH, MODULE_CORE_IMAGE_FULLNAME)
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
      } else {
        echo "Skipping stage..."
        Utils.markStageSkippedForConditional("Codecov")
      }
    }

    stage("Deploy") {
      sh "echo Deploy"
    }
  } finally {
    stage("cleanup") {
      if (MULTIPLE_PLATFORN) {
        // 
      } else {
        // sh "${DOCKER_PATH}/docker rm --force ${MODULE_CORE_CONTAINER_ID}"
        // sh "${DOCKER_PATH}/docker rmi ${MODULE_CORE_IMAGE_ID}"
      }
    }
  }
}
