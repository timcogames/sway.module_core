function(add_submodule #[[ARG1]] name_arg 
                       #[[ARG2]] source_dir_arg)
  if(NOT TARGET ${name_arg})
    add_subdirectory(${source_dir_arg})
  endif()
endfunction(add_submodule)
