#!/usr/bin/env groovy

def booleanToCMakeStr(Boolean val) {
  return (val) ? "ON" : "OFF"
}

return this
