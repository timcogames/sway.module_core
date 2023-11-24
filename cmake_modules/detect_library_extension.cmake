macro(detect_static_extension)
  if(GLOB_EMSCRIPTEN_PLATFORM) # Emscripten
    set(LIB_FILE_EXTENSION ".bc")
  elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # MacOS
    set(LIB_FILE_EXTENSION ".a")
  else() # Linux
    set(LIB_FILE_EXTENSION ".o")
  endif()
endmacro(detect_static_extension)

macro(detect_shared_extension)
  if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # MacOS
    set(LIB_FILE_EXTENSION ".dylib")
  else() # Linux
    set(LIB_FILE_EXTENSION ".so")
  endif()
endmacro(detect_shared_extension)
