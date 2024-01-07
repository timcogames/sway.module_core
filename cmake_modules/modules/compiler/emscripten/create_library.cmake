#---------------------------------------------------------------------------------
#[[
# DESC
  Создает конкретную Emscripten библиотеку

# ARGS
  ARG1:TARGET target [IN] - Цель
  ARG2:STRING environment [IN] - Тип окружения
  ARG3:STRING compilation [IN] - Тип компиляции
  ARG4:STRING target_name [OUT] - Имена цели
 ]]
#---------------------------------------------------------------------------------
function(create_emscripten_library_private #[[ARG1]] target 
                                           #[[ARG2]] environment 
                                           #[[ARG3]] compilation 
                                           #[[ARG4]] target_name)
  gen_emscripten_target_name(CURRENT_TARGET_NAME ${target} ${environment} ${compilation})
  set(${target_name} ${CURRENT_TARGET_NAME} PARENT_SCOPE)

  set_emscripten_environment(${environment} CURRENT_ENVIRONMENT)
  set_emscripten_compilation(${compilation} CURRENT_COMPILATION)

  add_executable(${CURRENT_TARGET_NAME} $<TARGET_OBJECTS:${target}>)

  target_compile_options(${CURRENT_TARGET_NAME} PUBLIC -Wall -Wextra -Wundef -pedantic)
  printf_compile_options(${CURRENT_TARGET_NAME})

  # Build for webassembly target
  target_link_options(${CURRENT_TARGET_NAME} PUBLIC "SHELL:-s WASM=1" ${CURRENT_ENVIRONMENT} ${CURRENT_COMPILATION})
  set_target_properties(${CURRENT_TARGET_NAME} PROPERTIES LINK_FLAGS "--no-entry")

  if(${environment} STREQUAL "node")
    # set_target_properties(${CURRENT_TARGET_NAME} PROPERTIES LINK_FLAGS "--no-entry --export-dynamic")
    # set_target_properties(${CURRENT_TARGET_NAME} PROPERTIES LINK_FLAGS "--no-entry --export-all")

    if(NOT GLOB_EMSCRIPTEN_USE_BINDINGS)
      set_target_properties(${CURRENT_TARGET_NAME} PROPERTIES SUFFIX ".wasm")
    endif()

    printf_link_flags(${CURRENT_TARGET_NAME})
  endif()

  # set_target_properties(${CURRENT_TARGET_NAME} PROPERTIES OUTPUT_NAME "${CURRENT_TARGET_NAME}.v1")
endfunction(create_emscripten_library_private)

#---------------------------------------------------------------------------------
#[[
# DESC
  Создает Emscripten библиотеку

# ARGS
  ARG1:TARGET target [IN] - Цель
  ARG2:STRING environment [IN] - Строка с типами окружения (прим.: "web,node")
  ARG3:STRING compilation [IN] - Тип компиляции
  ARG4:STRING_LIST target_name_list [OUT] - Список имен целей
 ]]
#---------------------------------------------------------------------------------
function(create_emscripten_library #[[ARG1]] target 
                                   #[[ARG2]] environment 
                                   #[[ARG3]] compilation 
                                   #[[ARG4]] target_name_list)
  string(REPLACE "," ";" ENVIRONMENT_LIST ${environment})
  if(NOT ENVIRONMENT_LIST) # Пустой список - пустая переменная, ее значение равно FALSE
    message(FATAL_ERROR "[EMSCRIPTEN]: Environment variable not set")
  endif()

  list(LENGTH ENVIRONMENT_LIST ENVIRONMENT_LIST_LENGTH)
  math(EXPR ENVIRONMENT_LIST_LENGTH "${ENVIRONMENT_LIST_LENGTH} - 1")

  foreach(INDEX RANGE ${ENVIRONMENT_LIST_LENGTH})
    list(GET ENVIRONMENT_LIST ${INDEX} ENVIRONMENT_STR)
    create_emscripten_library_private(${target} ${ENVIRONMENT_STR} ${compilation} OUTPUT_TARGET_NAME)
    set(${target_name_list} ${${target_name_list}} ${OUTPUT_TARGET_NAME})
  endforeach()

  set(${target_name_list} ${${target_name_list}} PARENT_SCOPE)
endfunction(create_emscripten_library)
