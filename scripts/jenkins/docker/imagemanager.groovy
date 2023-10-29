#!/usr/bin/env groovy

class ImageManager {
  private String docker_
  private List<Entity> images_

  ImageManager(String dockerPath) {
    this.docker_ = "${dockerPath}/docker"
  }
}
