function(emscripten_set_pthread flags_arg pool_size_arg)
  if(${pool_size_arg} EQUAL 1)
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--shared-memory,--no-check-features")
    # set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_PTHREADS=1 -s ALLOW_MEMORY_GROWTH=1 -s INITIAL_MEMORY=512Mb -s TOTAL_MEMORY=256Mb")
    
    # 1073741824(byte) = 1024(Mbyte)
    set(${flags_arg} ${${flags_arg}} -sWASM_MEM_MAX=1073741824 -pthread -sPTHREAD_POOL_SIZE=${pool_size_arg} PARENT_SCOPE)
  endif()
endfunction(emscripten_set_pthread)
