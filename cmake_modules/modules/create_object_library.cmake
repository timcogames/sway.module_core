include(CMakeParseArguments)

#--------------------------------------------------------------------------------
#[[
# DESC
  Create OBJECT library

# ARGS
  ARG1:TARGET target [IN] - Library target
  ARG2:STRING source_dir [IN] - Directory with sources

# KEYWORDS
  EXPORT - Export target
  EXCLUDE <files...>   - File names (regex) to exclude from glob
  INCLUDE_DIRS <dirs...> - Additional include directories
  COMPILE_DEFS <defs...> - Additional compile definitions
 ]]
#--------------------------------------------------------------------------------
function(create_object_library #[[ARG1]] target 
                               #[[ARG2]] source_dir)
  set(options EXPORT)
  set(one_value_keywords)
  set(multi_value_keywords EXCLUDE INCLUDE_DIRS COMPILE_DEFS)
  cmake_parse_arguments(ARG "${options}" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN})

  if(IS_DIRECTORY "${source_dir}")
    file(GLOB_RECURSE LIBRARY_SOURCE_FILE_LIST "${source_dir}/*.*")
  else()
    set(LIBRARY_SOURCE_FILE_LIST "${source_dir}")
  endif()

  if(ARG_EXCLUDE)
    foreach(exclude IN LISTS ARG_EXCLUDE)
      string(REPLACE "." "\\." exclude_escaped "${exclude}")
      list(FILTER LIBRARY_SOURCE_FILE_LIST EXCLUDE REGEX "/${exclude_escaped}$")
    endforeach()
  endif()

  add_library(${target} OBJECT ${LIBRARY_SOURCE_FILE_LIST})

  if(ARG_INCLUDE_DIRS)
    target_include_directories(${target} PRIVATE ${ARG_INCLUDE_DIRS})
  endif()

  if(ARG_COMPILE_DEFS)
    target_compile_definitions(${target} PRIVATE ${ARG_COMPILE_DEFS})
  endif()

  if(ARG_EXPORT)
    export(TARGETS ${target} FILE "${target}.cmake" NAMESPACE ns_)
  endif()
endfunction(create_object_library)
