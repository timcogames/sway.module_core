macro(gen_emscripten_target_name #[[ARG]] output_target_arg 
                                 #[[ARG]] target_arg 
                                 #[[ARG]] environment_arg 
                                 #[[ARG]] compilation_arg)
  set(${output_target_arg} "${target_arg}_wasm")

  if(${environment_arg} STREQUAL "web")
    set(${output_target_arg} "${${output_target_arg}}_${environment_arg}")
  endif()

  if(${compilation_arg} STREQUAL "async")
    set(${output_target_arg} "${${output_target_arg}}_${compilation_arg}")
  endif()
endmacro(gen_emscripten_target_name)
