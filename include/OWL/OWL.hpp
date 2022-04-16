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

int Main(const std::vector<std::string>&);

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

#ifdef _WIN32
/* WinAPI */
#include "WinAPI/WinAPI.hpp"

// Singleton for winapi specific data
class WinAPI_Data {
public:
	static WinAPI_Data* get() {
		if(!m_Instance) {
			m_Instance = new WinAPI_Data();
			std::cout << "getInstance(): First instance\n";
			return m_Instance;
		}
		else {
			std::cout << "getInstance(): previous instance\n";
			return m_Instance;
		}
	}
	HINSTANCE hInstance;
	int nCmdShow;
	HMODULE hOpengl32Module;
private:
	WinAPI_Data() {}
	static WinAPI_Data* m_Instance;
};

#include "WinAPI/window.hpp"

namespace OWL {
typedef WinAPI::Context Context;
typedef WinAPI::SoftwareContext SoftwareContext;
typedef WinAPI::Window Window;
}

// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
// 	WinAPI_Data::get() = new WinAPI_Data;
// 	WinAPI_Data::get()->hInstance = hInstance;
// 	WinAPI_Data::get()->nCmdShow = nCmdShow;

// 	std::vector<std::string> passed;
	
// 	{ /* Scope, so that variables created here will be freed when they are not needed */
// 		int cnt = 0;
// 		wchar_t** cmdl = CommandLineToArgvW(GetCommandLineW(), &cnt);
// 		if(cnt > 0) {
// 			unsigned int count = cnt;
// 			for(unsigned int i = 0; i < count; i++) {
// 				int strsize = WideCharToMultiByte(CP_UTF8, 0, cmdl[i], -1, 0, 0, NULL, NULL); //CP_ACP
// 				char* strstr = new char[strsize];
// 				WideCharToMultiByte(CP_UTF8, 0, cmdl[i], -1, strstr , strsize, NULL, NULL);
// 				passed.push_back(strstr);
// 				delete[] strstr;
// 			}
// 		}
// 		LocalFree(cmdl);
// 	}

// 	return Main(passed);
// 	/* No need for cleaning after allocating the WinAPI_Data::get(), as the kernel will do it itself. */
// }


#elif defined __linux__
/* X11 */
#include "X11/window.hpp"

namespace OWL {
typedef X11::Context Context;
typedef X11::SoftwareContext SoftwareContext;
typedef X11::Window Window;
}

// int main(int argc, char** argv) {
// 	std::vector<std::string> passed;
// 	for(unsigned int i = 0; i < argc; i++) {
// 		passed.push_back(argv[i]);
// 	}
// 	return Main(passed);
// }

#else

#error OWL: Unsupported platform! (Only linux and windows supported currently!)

#endif


#endif/*_OWL_OWL_HPP_HEADER_FILE_GUARD*/