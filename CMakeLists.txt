cmake_minimum_required(VERSION 3.0.0)
# NOT A FULL RELEASE YET
project(OWL VERSION 0.2022.2)
# I'm sorry but it has to be this way 😔
set(CMAKE_BUILD_TYPE Release)

# include basic cmake project config
include(CMakeUtility.cmake)

# include_directories and link_libraries work on all targets defined BELOW them
include_directories(include)

# All the OS independent source files should be in the main directories
file(GLOB_RECURSE lib_srcs
	"include/OWL/*.hpp"
	"src/*.hpp"
	"src/*.cpp"
)

if(OWL_SYSTEM_EMSCRIPTEN)
	# WASM doesn't have a concept of a dynamic library
	set(LIBTYPE STATIC)
	link_libraries(
		SDL2
	)

elseif(OWL_SYSTEM_WINDOWS)
	link_libraries(
		opengl32
		glu32
		gdi32
		user32
		comctl32
		kernel32
		shell32
		xinput
	)

elseif(OWL_SYSTEM_LINUX)
	if(NOT WAYLAND_OFF)
		link_libraries(
			wayland-client
		)

	endif()
	if(NOT X11_OFF)
		link_libraries(
			X11
			GL
			GLX
		)

	endif()

endif()

# Depending on the library type, we need to use a correct definition
if(LIBTYPE STREQUAL "STATIC")
	add_library(OWL STATIC ${lib_srcs})
	target_compile_definitions(OWL PRIVATE OWL_BUILD_STATIC)

else()
	add_library(OWL SHARED ${lib_srcs})
	target_compile_definitions(OWL PRIVATE OWL_BUILD_SHARED)

endif()

# 
if(WAYLAND_OFF)
	target_compile_definitions(OWL PRIVATE OWL_WAYLAND_OFF)

endif()
if(X11_OFF)
	target_compile_definitions(OWL PRIVATE OWL_X11_OFF)

endif()


# If the user didn't turn building examples off, we create them, linking the new OWL library to them:
if(NOT BUILD_EXAMPLES STREQUAL "NO")
	link_libraries(OWL)
	
	OWL_AddExample(GUIApplication)
	OWL_AddExample(ModernOpenGL)
	OWL_AddExample(SimpleWindow)
	OWL_AddExample(GamepadTest)
	OWL_AddExample(Sandbox)
endif()