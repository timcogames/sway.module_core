macro(emscripten_set_modularize #[[TARGET_NAME]] target_name_arg #[[CONFIG]] config_arg)
  set(${config_arg} ${${config_arg}} -sMODULARIZE=1 -sEXPORT_NAME="create_${target_name_arg}_module")
endmacro(emscripten_set_modularize)
