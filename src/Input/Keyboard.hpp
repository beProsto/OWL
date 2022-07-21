#pragma once

#include <OWL/Input/Keyboard.hpp>

namespace OWL {
namespace Impl {
class OWL_API Window;

class OWL_API Keyboard {
public:
	Keyboard() {}
	virtual ~Keyboard() {}

	virtual bool IsKeyPressed(unsigned int _key) const {return false;}

	virtual KeyData GetKeyData() const { return m_KeyData; }

public:
	virtual void PollPreparation() {}
	virtual void PollSpecificEvents() {}

public:
	unsigned int m_KeyMap[OWL::Keyboard::Key::Count];
	Window* m_WindowImpl;
	KeyData m_KeyData;
};
}
}

#if !defined _OWL_INCLUDE_WITHOUT_IMPLEMENTATION
#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/Keyboard.hpp"
#elif defined OWL_SYSTEM_LINUX

#endif
#endif