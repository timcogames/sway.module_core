function(add_submodule #[[ARG]] name_arg 
                       #[[ARG]] source_dir_arg)
  if(NOT TARGET ${name_arg})
    add_subdirectory(${source_dir_arg})
  endif()
endfunction(add_submodule)
