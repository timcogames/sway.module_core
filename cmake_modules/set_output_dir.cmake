#---------------------------------------------------------------------------------
#[[
# DESC
  Устанавливает путь выходного файла

# ARGS
  ARG1:STRING path [IN] - Путь выходного файла
 ]]
#---------------------------------------------------------------------------------
function(set_output_dir #[[ARG1]] path)
  if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(OUTPUT_PATH "${path}/dbg")
  else()
    set(OUTPUT_PATH "${path}")
  endif()

  foreach(file_type IN LISTS "EXECUTABLE;LIBRARY")
    set(${file_type}_OUTPUT_PATH "${OUTPUT_PATH}" PARENT_SCOPE)
  endforeach()
endfunction(set_output_dir)
