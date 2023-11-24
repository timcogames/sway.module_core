# function(emscripten_create_command_config #[[TARGET_NAME]] target_name_arg #[[CONFIG_NAME]] config_name_arg)
#   string(TOUPPER ${target_name_arg} target_name_upper)
#   string(TOUPPER ${config_name_arg} config_name_upper)

#   set(MODULE_${target_name_upper}_COMPILER_${config_name_upper}_CONFIG "" PARENT_SCOPE)
# endfunction(emscripten_create_command_config)

function(emscripten_set_compiler #[[CONFIG]] config_arg)
  set(${config_arg} "${GLOB_EMSCRIPTEN_ROOT_DIR}/em++" PARENT_SCOPE)
endfunction(emscripten_set_compiler)

function(emscripten_set_compiler_javascript #[[CONFIG]] config_arg 
  #[[BINARY_DIR]] binary_dir_arg #[[LIB_NAME_LIST]] lib_name_list_arg #[[VERSION]] version_arg)
  emscripten_set_compiler(${config_arg})

  list(REMOVE_DUPLICATES ${lib_name_list_arg})
  list(GET ${lib_name_list_arg} 0 OUTPUT_LIB_NAME)

  foreach(lib_name_var IN LISTS ${lib_name_list_arg})
    set(IN_LIB_NAME_LIST "${IN_LIB_NAME_LIST};${binary_dir_arg}/${lib_name_var}.bc")
  endforeach()

  set(${config_arg} ${${config_arg}} ${IN_LIB_NAME_LIST} -o \"${binary_dir_arg}/${OUTPUT_LIB_NAME}.${version_arg}.js\" PARENT_SCOPE)
endfunction(emscripten_set_compiler_javascript)
