#--------------------------------------------------------------------------------
#[[
# DESC
  Создает конкретную библиотеку

# ARGS
  ARG1:TARGET target [IN] - Цель
 ]]
#--------------------------------------------------------------------------------
function(create_clang_library #[[ARG1]] target)
  string(TOUPPER ${target} target_name_in_uppercase)
  set(CURRENT_BUILD_TYPE ${target_name_in_uppercase}_LIB_TYPE)

  if(${CURRENT_BUILD_TYPE} STREQUAL "shared")
    if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
      set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
    endif()

    add_library(${target} SHARED $<TARGET_OBJECTS:${target}_obj>)
  elseif(${CURRENT_BUILD_TYPE} STREQUAL "static")
    add_library(${target} STATIC $<TARGET_OBJECTS:${target}_obj>)
  endif()

  # set_target_properties(${target_arg} PROPERTIES OUTPUT_NAME ${META_CORE_PRJNAME})
  # set_target_properties(${target_arg} PROPERTIES SUFFIX ".a.${META_CORE_VERSION}")
endfunction(create_clang_library)
