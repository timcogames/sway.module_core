#!/usr/bin/env groovy

import org.docker.Entity

class Image implements Entity {
  private String docker_
  private ImageName name_

  Image(String dockerPath, String name, String tag) {
    this.docker_ = "${dockerPath}/docker"
    this.name_ = new ImageName(name, tag)
  }

  // override
  String name() {
    def (name, tag) = this.name_.toList()
    return "${name}:${tag}";
  }

  String id(step) {
    return step.sh(
      script: "${this.docker_} images --filter=reference=${this.name()} --format {{.ID}}",
      returnStdout: true
    ).trim()
  }
}

Image createImage(String dockerPath, String name, String tag) {
  new Image(dockerPath, name, tag)
}

return this
