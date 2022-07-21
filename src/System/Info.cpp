#include <OWL/System/Info.hpp>

namespace OWL {

OSInfo* OSInfo::m_Instance = nullptr;

OSInfo* OSInfo::Get() {
	if(!m_Instance) {
		m_Instance = new OSInfo();
		return m_Instance;
	}
	else {
		return m_Instance;
	}
}

OSInfo::OSInfo() {

}

}