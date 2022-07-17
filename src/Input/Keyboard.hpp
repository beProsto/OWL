#pragma once

#include <OWL/Input/Keyboard.hpp>

namespace OWL {
namespace Impl {
class OWL_API Keyboard {
public:
	Keyboard() {}
	virtual ~Keyboard() {}

	virtual bool IsKeyPressed(unsigned int _key) const {return false;}

protected:
	unsigned int m_KeyMap[OWL::Keyboard::Key::Count];
};
}
}


#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/Keyboard.hpp"
#elif defined OWL_SYSTEM_LINUX

#endif