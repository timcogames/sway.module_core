function(custom_add_subdirectory MODULE_NAME)
	if (NOT TARGET libmodule_${MODULE_NAME})
		add_subdirectory(modules/sway.module_${MODULE_NAME})
	endif()
endfunction(custom_add_subdirectory)