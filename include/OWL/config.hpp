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
	#ifdef OWL_BUILD_DLL
		#define OWL_LIB_EXPORT __declspec(dllexport)
	#else
		#define OWL_LIB_EXPORT __declspec(dllimport)
	#endif
#else
	#define OWL_LIB_EXPORT 
#endif