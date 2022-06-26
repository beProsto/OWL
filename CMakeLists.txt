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

# All the OS independent source files should be in the main directories
file(GLOB os_independent_srcs
	# "include/OWL/*.hpp"
	"src/*.cpp"
)

if(LIBTYPE STREQUAL "STATIC")
	add_library(OWL STATIC ${os_independent_srcs})
else()
	add_library(OWL SHARED ${os_independent_srcs})
	target_compile_definitions(OWL PRIVATE OWL_BUILD_DLL)
endif()

# If the user didn't turn building examples off, we create them, linking the new OWL library:
if(NOT BUILD_EXAMPLES STREQUAL "NO")
	link_libraries(OWL)
	add_executable(GUIApplicationExample examples/GUIApplicationExample/main.cpp)
	add_executable(ModernOpenGLExample examples/ModernOpenGLExample/main.cpp)
	add_executable(SimpleWindowExample examples/SimpleWindowExample/main.cpp)
endif()