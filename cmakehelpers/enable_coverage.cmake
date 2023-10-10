function(enable_coverage)
  set(COVERAGE_FLAGS "${COVERAGE_FLAGS} -fprofile-arcs")
  set(COVERAGE_FLAGS "${COVERAGE_FLAGS} -ftest-coverage")

  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage" PARENT_SCOPE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COVERAGE_FLAGS} -O0" PARENT_SCOPE)
endfunction(enable_coverage)
