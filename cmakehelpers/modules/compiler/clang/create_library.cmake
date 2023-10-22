# Создает конкретную библиотеку
#
# arg:target_arg - Цель
# arg:source_dir_arg - 
#
function(create_library target_arg source_dir_arg)
  file(GLOB_RECURSE LIBRARY_SOURCE_FILE_LIST ${source_dir_arg})

  if (MODULE_CORE_SHARED_LIB)
    add_executable(${target_arg} ${LIBRARY_SOURCE_FILE_LIST})
    # set_target_properties(${target_arg} PROPERTIES OUTPUT_NAME ${META_CORE_PRJNAME})
    # set_target_properties(${target_arg} PROPERTIES SUFFIX ".${META_CORE_VERSION}.js")
  else ()
    add_library(${target_arg} STATIC ${LIBRARY_SOURCE_FILE_LIST})
    # set_target_properties(${target_arg} PROPERTIES OUTPUT_NAME ${META_CORE_PRJNAME})
    # set_target_properties(${target_arg} PROPERTIES SUFFIX ".a.${META_CORE_VERSION}")
  endif ()
endfunction()
