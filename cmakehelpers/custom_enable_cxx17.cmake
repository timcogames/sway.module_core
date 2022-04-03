function(custom_enable_cxx17 TARGET)
  target_compile_features(${TARGET} PUBLIC cxx_std_17)
endfunction(custom_enable_cxx17)
