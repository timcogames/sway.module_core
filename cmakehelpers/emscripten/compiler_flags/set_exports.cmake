function(emscripten_set_exports #[[FLAGS]] flags_arg #[[JSON_FILE]] json_file_arg)
  set(${flags_arg} ${${flags_arg}} -sEXPORTED_FUNCTIONS=@${json_file_arg} PARENT_SCOPE)
endfunction(emscripten_set_exports)

function(emscripten_set_runtime_exports #[[FLAGS]] flags_arg #[[JSON_FILE]] json_file_arg)
  set(${flags_arg} ${${flags_arg}} -sEXPORTED_RUNTIME_METHODS=@${json_file_arg} PARENT_SCOPE)
endfunction(emscripten_set_runtime_exports)
