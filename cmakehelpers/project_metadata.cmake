function(project_metadata #[[PROJ_NAME]] proj_name_arg #[[VERSION]] version_arg)
  string(TOUPPER ${proj_name_arg} proj_name_upper)

  set(MODULE_${proj_name_upper}_PROJ_NAME "${proj_name_arg}" PARENT_SCOPE)
  set(MODULE_${proj_name_upper}_VERSION "${version_arg}" PARENT_SCOPE)
  set(MODULE_${proj_name_upper}_LIB_NAME "libmodule_${proj_name_arg}" PARENT_SCOPE)
  set(MODULE_${proj_name_upper}_LIB_NAME_VER "libmodule_${proj_name_arg}.${version_arg}" PARENT_SCOPE)
endfunction(project_metadata)
