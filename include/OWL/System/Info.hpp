#pragma once

#include <OWL/Utility/Config.hpp>

#if defined OWL_SYSTEM_WINDOWS
	#include <OWL/OS/Windows.hpp>

#elif defined OWL_SYSTEM_LINUX
	#include <OWL/OS/Linux.hpp>
	
#else
	
#endif

/// Define the OS Info singleton ///
namespace OWL {

class OWL_API OSInfo {
public:
	static OSInfo* get();

public:
	#if defined OWL_SYSTEM_WINDOWS
		HINSTANCE instanceHandle;
		HMODULE opengl32ModuleHandle;
	
	#elif defined OWL_SYSTEM_LINUX
		::Display* displayX11;
		int screenIdX11;

	#else

	#endif

private:
	OSInfo();
	static OSInfo* m_instance;
};

}
