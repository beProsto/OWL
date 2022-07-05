#pragma once

#include "../Mouse.hpp"

#include <OWL/OS/Windows.hpp>

namespace OWL {
namespace Impl {
class OWL_API WinAPIMouse: public Mouse {
public:
	WinAPIMouse() {
		m_ButtonMap[OWL::Mouse::Button::Left] = VK_LBUTTON;
		m_ButtonMap[OWL::Mouse::Button::Middle] = VK_MBUTTON;
		m_ButtonMap[OWL::Mouse::Button::Right] = VK_RBUTTON;
		m_ButtonMap[OWL::Mouse::Button::Backward] = VK_XBUTTON1;
		m_ButtonMap[OWL::Mouse::Button::Forward] = VK_XBUTTON2;

		m_Visible = true;
		m_Wheel = 0;
	}
	virtual ~WinAPIMouse() {

	}

	virtual void SetVisibility(bool _visible) {
		ShowCursor(_visible);
		m_Visible = _visible;
	}
	virtual bool IsVisible() const {
		return m_Visible;
	}

	virtual void SetPosition(const Vec2i& _position) {
		POINT p;
		p.x = _position.x;
		p.y = _position.y;
		ClientToScreen(m_Hwnd, &p);
		SetCursorPos(p.x, p.y);
	}
	virtual Vec2i GetPosition() const {
		POINT p;
		GetCursorPos(&p);
		ScreenToClient(m_Hwnd, &p);
		return Vec2<int>(p.x, p.y);
	}

	virtual int GetWheelRotation() const {
		return m_Wheel;
	}
	virtual bool IsButtonPressed(unsigned int _button) const {
		return GetKeyState(m_ButtonMap[_button]) & 0x100;;
	}

public:
	int m_Wheel;
	bool m_Visible;
	HWND m_Hwnd;
};
}
}