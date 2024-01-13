function(project_metadata #[[ARG]] proj_name_arg 
                          #[[ARG]] version_arg)
  string(TOUPPER ${proj_name_arg} proj_name_in_uppercase)

  set(MODULE_${proj_name_in_uppercase}_PROJ_NAME "${proj_name_arg}" PARENT_SCOPE)
  set(MODULE_${proj_name_in_uppercase}_LIB_TARGET "module_${proj_name_arg}" PARENT_SCOPE)
  set(MODULE_${proj_name_in_uppercase}_OBJ_TARGET "module_${proj_name_arg}_obj" PARENT_SCOPE)
  set(MODULE_${proj_name_in_uppercase}_TEST_TARGET "module_${proj_name_arg}_tests" PARENT_SCOPE)
  set(MODULE_${proj_name_in_uppercase}_OUTPUT_LIB_NAME "module_${proj_name_arg}" PARENT_SCOPE)
  set(MODULE_${proj_name_in_uppercase}_OUTPUT_LIB_NAME_VER "module_${proj_name_arg}.v${version_arg}" PARENT_SCOPE)
  set(MODULE_${proj_name_in_uppercase}_VERSION "${version_arg}" PARENT_SCOPE)
endfunction(project_metadata)
