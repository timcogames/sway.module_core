include("${CMAKE_CURRENT_SOURCE_DIR}/cmakehelpers/emscripten/compiler_flags/set_modularize.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmakehelpers/emscripten/compiler_flags/set_environment.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmakehelpers/emscripten/compiler_flags/set_optimization.cmake")

function(emscripten_set_config #[[TARGET_NAME]] target_name_arg #[[CONFIG]] config_arg)
  emscripten_set_modularize(${target_name_arg} ${config_arg})
  emscripten_set_environment(${config_arg})
  emscripten_set_optimization(${config_arg})

  set(EMSCRIPTEN_COMPILER_FLAGS ${${config_arg}} -sWASM=1)
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s STRICT=1")
  set(${config_arg} ${EMSCRIPTEN_COMPILER_FLAGS} PARENT_SCOPE)
endfunction(emscripten_set_config)