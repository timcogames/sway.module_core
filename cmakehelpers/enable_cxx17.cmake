function(enable_cxx17 #[[TARGET]] target_arg)
  target_compile_features(${target_arg} PUBLIC cxx_std_17)
endfunction(enable_cxx17)
