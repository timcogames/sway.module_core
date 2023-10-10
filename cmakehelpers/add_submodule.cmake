function(add_submodule #[[NAME]] name_arg #[[SOURCE_DIR]] source_dir_arg)
  if(NOT TARGET ${name_arg})
    add_subdirectory(${source_dir_arg})
  endif()
endfunction(add_submodule)
