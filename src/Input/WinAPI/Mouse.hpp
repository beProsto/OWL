#pragma once

#include "../mouse.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Windows.hpp>

namespace OWL {
namespace Impl {
class OWL_API WinAPIMouse: public Mouse {
public:
	WinAPIMouse() {
		m_buttonMap[OWL::Mouse::Button::Left] = VK_LBUTTON;
		m_buttonMap[OWL::Mouse::Button::Middle] = VK_MBUTTON;
		m_buttonMap[OWL::Mouse::Button::Right] = VK_RBUTTON;
		m_buttonMap[OWL::Mouse::Button::Backward] = VK_XBUTTON1;
		m_buttonMap[OWL::Mouse::Button::Forward] = VK_XBUTTON2;

		m_visible = true;
		m_wheel = 0;
	}
	virtual ~WinAPIMouse() {

	}

	virtual void setVisibility(bool _visible) {
		ShowCursor(_visible);
		m_visible = _visible;
	}
	virtual bool isVisible() const {
		return m_visible;
	}

	virtual void setPosition(const Vec2i& _position) {
		POINT p;
		p.x = _position.x;
		p.y = _position.y;
		ClientToScreen(static_cast<WinAPIWindow*>(m_windowImpl)->m_hwnd, &p);
		SetCursorPos(p.x, p.y);
	}
	virtual Vec2i getPosition() const {
		POINT p;
		GetCursorPos(&p);
		ScreenToClient(static_cast<WinAPIWindow*>(m_windowImpl)->m_hwnd, &p);
		return Vec2<int>(p.x, p.y);
	}

	virtual int getWheelRotation() const {
		return m_wheel;
	}

	virtual bool isButtonPressed(unsigned int _button) const {
		return GetKeyState(m_buttonMap[_button]) & 0x100;
	}

public:
	virtual void pollPreparation() {
		m_wheel = 0;
	}
	virtual void pollSpecificEvents() {
		if(static_cast<WinAPIWindow*>(m_windowImpl)->m_event.message == WM_MOUSEWHEEL) {
			m_wheel = GET_WHEEL_DELTA_WPARAM(static_cast<WinAPIWindow*>(m_windowImpl)->m_event.wParam);
		}
	}

public:
	int m_wheel;
	bool m_visible;
};
}
}