#--------------------------------------------------------------------------------
#[[
# DESC
  Create OBJECT library

# ARGS
  ARG1:TARGET target [IN] - Library target
  ARG2:STRING source_dir [IN] - Directory with sources
  ARG2:BOOL exported [IN] - 
 ]]
#--------------------------------------------------------------------------------
function(create_object_library #[[ARG1]] target 
                               #[[ARG2]] source_dir
                               #[[ARG3]] exported)
  file(GLOB_RECURSE LIBRARY_SOURCE_FILE_LIST ${source_dir})

  add_library(${target} OBJECT ${LIBRARY_SOURCE_FILE_LIST})

  if(exported)
    export(TARGETS ${target} FILE "${target}.cmake" NAMESPACE ns_)
  endif()
endfunction(create_object_library)
