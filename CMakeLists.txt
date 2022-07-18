cmake_minimum_required(VERSION 3.0.0)
# NOT A FULL RELEASE YET
project(OWL VERSION 0.2022.1)
# I'm sorry but it has to be this way 😔
set(CMAKE_BUILD_TYPE Release)

# include_directories and link_libraries work on all targets defined BELOW them
include_directories(include)

# All the OS independent source files should be in the main directories
file(GLOB_RECURSE lib_srcs
	"include/OWL/*.hpp"
	"src/*.hpp"
	"src/*.cpp"
)

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

if(LIBTYPE STREQUAL "STATIC")
	add_library(OWL STATIC ${lib_srcs})
	target_compile_definitions(OWL PRIVATE OWL_BUILD_STATIC)
else()
	add_library(OWL SHARED ${lib_srcs})
	target_compile_definitions(OWL PRIVATE OWL_BUILD_SHARED)
endif()

if(WIN32)
	set(EXE_TYPE WIN32)
else()
	set(EXE_TYPE )
endif()

function(add_example name)
	file(GLOB_RECURSE ${name}_srcs
		"examples/${name}/*.hpp"
		"examples/${name}/*.cpp"
	)
	add_executable(${name} ${EXE_TYPE} ${${name}_srcs})
	if(LIBTYPE STREQUAL "STATIC")
		target_compile_definitions(${name} PRIVATE OWL_BUILD_STATIC)
	endif()
endfunction()

# If the user didn't turn building examples off, we create them, linking the new OWL library to them:
if(NOT BUILD_EXAMPLES STREQUAL "NO")
	link_libraries(OWL)
	
	# add_example(GUIApplication)
	# add_example(ModernOpenGL)
	# add_example(SimpleWindow)
	add_example(Temporary)
endif()