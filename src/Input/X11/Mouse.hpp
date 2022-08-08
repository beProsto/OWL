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
			cursor = XCreateFontCursor(static_cast<X11Window*>(m_windowImpl)->m_display, XC_left_ptr);
			XDefineCursor(static_cast<X11Window*>(m_windowImpl)->m_display, static_cast<X11Window*>(m_windowImpl)->m_window, cursor);
			XFreeCursor(static_cast<X11Window*>(m_windowImpl)->m_display, cursor);
		}
		else if(!_visible && _visible != m_visible) {
			Cursor invisibleCursor;
			Pixmap bitmapNoData;
			XColor black;
			static char noData[] = {0, 0, 0, 0, 0, 0, 0, 0};
			black.red = black.green = black.blue = 0;

			bitmapNoData = XCreateBitmapFromData(static_cast<X11Window*>(m_windowImpl)->m_display, static_cast<X11Window*>(m_windowImpl)->m_window, noData, 8, 8);
			invisibleCursor = XCreatePixmapCursor(static_cast<X11Window*>(m_windowImpl)->m_display, bitmapNoData, bitmapNoData, &black, &black, 0, 0);
			XDefineCursor(static_cast<X11Window*>(m_windowImpl)->m_display, static_cast<X11Window*>(m_windowImpl)->m_window, invisibleCursor);
			XFreeCursor(static_cast<X11Window*>(m_windowImpl)->m_display, invisibleCursor);
			XFreePixmap(static_cast<X11Window*>(m_windowImpl)->m_display, bitmapNoData);
		}
		m_visible = _visible;
	}
	virtual bool isVisible() const {
		return m_visible;
	}

	virtual void setPosition(const Vec2i& _position) {
		XWarpPointer(static_cast<X11Window*>(m_windowImpl)->m_display, 0L, static_cast<X11Window*>(m_windowImpl)->m_window, 0, 0, 0, 0, _position.x, _position.y);
	}
	virtual Vec2i getPosition() const {
		int xReturned, yReturned;

		int tmpInt; ::Window tmpRoot, tmpWin;
		XQueryPointer(static_cast<X11Window*>(m_windowImpl)->m_display, static_cast<X11Window*>(m_windowImpl)->m_window, &tmpRoot, &tmpWin, &tmpInt, &tmpInt, &xReturned, &yReturned, (unsigned int*)&tmpInt);

		return OWL::Vec2i(xReturned, yReturned);
	}

	virtual int getWheelRotation() const {
		return m_wheel;
	}

	virtual bool isButtonPressed(unsigned int _button) const {
		unsigned int buttonPressed;

		int tmpInt; ::Window tmpRoot, tmpWin;
		XQueryPointer(static_cast<X11Window*>(m_windowImpl)->m_display, static_cast<X11Window*>(m_windowImpl)->m_window, &tmpRoot, &tmpWin, &tmpInt, &tmpInt, &tmpInt, &tmpInt, &buttonPressed);
		
		return (buttonPressed & m_buttonMap[_button]);
	}

public:
	virtual void pollPreparation() {
		m_wheel = 0;
	}
	virtual void pollSpecificEvents() {
		if(static_cast<X11Window*>(m_windowImpl)->m_event.type == ButtonPress) {
			if(static_cast<X11Window*>(m_windowImpl)->m_event.xbutton.button == Button4) {
				m_wheel += 1;
			}
			else if(static_cast<X11Window*>(m_windowImpl)->m_event.xbutton.button == Button5) {
				m_wheel -= 1;
			}
		}
	}

public:
	int m_wheel;
	bool m_visible;
};
}
}