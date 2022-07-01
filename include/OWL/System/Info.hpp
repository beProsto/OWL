#pragma once

#include <OWL/Utility/Config.hpp>

#if defined OWL_SYSTEM_WINDOWS
	#include <OWL/OS/WinAPI.hpp>
#elif defined OWL_SYSTEM_LINUX
	
#else
	
#endif

/// Define the OS Info singleton ///
namespace OWL {

class OSInfo {
public:
	static OSInfo* Get() {
		if(!m_Instance) {
			m_Instance = new OSInfo();
			return m_Instance;
		}
		else {
			return m_Instance;
		}
	}

public:
	#if defined OWL_SYSTEM_WINDOWS
		HINSTANCE InstanceHandle;
	#elif defined OWL_SYSTEM_LINUX
		
	#else

	#endif

private:
	OSInfo() {}
	static OSInfo* m_Instance;
};

OSInfo* OSInfo::m_Instance = nullptr;

}
