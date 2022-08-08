#include <OWL/Input/Keyboard.hpp>

#include "Keyboard.hpp"

namespace OWL {

Keyboard::Keyboard() {
	#if defined OWL_SYSTEM_WINDOWS
		m_impl = new Impl::WinAPIKeyboard;

	#elif defined OWL_SYSTEM_LINUX
		m_impl = new Impl::X11Keyboard;

	#endif
}
Keyboard::~Keyboard() {
	delete m_impl;
}

bool Keyboard::isKeyPressed(unsigned int _key) const {
	return m_impl->isKeyPressed(_key);
}

KeyData Keyboard::getKeyData() const {
	return m_impl->getKeyData();
}

}