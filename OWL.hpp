#ifndef _OWL_OWL_HPP_HEADER_FILE_GUARD
#define _OWL_OWL_HPP_HEADER_FILE_GUARD

#include <chrono>
#include <thread>
#include <time.h>
#include <vector>
#include <sstream>

#include "debugout.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

/* This file contains typedefs for all the needed types in OWL */

namespace OWL {
enum {
	ContextType_Unknown = 0,
	ContextType_Software = 1,
};
enum class EventLoopType {
	EventLoop = 0,
	GameLoop = 1
};
struct KeyData {
	std::string String; 
	unsigned int KeyEnum;
}; 

}

int Main(const std::vector<std::string>&);


#ifdef _WIN32
/* WinAPI */
#include "WinAPI/WinAPI.hpp"
struct WinAPI_Data {
	HINSTANCE hInstance;
	int nCmdShow;
	HMODULE hOpengl32Module;
};
WinAPI_Data* g_WinAPI_Data;

#include "WinAPI/window.hpp"

namespace OWL {
typedef WinAPI::Context Context;
typedef WinAPI::SoftwareContext SoftwareContext;
typedef WinAPI::Window Window;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	g_WinAPI_Data = new WinAPI_Data;
	g_WinAPI_Data->hInstance = hInstance;
	g_WinAPI_Data->nCmdShow = nCmdShow;

	std::vector<std::string> passed;
	
	{ /* Scope, so that variables created here will be freed when they are not needed */
		int cnt = 0;
		wchar_t** cmdl = CommandLineToArgvW(GetCommandLineW(), &cnt);
		for(unsigned int i = 0; i < cnt; i++) {
			int strsize = WideCharToMultiByte(CP_UTF8, 0, cmdl[i], -1, 0, 0, NULL, NULL); //CP_ACP
			char* strstr = new char[strsize];
			WideCharToMultiByte(CP_UTF8, 0, cmdl[i], -1, strstr , strsize, NULL, NULL);
			passed.push_back(strstr);
			delete[] strstr;
		}
		LocalFree(cmdl);
	}

	return Main(passed);
	/* No need for cleaning after allocating the g_WinAPI_Data, as the kernel will do it itself. */
}


#elif defined __linux__
/* X11 */
#include "X11/window.hpp"

namespace OWL {
typedef X11::Context Context;
typedef X11::SoftwareContext SoftwareContext;
typedef X11::Window Window;
}

int main(int argc, char** argv) {
	std::vector<std::string> passed;
	for(unsigned int i = 0; i < argc; i++) {
		passed.push_back(argv[i]);
	}
	return Main(passed);
}


#endif

#endif/*_OWL_OWL_HPP_HEADER_FILE_GUARD*/