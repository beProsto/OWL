cmake_minimum_required(VERSION 3.0.0)
# NOT A FULL RELEASE YET
project(OWL VERSION 0.2022.1)

# include_directories and link_libraries work on all targets defined BELOW them

include_directories(include)

if(WIN32)
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
else()
	link_libraries(
		X11
		GL
		GLX
	)
endif()

# NOTE: OWL_Main should actually be a header-only part of the library.
# The rest shall be compilable. At that point shared libraries are a proper goal.
# Because of that small mishap we'll have to compile to static for a while.
# Here we define the OWL (library) target:

if(LIBTYPE STREQUAL "SHARED")
	add_library(OWL SHARED src/OWL.cpp)
else()
	add_library(OWL STATIC src/OWL.cpp)
endif()

# If the user didn't turn building examples off, we create them, linking the new OWL library:
if(NOT BUILD_EXAMPLES STREQUAL "NO")
	link_libraries(OWL)
	add_executable(GUIApplicationExample  examples/GUIApplicationExample/main.cpp)
	add_executable(ModernOpenGLExample    examples/ModernOpenGLExample/main.cpp)
	add_executable(SimpleWindowExample    examples/SimpleWindowExample/main.cpp)
endif()



