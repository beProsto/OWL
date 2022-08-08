#pragma once

#include "../Mouse.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Windows.hpp>

namespace OWL {
namespace Impl {
class OWL_API X11Mouse: public Mouse {
public:
	X11Mouse() {
		m_buttonMap[OWL::Mouse::Button::Left] = 1<<8;
		m_buttonMap[OWL::Mouse::Button::Middle] = 1<<9;
		m_buttonMap[OWL::Mouse::Button::Right] = 1<<10;
		m_buttonMap[OWL::Mouse::Button::Backward] = 1<<15;
		m_buttonMap[OWL::Mouse::Button::Forward] = 1<<16;

		m_visible = true;
		m_wheel = 0;
	}
	virtual ~X11Mouse() {

	}

	virtual void setVisibility(bool _visible) {
		if(_visible && _visible != m_visible) {
			Cursor cursor;
			cursor = XCreateFontCursor(mstatic_cast<X11Window*>(m_windowImpl)->m_display, XC_left_ptr);
			XDefineCursor(mstatic_cast<X11Window*>(m_windowImpl)->m_display, mstatic_cast<X11Window*>(m_windowImpl)->m_window, cursor);
			XFreeCursor(mstatic_cast<X11Window*>(m_windowImpl)->m_display, cursor);
		}
		else if(!_visible && _visible != m_visible) {
			Cursor invisibleCursor;
			Pixmap bitmapNoData;
			XColor black;
			static char noData[] = {0, 0, 0, 0, 0, 0, 0, 0};
			black.red = black.green = black.blue = 0;

			bitmapNoData = XCreateBitmapFromData(mstatic_cast<X11Window*>(m_windowImpl)->m_display, mstatic_cast<X11Window*>(m_windowImpl)->m_window, noData, 8, 8);
			invisibleCursor = XCreatePixmapCursor(mstatic_cast<X11Window*>(m_windowImpl)->m_display, bitmapNoData, bitmapNoData, &black, &black, 0, 0);
			XDefineCursor(mstatic_cast<X11Window*>(m_windowImpl)->m_display, mstatic_cast<X11Window*>(m_windowImpl)->m_window, invisibleCursor);
			XFreeCursor(mstatic_cast<X11Window*>(m_windowImpl)->m_display, invisibleCursor);
			XFreePixmap(mstatic_cast<X11Window*>(m_windowImpl)->m_display, bitmapNoData);
		}
		m_visible = _visible;
	}
	virtual bool isVisible() const {
		return m_visible;
	}

	virtual void setPosition(const Vec2i& _position) {

	}
	virtual Vec2i getPosition() const {
		return Vec2i(0);
	}

	virtual int getWheelRotation() const {
		return m_wheel;
	}

	virtual bool isButtonPressed(unsigned int _button) const {
		return false;
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