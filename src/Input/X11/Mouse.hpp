#pragma once

#include "../mouse.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Windows.hpp>

namespace OWL {
namespace Impl {
class OWL_API WinAPIMouse: public Mouse {
public:
	WinAPIMouse() {
		m_buttonMap[OWL::Mouse::Button::Left] = 1<<8;
		m_buttonMap[OWL::Mouse::Button::Middle] = 1<<9;
		m_buttonMap[OWL::Mouse::Button::Right] = 1<<10;
		m_buttonMap[OWL::Mouse::Button::Backward] = 1<<15;
		m_buttonMap[OWL::Mouse::Button::Forward] = 1<<16;

		m_visible = true;
		m_wheel = 0;
	}
	virtual ~WinAPIMouse() {

	}

	virtual void setVisibility(bool _visible) {

		m_visible = _visible;
	}
	virtual bool isVisible() const {
		return m_visible;
	}

	virtual void setPosition(const Vec2i& _position) {

	}
	virtual Vec2i getPosition() const {

	}

	virtual int getWheelRotation() const {
		return m_wheel;
	}

	virtual bool isButtonPressed(unsigned int _button) const {

	}

public:
	virtual void pollPreparation() {
		m_wheel = 0;
	}
	virtual void pollSpecificEvents() {

	}

public:
	int m_wheel;
	bool m_visible;
};
}
}