#!/usr/bin/env groovy

package org.docker

@RecordOptions(copyWith=true)
record ImageName(String name, String tag) { }
