#!/usr/bin/env groovy

package jenkins.docker

@RecordOptions(copyWith=true)
record ImageName(String name, String tag) { }
