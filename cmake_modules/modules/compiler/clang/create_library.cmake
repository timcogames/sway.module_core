#---------------------------------------------------------------------------------
#[[
# DESC
  Создает конкретную библиотеку

# ARGS
  ARG1:TARGET target [IN] - Цель
  ARG2:STRING source_dir [IN] - Директория с исходными файлами
 ]]
#---------------------------------------------------------------------------------
function(create_library target source_dir)
  file(GLOB_RECURSE LIBRARY_SOURCE_FILE_LIST ${source_dir})
  string(TOUPPER ${target} TARGET_NAME_UPPER)
  if (${TARGET_NAME_UPPER}_SHARED_LIB)
    # add_executable(${target} ${LIBRARY_SOURCE_FILE_LIST})
    add_library(${target} SHARED ${LIBRARY_SOURCE_FILE_LIST})
    # set_target_properties(${target_arg} PROPERTIES OUTPUT_NAME ${META_CORE_PRJNAME})
    # set_target_properties(${target_arg} PROPERTIES SUFFIX ".${META_CORE_VERSION}.js")
  else ()
    add_library(${target} STATIC ${LIBRARY_SOURCE_FILE_LIST})
    # set_target_properties(${target_arg} PROPERTIES OUTPUT_NAME ${META_CORE_PRJNAME})
    # set_target_properties(${target_arg} PROPERTIES SUFFIX ".a.${META_CORE_VERSION}")
  endif ()
endfunction()
