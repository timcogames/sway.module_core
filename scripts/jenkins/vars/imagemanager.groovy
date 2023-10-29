#!/usr/bin/env groovy

import org.docker.Entity

class ImageManager {
  private String docker_
  private List<Entity> images_

  ImageManager(String dockerPath) {
    this.docker_ = "${dockerPath}/docker"
  }
}

ImageManager createImageManager(String dockerPath) {
  return new ImageManager(dockerPath)
}
