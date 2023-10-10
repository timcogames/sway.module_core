# function(emscripten_create_command_config #[[TARGET_NAME]] target_name_arg #[[CONFIG_NAME]] config_name_arg)
#   string(TOUPPER ${target_name_arg} target_name_upper)
#   string(TOUPPER ${config_name_arg} config_name_upper)

#   set(MODULE_${target_name_upper}_COMPILER_${config_name_upper}_CONFIG "" PARENT_SCOPE)
# endfunction(emscripten_create_command_config)

function(emscripten_set_compiler #[[CONFIG]] config_arg)
  set(${config_arg} "${GLOB_EMSCRIPTEN_ROOT_DIR}/em++" PARENT_SCOPE)
endfunction(emscripten_set_compiler)

function(emscripten_set_compiler_javascript #[[CONFIG]] config_arg 
  #[[BINARY_DIR]] binary_dir_arg #[[IO_LIB_NAME]] io_lib_name_arg #[[VERSION]] version_arg)
  emscripten_set_compiler(${config_arg})
  set(${config_arg} ${${config_arg}} \"${binary_dir_arg}/${io_lib_name_arg}.bc\" -o \"${binary_dir_arg}/${io_lib_name_arg}.${version_arg}.js\" PARENT_SCOPE)
endfunction(emscripten_set_compiler_javascript)
