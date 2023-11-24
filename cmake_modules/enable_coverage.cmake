function(enable_coverage)
  set(COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
  set(COVERAGE_LINK_FLAGS "--coverage")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COVERAGE_COMPILE_FLAGS}" PARENT_SCOPE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${COVERAGE_LINK_FLAGS}" PARENT_SCOPE)
endfunction(enable_coverage)
