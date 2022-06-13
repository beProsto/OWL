cmake_minimum_required(VERSION 3.0.0)
project(OWL VERSION 0.2022.1)

target_sources(OWL PRIVATE src/OWL.cpp)

if(WIN32)
	target_link_libraries(OWL PRIVATE
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
	target_link_libraries(OWL PRIVATE
		X11
		GL
		GLX
	)
endif()


# NOT YET SURE HOW TO USE THIS

# if(LIBTYPE STREQUAL "STATIC")
# else()
# endif()