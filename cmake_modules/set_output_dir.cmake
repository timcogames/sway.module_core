#--------------------------------------------------------------------------------
#[[
# DESC
  Устанавливает путь выходного файла

# ARGS
  ARG1:STRING path [IN] - Путь выходного файла
 ]]
#--------------------------------------------------------------------------------
function(set_output_dir #[[ARG1]] path)
  if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(OUTPUT_PATH "${path}/dbg")
  else()
    set(OUTPUT_PATH "${path}")
  endif()

  set(OUTPUT_FILE_TYPE_LIST "EXECUTABLE;LIBRARY")
  foreach(FILE_TYPE ${OUTPUT_FILE_TYPE_LIST})
    set(${FILE_TYPE}_OUTPUT_PATH "${OUTPUT_PATH}" PARENT_SCOPE)
  endforeach()
endfunction(set_output_dir)
