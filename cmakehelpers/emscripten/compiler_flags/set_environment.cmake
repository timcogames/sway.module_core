macro(emscripten_set_environment #[[FLAGS]] flags_arg)
  if(GLOB_EMSCRIPTEN_WEB_ENVIRONMENT)
    set(${flags_arg} ${${flags_arg}} -sENVIRONMENT=web,worker
                                     -sEXPORT_ES6=1 -sUSE_ES6_IMPORT_META=0)
  else()
    set(${flags_arg} ${${flags_arg}} -sENVIRONMENT=node)
  endif()
endmacro(emscripten_set_environment)
