#--------------------------------------------------------------------------------
#[[
# DESC
  Устанавливает тип компиляции

# ARGS
  ARG1:STRING compilation [IN] - Тип компиляции (variants: "sync,async")
  ARG2:STRING_LIST flags [OUT] - Флаги компиляции
 ]]
#--------------------------------------------------------------------------------
macro(set_emscripten_compilation #[[ARG1]] compilation 
                                 #[[ARG2]] flags)
  if(${compilation} STREQUAL "async")
    set(${flags} "SHELL:-s WASM_ASYNC_COMPILATION=1")
  elseif(${compilation} STREQUAL "sync")
    set(${flags} "SHELL:-s WASM_ASYNC_COMPILATION=0")
  else()
    message(FATAL_ERROR "[EMSCRIPTEN]: Invalid compilation: ${compilation}")
  endif()
endmacro(set_emscripten_compilation)
