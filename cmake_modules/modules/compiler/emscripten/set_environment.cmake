macro(set_emscripten_environment #[[ARG]] output_flags_arg 
                                 #[[ARG]] environment_arg)
  if(${environment_arg} STREQUAL "web")
    set(${output_flags_arg} "SHELL:-s ENVIRONMENT=${environment_arg},worker")
    list(APPEND ${output_flags_arg} "SHELL:-s EXPORT_ES6=1")
    list(APPEND ${output_flags_arg} "SHELL:-s USE_ES6_IMPORT_META=0")
  elseif(${environment_arg} STREQUAL "node")
    set(${output_flags_arg} "SHELL:-s ENVIRONMENT=${environment_arg}")
  else()
    message(FATAL_ERROR "[EMSCRIPTEN]: Invalid environment: ${environment_arg}")
  endif()
endmacro(set_emscripten_environment)

macro(set_emscripten_environment_deprecated #[[ARG]] output_flags_arg 
                                            #[[ARG]] environment_arg)
  if(${environment_arg} STREQUAL "web")
    set(${output_flags_arg} ${${output_flags_arg}} -s ENVIRONMENT=web,worker
                                                   -s EXPORT_ES6=1 
                                                   -s USE_ES6_IMPORT_META=0)
  elseif(${environment_arg} STREQUAL "node")
    set(${output_flags_arg} ${${output_flags_arg}} -s ENVIRONMENT=node)
  else()
    message(FATAL_ERROR "[EMSCRIPTEN]: Invalid environment: ${environment_arg}")
  endif()
endmacro(set_emscripten_environment_deprecated)
