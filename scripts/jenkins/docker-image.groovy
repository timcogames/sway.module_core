#!/usr/bin/env groovy

def getBuildxId(String dockerPath, String containerName) {

}

def getId(String dockerPath, String imageFullname) {
  return sh(
    script: "${dockerPath}/docker images --filter=reference=${imageFullname} --format {{.ID}}",
    returnStdout: true
  ).trim()
}

return this
