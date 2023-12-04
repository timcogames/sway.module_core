macro(set_exe_output_dir #[[ARG]] path_arg)
  set(EXECUTABLE_OUTPUT_PATH "${path_arg}" PARENT_SCOPE)
endmacro(set_exe_output_dir)

macro(set_lib_output_dir #[[ARG]] path_arg)
  set(LIBRARY_OUTPUT_PATH "${path_arg}" PARENT_SCOPE)
endmacro(set_lib_output_dir)

function(set_output_dir #[[ARG]] path_arg)
  if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(OUTPUT_PATH "${path_arg}/dbg")
  else()
    set(OUTPUT_PATH "${path_arg}")
  endif()

  set_exe_output_dir("${OUTPUT_PATH}")
  set_lib_output_dir("${OUTPUT_PATH}")
endfunction(set_output_dir)
