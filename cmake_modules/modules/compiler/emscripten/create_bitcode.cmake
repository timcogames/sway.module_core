#---------------------------------------------------------------------------------
#[[
# DESC
  Создает bitcode

# ARGS
  ARG1:TARGET target [IN] - Цель
  ARG2:STRING source_dir [IN] - Директория с исходными файлами
 ]]
#---------------------------------------------------------------------------------
function(create_bitcode #[[ARG1]] target 
                        #[[ARG2]] source_dir)
  file(GLOB_RECURSE LIBRARY_SOURCE_FILE_LIST ${source_dir})
  add_library(${target} OBJECT ${LIBRARY_SOURCE_FILE_LIST})

  export(TARGETS ${target} FILE "${target}.cmake" NAMESPACE ns_)
endfunction(create_bitcode)

#---------------------------------------------------------------------------------
#[[
# DESC
  Создает INTERFACE library

# ARGS
  ARG1:TARGET target [IN] - Цель
  ARG2:STRING_LIST object_list [IN] - 
 ]]
#---------------------------------------------------------------------------------
function(create_iface #[[ARG1]] target 
                      #[[ARG2]] object_list)
  if(NOT object_list)
    message(FATAL_ERROR "'create_iface' target requires a HDRS list of .h files")
  endif()

  add_library(${target} INTERFACE)
  target_sources(${target} INTERFACE ${object_list})
endfunction(create_iface)
