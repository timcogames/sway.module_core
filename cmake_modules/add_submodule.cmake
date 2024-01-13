#--------------------------------------------------------------------------------
#[[
# DESC
  Add submodule

# ARGS
  ARG1:STRING name [IN] - 
  ARG2:STRING module_dir [IN] - 
 ]]
#--------------------------------------------------------------------------------
function(add_submodule #[[ARG1]] name
                       #[[ARG2]] module_dir)
  if(NOT TARGET ${name})
    add_subdirectory(${module_dir})
  endif()
endfunction(add_submodule)
