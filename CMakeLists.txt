cmake_minimum_required(VERSION 3.0.0)
project(OWL VERSION 0.2022.1)

# NOT YET SURE HOW TO USE THIS

if(LIBTYPE STREQUAL "STATIC")
	add_library(OWL STATIC src/OWL.cpp)
else()
	add_library(OWL SHARED src/OWL.cpp)
	target_link_options(OWL PRIVATE -Wl,--unresolved-symbols=ignore-all)
endif()


target_include_directories(OWL PRIVATE include)

target_compile_definitions(OWL PRIVATE BUILD_SHARED_LIBS _OWL_EXPORT)

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

