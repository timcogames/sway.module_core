function(emscripten_set_async #[[FLAGS]] flags_arg #[[VALUE]] value_arg)
  set(${flags_arg} ${${flags_arg}} -sASYNCIFY=${value_arg} PARENT_SCOPE)
endfunction(emscripten_set_async)
