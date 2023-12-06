#---------------------------------------------------------------------------------
#[[
# DESC
  Устанавливает макросы по умолчанию, с которыми собирается цель

# ARGS
  ARG1:TARGET target [IN] - Цель
 ]]
#---------------------------------------------------------------------------------
function(set_compile_definitions #[[ARG1]] target)
  string(TOUPPER ${target} TARGET_NAME_UPPER)

  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${target} PUBLIC -D${TARGET_NAME_UPPER}_DEBUG_BUILD)
  endif()
  
  if((GLOB_EMSCRIPTEN_PLATFORM AND NOT GLOB_EMSCRIPTEN_USE_BINDINGS) OR ${TARGET_NAME_UPPER}_SHARED_LIB)
    target_compile_definitions(${target} PUBLIC -DSHARED_LIB_EXPORT_API)
  endif()
endfunction(set_compile_definitions)
