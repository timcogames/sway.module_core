#--------------------------------------------------------------------------------
#[[
# DESC
  Устанавливает флаги для ES6 модулей

# ARGS
  ARG1:STRING_LIST flags [IN/OUT] - Список флагов для модификации
  ARG2:STRING environment [IN] - Тип окружения ("node" или "web")
  ARG3:BOOL enable_import_meta [IN] - Включить USE_ES6_IMPORT_META (по умолчанию: OFF)
]]
#--------------------------------------------------------------------------------
macro(set_emscripten_es6_flags #[[ARG1]] flags
                               #[[ARG2]] environment
                               #[[ARG3]] enable_import_meta)
  list(APPEND ${flags} "SHELL:-s EXPORT_ES6=1")
  
  if(enable_import_meta)
    list(APPEND ${flags} "SHELL:-s USE_ES6_IMPORT_META=1")
  else()
    # Emscripten не позволяет установить USE_ES6_IMPORT_META=0, если в списке окружений 
    # присутствует Node.js. Это связано с тем, что для работы __dirname в ES модулях 
    # необходимо использовать import.meta, и отключить эту возможность нельзя
    if(NOT ${environment} STREQUAL "node")
      list(APPEND ${flags} "SHELL:-s USE_ES6_IMPORT_META=0")
    endif()
  endif()
endmacro()

#--------------------------------------------------------------------------------
#[[
# DESC
  Устанавливает окружение

# ARGS
  ARG1:STRING environment [IN] - Тип окружения (variants: "node, web")
  ARG2:STRING_LIST flags [OUT] - Флаги компиляции
  ARG3:BOOL use_es6 [IN] - Использовать ES6 модули (по умолчанию: OFF)
  ARG4:BOOL enable_import_meta [IN] - Включить USE_ES6_IMPORT_META (по умолчанию: OFF)
]]
#--------------------------------------------------------------------------------
macro(set_emscripten_environment #[[ARG1]] environment
                                 #[[ARG2]] flags
                                 #[[ARG3]] use_es6
                                 #[[ARG4]] enable_import_meta)
  if(${environment} STREQUAL "web")
    set(${flags} "SHELL:-s ENVIRONMENT=${environment},worker")
  elseif(${environment} STREQUAL "node")
    set(${flags} "SHELL:-s ENVIRONMENT=${environment}")
  else()
    message(FATAL_ERROR "[EMSCRIPTEN]: Invalid environment: ${environment}")
  endif()

  if(use_es6)
    set_emscripten_es6_flags(${flags} ${environment} ${enable_import_meta})
  endif()
endmacro()
