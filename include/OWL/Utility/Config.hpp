#pragma once

// Decide which operating system this is:
#if defined _WIN32
#define OWL_SYSTEM_WINDOWS
#elif defined __linux__
#define OWL_SYSTEM_LINUX
#else
#define OWL_SYSTEM_OTHER
#endif

// On windows we need spec declarations for shared libraries:
#ifdef OWL_SYSTEM_WINDOWS
	#ifdef OWL_BUILD_SHARED
		// When building the DLL, we specify we want the classes and functions treated as export
		#define OWL_API __declspec(dllexport)
	#elif OWL_BUILD_STATIC
		// Compiling statically we don't want to specify anything as an import
		#define OWL_API 
	#else
		// When building the executables, we specify we want everything treated as import
		#define OWL_API __declspec(dllimport)
	#endif
#else
	// On other systems we can leave it empty
	#define OWL_API 
#endif

// If any other libs would like to know if OWL is used:
#define OWL_