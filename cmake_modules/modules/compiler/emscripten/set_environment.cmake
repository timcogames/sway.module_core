#---------------------------------------------------------------------------------
#[[
# DESC
  Устанавливает окружение

# ARGS
  ARG1:STRING environment [IN] - Тип окружения (variants: "node,web")
  ARG2:STRING_LIST flags [OUT] - Флаги компиляции
 ]]
#---------------------------------------------------------------------------------
macro(set_emscripten_environment #[[ARG1]] environment 
                                 #[[ARG2]] flags)
  if(${environment} STREQUAL "web")
    set(${flags} "SHELL:-s ENVIRONMENT=${environment},worker")
    list(APPEND ${flags} "SHELL:-s EXPORT_ES6=1")
    list(APPEND ${flags} "SHELL:-s USE_ES6_IMPORT_META=0")
  elseif(${environment} STREQUAL "node")
    set(${flags} "SHELL:-s ENVIRONMENT=${environment}")
  else()
    message(FATAL_ERROR "[EMSCRIPTEN]: Invalid environment: ${environment}")
  endif()
endmacro(set_emscripten_environment)
