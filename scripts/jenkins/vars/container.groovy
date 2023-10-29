#!/usr/bin/env groovy

import org.docker.Entity

class Container implements Entity {
  private String docker_
  private String name_

  Container(String dockerPath, String name) {
    this.docker_ = "${dockerPath}/docker"
    this.name_ = name
  }

  // override
  String name() {
    return this.name_;
  }
}

Container createContainer(String dockerPath, String name) {
  return new Container(dockerPath, name)
}

def isBuildxExists(String dockerPath, String containerName) {
  return sh(
    script: "${dockerPath}/docker buildx inspect ${containerName}-cntr",
    returnStdout: true
  ) == 0
}

def isExists(String dockerPath, String containerName) {
  return sh(
    script: "${dockerPath}/docker inspect -f {{.State.Status}} ${containerName}",
    returnStdout: true
  ) == 0
}

def createBuildx(String dockerPath, String containerName, String platforms) {
  sh "${dockerPath}/docker buildx create \
    --use \
    --bootstrap \
    --name ${containerName}-cntr \
    --platform ${platforms} \
    --driver docker-container"
}

def create(String dockerPath, String containerName, String imageFullname) {
  sh "${dockerPath}/docker create \
    --name ${containerName} \
    ${imageFullname}"
}

def getId(String dockerPath, String containerName) {
  return sh(
    script: "${dockerPath}/docker ps -aqf \"name=${containerName}\"",
    returnStdout: true
  ).trim()
}

return this
