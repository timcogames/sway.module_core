function(create_library #[[TARGET]] target_arg #[[TYPE]] type_arg #[[SOURCE_DIR]] source_dir_arg)
  if(${type_arg} STREQUAL STATIC)
    detect_static_extension()
  elseif(${type_arg} STREQUAL SHARED)
    detect_shared_extension()
  else()
    message(FATAL_ERROR "Invalid library type")
  endif()

  file(GLOB_RECURSE SOURCE_FILE_LIST ${source_dir_arg})

  add_library(${target_arg} ${type_arg} ${SOURCE_FILE_LIST})
  set_target_properties(${target_arg} PROPERTIES OUTPUT_NAME "module_${target_arg}")
  set_target_properties(${target_arg} PROPERTIES SUFFIX ${LIB_FILE_EXTENSION})

  target_link_libraries(${target_arg})
endfunction(create_library)

function(create_bitcode_library #[[TARGET]] target_arg #[[SOURCE_DIR]] source_dir_arg)
  string(TOUPPER ${target_arg} target_upper)
  if(GLOB_EMSCRIPTEN_PLATFORM AND MODULE_${target_upper}_SHARED_LIB)
    message(WARNING "Bitcode requires a static library type")
  endif()

  create_library(${target_arg} STATIC ${source_dir_arg})
endfunction(create_bitcode_library)
