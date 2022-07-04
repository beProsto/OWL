#include <OWL/Input/Keyboard.hpp>

#include "Keyboard.hpp"

namespace OWL {

Keyboard::Keyboard() {
	#if defined OWL_SYSTEM_WINDOWS
		m_Impl = new Impl::WinAPIKeyboard;
	#elif defined OWL_SYSTEM_LINUX

	#endif
}
Keyboard::~Keyboard() {
	delete m_Impl;
}

bool Keyboard::IsKeyPressed(unsigned int _key) const {
	return m_Impl ->IsKeyPressed(_key);
}

}