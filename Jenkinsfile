@Library("sway_jenkins_pipeline_docker") _

import org.jenkinsci.plugins.pipeline.modeldefinition.Utils

import java.util.Optional
import sway.jenkins_pipeline.docker.model.OSType
import sway.jenkins_pipeline.docker.model.ArchitectureType
import sway.jenkins_pipeline.docker.model.TargetPlatform
import sway.jenkins_pipeline.docker.model.ContainerAction
import sway.jenkins_pipeline.docker.entity.Entity
import sway.jenkins_pipeline.docker.entity.ImageEntity
import sway.jenkins_pipeline.docker.entity.MultiarchImageEntity
import sway.jenkins_pipeline.docker.entity.ContainerEntity
import sway.jenkins_pipeline.docker.command.Command
import sway.jenkins_pipeline.docker.command.CommandHandler
import sway.jenkins_pipeline.docker.command.CommandResult
import sway.jenkins_pipeline.docker.command.BuildImageCommand
import sway.jenkins_pipeline.docker.command.BuildImageCommandHandler
import sway.jenkins_pipeline.docker.command.CreateContainerCommand
import sway.jenkins_pipeline.docker.command.CreateContainerCommandHandler
import sway.jenkins_pipeline.docker.command.CreateMultiarchImageCommand
import sway.jenkins_pipeline.docker.command.CreateMultiarchImageCommandHandler
import sway.jenkins_pipeline.docker.command.PushImageCommand
import sway.jenkins_pipeline.docker.command.PushImageCommandHandler
import sway.jenkins_pipeline.docker.command.PushMultiarchImageCommand
import sway.jenkins_pipeline.docker.command.PushMultiarchImageCommandHandler
import sway.jenkins_pipeline.docker.command.UpdateContainerStateCommand
import sway.jenkins_pipeline.docker.command.UpdateContainerStateCommandHandler
import sway.jenkins_pipeline.docker.command.RemoveContainerCommand
import sway.jenkins_pipeline.docker.command.RemoveContainerCommandHandler
import sway.jenkins_pipeline.docker.command.RemoveImageCommand
import sway.jenkins_pipeline.docker.command.RemoveImageCommandHandler
import sway.jenkins_pipeline.docker.command.RunContainerScenarioCommand
import sway.jenkins_pipeline.docker.command.RunContainerScenarioCommandHandler
import sway.jenkins_pipeline.docker.query.ImageInspectQuery
import sway.jenkins_pipeline.docker.query.ImageInspectQueryHandler
import sway.jenkins_pipeline.docker.query.ContainerInspectQuery
import sway.jenkins_pipeline.docker.query.ContainerInspectQueryHandler
import sway.jenkins_pipeline.docker.query.GetIdContainerQuery
import sway.jenkins_pipeline.docker.query.GetIdContainerQueryHandler
import sway.jenkins_pipeline.docker.shell.Executor
import sway.jenkins_pipeline.docker.shell.ScriptExecutor

String GIT_PATH = "/usr/bin"
String DOCKER_PATH = "/Applications/Docker.app/Contents/Resources/bin"
String CMAKE_PATH = "/opt/homebrew/Cellar/cmake/3.22.1/bin"

String MODULE_CORE_CONTAINER_ID = ""
String MODULE_CORE_CONTAINER_NAME = "cntr"

String MODULE_CORE_IMAGE_ID = ""
String MODULE_CORE_IMAGE_REGISTRY_NAMESPACE = "bonus85"
String MODULE_CORE_IMAGE_LOCAL_NAMESPACE = "local"
String MODULE_CORE_IMAGE_NAME = "sway.module_core"
String MODULE_CORE_IMAGE_TAG = "latest"
String MODULE_CORE_IMAGE_REFERENCE_NAME = "${MODULE_CORE_IMAGE_NAME}:${MODULE_CORE_IMAGE_TAG}"

