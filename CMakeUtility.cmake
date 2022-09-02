if(WIN32)
	set(OWL_SYSTEM_WINDOWS TRUE)

elseif(UNIX)
	set(OWL_SYSTEM_LINUX TRUE)

endif()


# Determines if the library is statically compiled
if(LIBTYPE STREQUAL "STATIC")
	set(OWL_BUILD_STATIC TRUE)

endif()


# Determines the preffered windowing subsystem on linux
# if(DISABLE_WAYLAND STREQUAL "YES")
# 	set(OWL_WAYLAND_OFF TRUE)
# 	set(OWL_X11_ON TRUE)
#
# elseif(DISABLE_X11 STREQUAL "YES")
# 	set(OWL_WAYLAND_ON TRUE)
# 	set(OWL_X11_OFF TRUE)
#
# endif()


# Determines if building examples is enabled
if(BUILD_EXAMPLES STREQUAL "NO")
	set(OWL_EXAMPLES_OFF TRUE)

else()
	set(OWL_EXAMPLES_ON TRUE)

endif()


# Sets the executable type
if(OWL_SYSTEM_WINDOWS)
	set(OWL_EXE_TYPE WIN32)

else()
	set(OWL_EXE_TYPE )

endif()


# Adds an executable target for our examples
function(OWL_AddExample name)
	file(GLOB_RECURSE ${name}_srcs
		"examples/${name}/*.hpp"
		"examples/${name}/*.cpp"
	)

	add_executable(${name} ${OWL_EXE_TYPE} ${${name}_srcs})

	if(OWL_BUILD_STATIC)
		target_compile_definitions(${name} PRIVATE OWL_BUILD_STATIC)
	endif()
endfunction()