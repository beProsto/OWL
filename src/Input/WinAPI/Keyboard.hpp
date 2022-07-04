#pragma once

#include "../Keyboard.hpp"

#include <OWL/OS/Windows.hpp>

namespace OWL {
namespace Impl {
class OWL_API WinAPIKeyboard: public Keyboard {
public:
	WinAPIKeyboard() {

	}
	virtual ~WinAPIKeyboard() {

	}

	virtual bool IsKeyPressed(unsigned int _key) const {
		return GetKeyState(m_KeyMap[_key]) & 0xFFFF0000;
	}

};
}
}