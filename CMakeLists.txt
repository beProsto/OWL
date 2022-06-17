cmake_minimum_required(VERSION 3.0.0)
project(OWL VERSION 0.2022.1)

# NOT YET SURE HOW TO USE THIS
# NOTE: OWL_Main should actually be a header-only part of the library.
# The rest shall be compilable. At that point shared libraries are a proper goal.

if(LIBTYPE STREQUAL "SHARED")
	add_library(OWL SHARED src/OWL.cpp)
else()
	add_library(OWL STATIC src/OWL.cpp)
endif()

target_include_directories(OWL PRIVATE include)

if(WIN32)
	target_link_libraries(OWL
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
	target_link_libraries(OWL
		X11
		GL
		GLX
	)
endif()

