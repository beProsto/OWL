#pragma once

#include <OWL/Input/Keyboard.hpp>

namespace OWL {
namespace Impl {
class OWL_API Window;

class OWL_API Keyboard {
public:
	Keyboard() {}
	virtual ~Keyboard() {}

	virtual bool isKeyPressed(unsigned int _key) const {return false;}

	virtual KeyData getKeyData() const { return m_keyData; }

public:
	virtual void pollPreparation() {}
	virtual void pollSpecificEvents() {}

public:
	unsigned int m_keyMap[OWL::Keyboard::Key::Count];
	Window* m_windowImpl;
	KeyData m_keyData;
};
}
}

#if !defined _OWL_INCLUDE_WITHOUT_IMPLEMENTATION
#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/Keyboard.hpp"
#elif defined OWL_SYSTEM_LINUX

#endif
#endif