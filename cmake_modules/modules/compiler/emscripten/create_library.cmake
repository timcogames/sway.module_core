# Создает конкретную Emscripten библиотеку
#
# \arg:target_arg - Цель
# \arg:environment_arg - Тип окружения
# \arg:compilation_arg - Тип компиляции
# \arg:output_target_name_arg
#
function(create_emscripten_library_private #[[ARG]] target_arg 
                                           #[[ARG]] environment_arg 
                                           #[[ARG]] compilation_arg 
                                           #[[ARG]] output_target_name_arg)
  gen_emscripten_target_name(CURRENT_TARGET_NAME ${target_arg} ${environment_arg} ${compilation_arg})
  set(${output_target_name_arg} ${CURRENT_TARGET_NAME} PARENT_SCOPE)

  set_emscripten_environment(CURRENT_ENVIRONMENT ${environment_arg})
  set_emscripten_compilation(CURRENT_COMPILATION ${compilation_arg})

  add_executable(${CURRENT_TARGET_NAME} $<TARGET_OBJECTS:${target_arg}>)

  target_compile_options(${CURRENT_TARGET_NAME} PUBLIC -Wall -Wextra -Wundef -pedantic)
  printf_compile_options(${CURRENT_TARGET_NAME})

  # Build for webassembly target
  target_link_options(${CURRENT_TARGET_NAME} PUBLIC "SHELL:-s WASM=1" ${CURRENT_ENVIRONMENT} ${CURRENT_COMPILATION})

  if(${environment_arg} STREQUAL "node")
    set_target_properties(${CURRENT_TARGET_NAME} PROPERTIES LINK_FLAGS "--no-entry")
    # set_target_properties(${CURRENT_TARGET_NAME} PROPERTIES LINK_FLAGS "--no-entry --export-dynamic")
    # set_target_properties(${CURRENT_TARGET_NAME} PROPERTIES LINK_FLAGS "--no-entry --export-all")
    set_target_properties(${CURRENT_TARGET_NAME} PROPERTIES SUFFIX ".wasm")

    printf_link_flags(${CURRENT_TARGET_NAME})
  endif()

  # set_target_properties(${CURRENT_TARGET_NAME} PROPERTIES OUTPUT_NAME "${CURRENT_TARGET_NAME}.v1")
endfunction(create_emscripten_library_private)

#
# Создает Emscripten библиотеку
#
# \arg:target_arg - Цель
# \arg:environment_arg - Строка с типами окружения (прим.: "web,node")
# \arg:compilation_arg - Тип компиляции
#
function(create_emscripten_library #[[ARG]] target_arg 
                                   #[[ARG]] environment_arg 
                                   #[[ARG]] compilation_arg 
                                   #[[ARG]] output_target_name_list_arg)
  string(REPLACE "," ";" ENVIRONMENT_LIST ${environment_arg})
  list(LENGTH ENVIRONMENT_LIST ENVIRONMENT_LIST_LENGTH)

  if(${ENVIRONMENT_LIST_LENGTH} GREATER 0)
    list(GET ENVIRONMENT_LIST 0 ENVIRONMENT_STR)
    create_emscripten_library_private(${target_arg} ${ENVIRONMENT_STR} ${compilation_arg} OUTPUT_TARGET_NAME)
    set(${output_target_name_list_arg} ${${output_target_name_list_arg}} ${OUTPUT_TARGET_NAME})
  else()
    message(FATAL_ERROR "[EMSCRIPTEN]: Environment variable not set")
  endif()

  if(${ENVIRONMENT_LIST_LENGTH} GREATER 1)
    list(GET ENVIRONMENT_LIST 1 ENVIRONMENT_STR)
    create_emscripten_library_private(${target_arg} ${ENVIRONMENT_STR} ${compilation_arg} OUTPUT_TARGET_NAME)
    set(${output_target_name_list_arg} ${${output_target_name_list_arg}} ${OUTPUT_TARGET_NAME})
  endif()

  set(${output_target_name_list_arg} ${${output_target_name_list_arg}} PARENT_SCOPE)
endfunction(create_emscripten_library)
