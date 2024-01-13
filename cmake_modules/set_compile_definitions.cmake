#--------------------------------------------------------------------------------
#[[
# DESC
  Устанавливает макросы по умолчанию, с которыми собирается цель

# ARGS
  ARG1:TARGET proj_name [IN] - 
  ARG2:TARGET target [IN] - Цель
 ]]
#--------------------------------------------------------------------------------
function(set_compile_definitions #[[ARG1]] proj_name
                                 #[[ARG2]] target)
  string(TOUPPER ${proj_name} proj_name_in_uppercase)

  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${target} PUBLIC -DMODULE_${proj_name_in_uppercase}_DEBUG)
  endif()

  if((GLOB_EMSCRIPTEN_PLATFORM AND NOT GLOB_EMSCRIPTEN_USE_BINDINGS) OR MODULE_${proj_name_in_uppercase}_LIB_TYPE STREQUAL "shared")
    target_compile_definitions(${target} PUBLIC -DMODULE_${proj_name_in_uppercase}_INTERFACE_EXPORT)
  endif()
endfunction(set_compile_definitions)
