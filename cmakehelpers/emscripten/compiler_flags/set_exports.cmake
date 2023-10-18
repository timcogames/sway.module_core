function(emscripten_set_exports #[[FLAGS]] flags_arg #[[JSON_FILE]] json_file_arg)
  set(${flags_arg} ${${flags_arg}} -sEXPORTED_FUNCTIONS=@${json_file_arg} PARENT_SCOPE)
endfunction(emscripten_set_exports)

function(emscripten_set_runtime_exports #[[FLAGS]] flags_arg #[[JSON_FILE]] json_file_arg #[[RESERVED_FUNC_PTRS]] reserved_func_ptrs_arg)
  # RESERVED_FUNCTION_POINTERS совместно с addFunction, removeFunction
  set(${flags_arg} ${${flags_arg}} -sEXPORTED_RUNTIME_METHODS=@${json_file_arg} -sRESERVED_FUNCTION_POINTERS=${reserved_func_ptrs_arg} PARENT_SCOPE)
endfunction(emscripten_set_runtime_exports)
