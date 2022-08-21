#include <OWL/System/Info.hpp>

namespace OWL {

OSInfo* OSInfo::m_instance = nullptr;

OSInfo* OSInfo::get() {
	if(!m_instance) {
		m_instance = new OSInfo();
		return m_instance;
	}
	else {
		return m_instance;
	}
}

OSInfo::OSInfo() {

}

}