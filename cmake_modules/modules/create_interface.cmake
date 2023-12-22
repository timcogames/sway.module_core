#---------------------------------------------------------------------------------
#[[
# DESC
  Create INTERFACE library

# ARGS
  ARG1:TARGET target [IN] - Library target
  ARG2:STRING_LIST object_list [IN] - 
 ]]
#---------------------------------------------------------------------------------
function(create_interface #[[ARG1]] target 
                          #[[ARG2]] object_list)
  if(NOT object_list)
    message(FATAL_ERROR "'create_interface' target requires a HDRS list of .h files")
  endif()

  add_library(${target} INTERFACE)
  target_sources(${target} INTERFACE ${object_list})
endfunction(create_interface)
