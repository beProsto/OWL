#include <OWL/Input/Keyboard.hpp>

#include "Keyboard.hpp"

namespace OWL {

Keyboard::Keyboard() {
	#if defined OWL_SYSTEM_WINDOWS
		m_impl = new Impl::WinAPIKeyboard;
	#elif defined OWL_SYSTEM_LINUX

	#endif
}
Keyboard::~Keyboard() {
	delete m_impl;
}

bool Keyboard::IsKeyPressed(unsigned int _key) const {
	return m_impl->IsKeyPressed(_key);
}

KeyData Keyboard::GetKeyData() const {
	return m_impl->GetKeyData();
}

}