macro(set_emscripten_modularize #[[ARG]] proj_name_arg 
                                #[[ARG]] config_arg)
  set(${config_arg} ${${config_arg}} -s MODULARIZE=1 -s EXPORT_NAME="create_${proj_name_arg}_module")
endmacro(set_emscripten_modularize)
