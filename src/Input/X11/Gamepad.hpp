#pragma once

#include "../Gamepad.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Linux.hpp>

namespace OWL {
namespace Impl {
class OWL_API X11Gamepads: public Gamepads {
public:
	X11Gamepads() {
		m_gamepadsCount = 4;
		m_gamepads = new Gamepad[m_gamepadsCount]();
	}
	virtual ~X11Gamepads() {
		delete[] m_gamepads;
	}

	virtual void setCount(unsigned int _gamepadsCount) {
		if(_gamepadsCount != m_gamepadsCount) {
			delete[] m_gamepads;

			m_gamepadsCount = _gamepadsCount;
			m_gamepads = new Gamepad[m_gamepadsCount]();
		}
	}

public:
	virtual void pollPreparation() {

	}
	virtual void pollSpecificEvents() {

	}
};
}
}