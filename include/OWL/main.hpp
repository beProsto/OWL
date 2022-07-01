#pragma once

#include <OWL/Utility/Config.hpp>
#include <OWL/System/Info.hpp>
#include <OWL/OWL.hpp>

/// Define the main function ///
int OWLMain(int, char**);
#if defined main
	#undef main
#endif
#define main OWLMain


/// Call the main function ///
#if defined OWL_SYSTEM_WINDOWS
/* WinAPI */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	OWL::OSInfo::Get()->InstanceHandle = hInstance;

	AllocConsole();
	FILE *fpstdin = stdin, *fpstdout = stdout, *fpstderr = stderr;
    freopen_s(&fpstdin,  "CONIN$",  "r", stdin);
    freopen_s(&fpstdout, "CONOUT$", "w", stdout);
    freopen_s(&fpstderr, "CONOUT$", "w", stderr);

	return OWLMain(__argc, __argv);
}

#elif defined OWL_SYSTEM_LINUX
/* X11 */
int main(int argc, char** argv) {
	return OWLMain(argc, argv);
}

#else
/* Other */
#error OWL: Unsupported platform! (Only linux and windows supported currently!)

#endif