function(create_bitcode target_arg source_dir_arg)
  file(GLOB_RECURSE LIBRARY_SOURCE_FILE_LIST ${source_dir_arg})

  add_library(${target_arg} OBJECT ${LIBRARY_SOURCE_FILE_LIST})

  enable_cxx17(${MODULE_CORE_TARGET})

  export(TARGETS ${target_arg} FILE "${target_arg}.cmake" NAMESPACE ns_)
endfunction(create_bitcode)
