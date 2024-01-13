# Отображает имя, идентификатор и версию компилятора в виде сообщения
#
# arg:target_arg Цель
#
function(printf_compiler_name #[[ARG]] target_arg)
  get_filename_component(CURRENT_COMPILER_NAME "${CMAKE_CXX_COMPILER}" NAME)
  message("[${target_arg}]: compiler=${CMAKE_CXX_COMPILER_ID} v${CMAKE_CXX_COMPILER_VERSION} (${CURRENT_COMPILER_NAME})")
endfunction(printf_compiler_name)

# Отображает COMPILE_DEFINITIONS извлеченные из <target_arg> в виде сообщения
#
# arg:target_arg Цель
#
function(printf_compile_definitions #[[ARG]] target_arg)
  get_target_property(CURRENT_COMPILE_DEFINITIONS ${target_arg} INTERFACE_COMPILE_DEFINITIONS)
  message("[${target_arg}]: defines=${CURRENT_COMPILE_DEFINITIONS}")
endfunction(printf_compile_definitions)

# Отображает COMPILE_OPTIONS извлеченные из <target_arg> в виде сообщения
#
# arg1:target_arg Цель
#
function(printf_compile_options #[[ARG]] target_arg)
  get_target_property(CURRENT_COMPILE_OPTIONS ${target_arg} INTERFACE_COMPILE_OPTIONS)
  string(REPLACE ";" "\n\t" COMPILE_OPTIONS_RESULT "\n\t${CURRENT_COMPILE_OPTIONS}")
  message("[${target_arg}]: compile options=[${COMPILE_OPTIONS_RESULT}]")
endfunction(printf_compile_options)

# Отображает LINK_OPTIONS извлеченные из <target_arg> в виде сообщения
#
# arg1:target_arg Цель
#
function(printf_link_options #[[ARG]] target_arg)
  get_target_property(CURRENT_LINK_OPTIONS ${target_arg} INTERFACE_LINK_OPTIONS)
  string(REPLACE "SHELL:" "\n\t" LINK_OPTIONS_WITHOUT_SHELL "${CURRENT_LINK_OPTIONS}")
  string(REPLACE " " "" LINK_OPTIONS_WITHOUT_SPACE "${LINK_OPTIONS_WITHOUT_SHELL}")
  string(REPLACE ";" "" LINK_OPTIONS_RESULT "${LINK_OPTIONS_WITHOUT_SPACE}")
  message("[${target_arg}]: link options=[${LINK_OPTIONS_RESULT}]")
endfunction(printf_link_options)

# Отображает LINK_FLAGS извлеченные из <target_arg> в виде сообщения
#
# arg1:target_arg Цель
#
function(printf_link_flags #[[ARG]] target_arg)
  get_target_property(CURRENT_LINK_FLAGS ${target_arg} LINK_FLAGS)
  message("[${target_arg}]: link flags=${CURRENT_LINK_FLAGS}")
endfunction(printf_link_flags)

macro(create_logger)
  message("[${MODULE_CORE_PROJ_NAME}]: ${META_CORE_VERSION}
            system | ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION}
          platform | ${CMAKE_CXX_PLATFORM_ID}
          compiler | ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}
        build type | ${CMAKE_BUILD_TYPE}
        shared lib | ${MODULE_CORE_LIB_TYPE}
          cxxflags | ${CMAKE_CXX_FLAGS} ${EXTRA_FLAGS}
  build type flags | ${BUILD_TYPE_CXX_FLAGS}
         build dir | ${CMAKE_BINARY_DIR}
    install prefix | ${CMAKE_INSTALL_PREFIX}

    emscripten dir | ${GLOB_EMSCRIPTEN_ROOT_DIR}
         boost dir | ${GLOB_BOOST_ROOT_DIR}
         gtest dir | ${GLOB_GTEST_ROOT_DIR}

        emscripten | ${GLOB_EMSCRIPTEN_PLATFORM}
          coverage | ${MODULE_CORE_ENABLE_COVERAGE}
             tests | ${MODULE_CORE_ENABLE_TESTS}
  ")
endmacro(create_logger)
