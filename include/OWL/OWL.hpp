#pragma once

#include "config.hpp"

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

#if defined OWL_SYSTEM_WINDOWS
/* WinAPI */
#include "WinAPI/WinAPI.hpp"

// Singleton for winapi specific data
class WinAPI_Data {
public:
	static WinAPI_Data* get() {
		if(!m_Instance) {
			m_Instance = new WinAPI_Data();
			return m_Instance;
		}
		else {
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



#elif defined OWL_SYSTEM_LINUX
/* X11 */
#include "X11/window.hpp"

namespace OWL {
typedef X11::Context Context;
typedef X11::SoftwareContext SoftwareContext;
typedef X11::Window Window;
}

#else

#error OWL: Unsupported platform! (Only linux and windows supported currently!)

#endif