def SELECTED_BRANCH_NAME = ""
def SELECTED_BUILD_TYPE = ""
def SELECTED_PLATFORN_LIST = []
def SELECTED_PLATFORN_LIST_STR = ""
def MULTIPLE_PLATFORN = false
def APPLIED_THIRD_PARTY_DIR = ""
def ENABLED_TESTS = ""
def ENABLED_COVERAGE = ""
def PUBLISH_COVERAGE_REPORT = false

def base

ContainerEntity dockerContainerEntity = new ContainerEntity(MODULE_CORE_CONTAINER_NAME)
MultiarchImageEntity dockerMultiarchImageEntity = new MultiarchImageEntity(MODULE_CORE_IMAGE_REGISTRY_NAMESPACE, MODULE_CORE_IMAGE_NAME, MODULE_CORE_IMAGE_TAG)
List<ImageEntity> dockerImageEntities = new ArrayList<ImageEntity>()

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
      sh "${GIT_PATH}/git submodule update --init --recursive"

      // ImageEntityCall()
      dir("scripts") {
        // def request = libraryResource "request.json"
        base = load "sway.jenkins_pipeline-docker/vars/Utils.groovy"

        // TODO
        base.approveSignatures([
          "new java.util.ArrayList",
          "new java.util.Optional java.lang.Object"
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
      optionParams.add(booleanParam(name: "COVERAGE_REPORT", defaultValue: false, description: ""))

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
      PUBLISH_COVERAGE_REPORT = options["COVERAGE_REPORT"]
    }

    stage("Build:docker gcc-linux-xarch") {
      // def targetPlatform = SELECTED_PLATFORN_LIST_STR.tokenize("/")[0];
      // def targetArch = SELECTED_PLATFORN_LIST_STR.substring(targetPlatform.size() + 1)

      List<TargetPlatform> platforms = [ 
        new TargetPlatform(OSType.LINUX, ArchitectureType.AARCH64)
        // new TargetPlatform(OSType.LINUX, ArchitectureType.X64) 
        ]

      platforms.eachWithIndex { item, index ->
        dockerImageEntities.add(new ImageEntity(MODULE_CORE_IMAGE_LOCAL_NAMESPACE, MODULE_CORE_IMAGE_NAME, MODULE_CORE_IMAGE_TAG, item))
        
        Map<String, String> envs = [:]
        Map<String, String> args = [
          "ENABLED_COVERAGE": base.booleanToCMakeStr(ENABLED_COVERAGE),
          "ENABLED_TESTS": base.booleanToCMakeStr(ENABLED_TESTS)
        ]

        BuildImageCommand buildImageCmd = new BuildImageCommand(dockerImageEntities.get(index), 
          "${env.WORKSPACE}", "gcc-linux-xarch.Dockerfile", envs, args, "module_core-${SELECTED_BUILD_TYPE}")
        BuildImageCommandHandler buildImageCmdHandler = new BuildImageCommandHandler(new ScriptExecutor(DOCKER_PATH))
        CommandResult<String> buildImageCmdHandlerResult = buildImageCmdHandler.handle(buildImageCmd)

        if (buildImageCmdHandlerResult.succeeded) {
          ImageInspectQuery imageInspectQry = new ImageInspectQuery(dockerImageEntities.get(index))
          ImageInspectQueryHandler imageInspectQryHandler = new ImageInspectQueryHandler(new ScriptExecutor(DOCKER_PATH))
          Map<String, String> imageInspectQryHandlerResult = imageInspectQryHandler.handle(imageInspectQry)
          dockerImageEntities.get(index).setId(imageInspectQryHandlerResult.id)
        }
      }
    }

    stage("Build:docker wasm") {
      sh "echo Build:Dockerfile-wasm"
    }

    stage("Start:docker") {
      ContainerInspectQuery containerInspectQry = new ContainerInspectQuery(dockerContainerEntity)
      ContainerInspectQueryHandler containerInspectQryHandler = new ContainerInspectQueryHandler(new ScriptExecutor(DOCKER_PATH))
      Optional<Map<String, String>> containerInspectQryResult = containerInspectQryHandler.handle(containerInspectQry)

      boolean containerExists = containerInspectQryResult.get().status != null
      if (containerExists) {
        echo "${MODULE_CORE_CONTAINER_NAME} already exists..."
      } else {
        CreateContainerCommand createContainerCmd = new CreateContainerCommand(dockerContainerEntity, dockerImageEntities.get(0))
        CreateContainerCommandHandler createContainerCmdHandler = new CreateContainerCommandHandler(new ScriptExecutor(DOCKER_PATH))
        CommandResult<String> createContainerCmdResult = createContainerCmdHandler.handle(createContainerCmd)
        if (createContainerCmdResult.succeeded) {
          echo "CreateContainerCommand : ${createContainerCmdResult.message}"
        }
      }

      GetIdContainerQuery getIdContainerQry = new GetIdContainerQuery(dockerContainerEntity)
      GetIdContainerQueryHandler getIdContainerQryHandler = new GetIdContainerQueryHandler(new ScriptExecutor(DOCKER_PATH))
      Optional<String> containerIdOpt = getIdContainerQryHandler.handle(getIdContainerQry)
      dockerContainerEntity.setId(containerIdOpt.get())

      UpdateContainerStateCommand updateContainerStateCmd = new UpdateContainerStateCommand(dockerContainerEntity, ContainerAction.START)
      UpdateContainerStateCommandHandler updateContainerStateCmdHandler = new UpdateContainerStateCommandHandler(new ScriptExecutor(DOCKER_PATH))
      updateContainerStateCmdHandler.handle(updateContainerStateCmd)
    }

    stage("Run:Tests") {
      if (ENABLED_TESTS) {
        RunContainerScenarioCommand runContainerScenarioCmd = new RunContainerScenarioCommand(dockerContainerEntity, 
          (SELECTED_BUILD_TYPE == "debug") ? "./bin/dbg/module_core_tests" : "./bin/module_core_tests")
        RunContainerScenarioCommandHandler runContainerScenarioCmdHandler = new RunContainerScenarioCommandHandler(new ScriptExecutor(DOCKER_PATH))
        runContainerScenarioCmdHandler.handle(runContainerScenarioCmd)
      } else {
        echo "Skipping stage..."
        Utils.markStageSkippedForConditional("Run:Tests")
      }
    }

    stage("Push:docker") {
      // withCredentials([[$class: "UsernamePasswordMultiBinding", credentialsId: "DOCKER_HUB_TOKEN", usernameVariable: "DOCKER_REGISTRY_USER", passwordVariable: "DOCKER_REGISTRY_TOKEN"]]) {
      //   echo "$DOCKER_REGISTRY_TOKEN | ${DOCKER_PATH}/docker login https://hub.docker.com/v2/ -u=victor-timoshin@hotmail.com --password-stdin"
      // }

      // dockerImageEntities.each { item ->
      //   PushImageCommand pushImageCmd = new PushImageCommand(item, MODULE_CORE_IMAGE_REGISTRY_NAMESPACE)
      //   PushImageCommandHandler pushImageCmdHandler = new PushImageCommandHandler(scriptExec)
      //   CommandResult<String> pushImageCmdResult = pushImageCmdHandler.handle(pushImageCmd)
      //   echo ">> ${pushImageCmdResult.message}"
      // }

      // CreateMultiarchImageCommand createMAImageCmd = new CreateMultiarchImageCommand(dockerMultiarchImageEntity, dockerImageEntities)
      // CreateMultiarchImageCommandHandler createMAImageCmdHandler = new CreateMultiarchImageCommandHandler(scriptExec)
      // CommandResult<String> createMAImageCmdResult = createMAImageCmdHandler.handle(createMAImageCmd)
      // echo ">> ${createMAImageCmdResult.message}"

      // PushMultiarchImageCommand pushMAImageCmd = new PushMultiarchImageCommand(dockerMultiarchImageEntity, MODULE_CORE_IMAGE_REGISTRY_NAMESPACE)
      // PushMultiarchImageCommandHandler pushMAImageCmdHandler = new PushMultiarchImageCommandHandler(scriptExec)
      // CommandResult<String> pushMAImageCmdResult = pushMAImageCmdHandler.handle(pushMAImageCmd)
      // echo ">> ${pushMAImageCmdResult.message}"

      // def RESULT = sh(
      //   script: "${DOCKER_PATH}/docker manifest push ${MODULE_CORE_IMAGE_REGISTRY_NAMESPACE}/${MODULE_CORE_IMAGE_REFERENCE_NAME}", 
      //   returnStdout: true
      // ).trim()

      // echo ">> ${RESULT}"
    }

    stage("Codecov") {
      if (ENABLED_TESTS && ENABLED_COVERAGE) {
        String PROJECT_ROOT_DIR = "."
        String PROJECT_SOURCE_DIR = "${PROJECT_ROOT_DIR}/build"
        String OUTPUT_DIR = "${PROJECT_ROOT_DIR}/lcov_report"
        String OUTPUT_FILE = "${OUTPUT_DIR}/coverage.info"
        String LCOV_ENABLE_COVERAGE_BRANCH = "--rc lcov_branch_coverage=1"

        RunContainerScenarioCommand generateInfoCmd = new RunContainerScenarioCommand(dockerContainerEntity, "lcov \
          --base-directory ${PROJECT_ROOT_DIR}/ \
          --directory ${PROJECT_SOURCE_DIR} \
          --capture \
          --output-file ${OUTPUT_FILE}")
        RunContainerScenarioCommandHandler generateInfoCmdHandler = new RunContainerScenarioCommandHandler(new ScriptExecutor(DOCKER_PATH))
        generateInfoCmdHandler.handle(generateInfoCmd)

        String GENHTML_ENABLE_COVERAGE_BRANCH = "--branch-coverage"

        RunContainerScenarioCommand generateHTMLCmd = new RunContainerScenarioCommand(dockerContainerEntity, "genhtml ${OUTPUT_FILE} \
          --output-directory ${OUTPUT_DIR}")
        RunContainerScenarioCommandHandler generateHTMLCmdHandler = new RunContainerScenarioCommandHandler(new ScriptExecutor(DOCKER_PATH))
        generateHTMLCmdHandler.handle(generateHTMLCmd)

        sh "${DOCKER_PATH}/docker cp ${dockerContainerEntity.getId().get()}:/module_core_workspace/lcov_report/. ${env.WORKSPACE}/lcov_report"

        if (PUBLISH_COVERAGE_REPORT) {
          publishHTML(target: [
            allowMissing: false,
            alwaysLinkToLastBuild: false,
            keepAll: true,
            reportDir: OUTPUT_DIR,
            reportFiles: "index.html",
            reportName: "LCov Report"
          ])

          withCredentials([string(credentialsId: "MODULE_CORE_CODECOV_TOKEN", variable: "CODECOV")]) {
            sh "curl -s https://codecov.io/bash | bash -s - -t $CODECOV || echo \"Codecov failed to upload\""
          }
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
      UpdateContainerStateCommand updateContainerStateCmd = new UpdateContainerStateCommand(dockerContainerEntity, ContainerAction.STOP)
      UpdateContainerStateCommandHandler updateContainerStateCmdHandler = new UpdateContainerStateCommandHandler(new ScriptExecutor(DOCKER_PATH))
      updateContainerStateCmdHandler.handle(updateContainerStateCmd)

      RemoveContainerCommand removeContainerCmd = new RemoveContainerCommand(dockerContainerEntity)
      RemoveContainerCommandHandler removeContainerCmdHandler = new RemoveContainerCommandHandler(new ScriptExecutor(DOCKER_PATH))
      removeContainerCmdHandler.handle(removeContainerCmd)

      dockerImageEntities.each { item ->
        RemoveImageCommand removeImageCmd = new RemoveImageCommand(item)
        RemoveImageCommandHandler removeImageCmdHandler = new RemoveImageCommandHandler(new ScriptExecutor(DOCKER_PATH))
        removeImageCmdHandler.handle(removeImageCmd)
      }
    }
  }
}
