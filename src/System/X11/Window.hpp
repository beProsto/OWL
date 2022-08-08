#pragma once

#include <OWL/Utility/Config.hpp>
#include <OWL/OS/Linux.hpp>

#include "../Window.hpp"

#define OWL_X11_WINDOW_EVENT_MASKS ExposureMask | ButtonPressMask | ButtonReleaseMask | EnterWindowMask | LeaveWindowMask | PointerMotionMask | PointerMotionHintMask | Button1MotionMask | Button2MotionMask | Button3MotionMask | Button4MotionMask | Button5MotionMask | ButtonMotionMask | KeymapStateMask | KeyPressMask | KeyReleaseMask

namespace OWL {
namespace Impl {

class OWL_API X11Window: public Window {
public:
	X11Window(Vec2ui _size, std::string _title, Keyboard* _keyboardImpl, Mouse* _mouseImpl, Gamepads* _gamepadsImpl) {
		m_isRunning = true;
		m_isFullScreen = false;
		m_contextImpl = nullptr;

		m_keyboardImpl = _keyboardImpl;
		m_keyboardImpl->m_windowImpl = this;

		m_mouseImpl = _mouseImpl;
		m_mouseImpl->m_windowImpl = this;

		m_gamepadsImpl = _gamepadsImpl;
		m_gamepadsImpl->m_windowImpl = this;

		m_display = XOpenDisplay(0);
		m_screenID = DefaultScreen(m_display);

		m_window = XCreateSimpleWindow(m_display, XRootWindow(m_display, m_screenID), 0, 0, _size.x, _size.y, 1, 0, 0);
		
		XSelectInput(m_display, m_window, OWL_X11_WINDOW_EVENT_MASKS);
		XMapWindow(m_display, m_window);

		XSetLocaleModifiers("");
		m_xIM = XOpenIM(m_display, 0, 0, 0);
		if(!m_xIM) {
			XSetLocaleModifiers("@im=none");
			m_xIM = XOpenIM(m_display, 0, 0, 0);
		}
		m_xIC = XCreateIC(
			m_xIM,
			XNInputStyle,   XIMPreeditNothing | XIMStatusNothing,
			XNClientWindow, m_window,
			XNFocusWindow, m_window,
			NULL
		);
		XSetICFocus(m_xIC);

		setTitle(_title);

		m_deleteWM = XInternAtom(m_display, "WM_DELETE_WINDOW", false);
		XSetWMProtocols(m_display, m_window, &m_deleteWM, 1);
	}
	virtual ~X11Window() {
		
	}

	virtual bool create(Vec2ui _size, std::string _title) {return false;}
	virtual void destroy() {}
	
	virtual void setContext(Context& _context) {}

	virtual void pollEvents() {
		while(XPending(m_display) > 0) {
			XNextEvent(m_display, &m_event);
			if(XFilterEvent(&m_event, 0L)) {
				continue;
			}

			if(m_event.type == ClientMessage) {
				if(m_event.xclient.data.l[0] == m_deleteWM) {
					close();
				}
			}
		}
	}

	virtual void setPosition(const Vec2i& _position) {}
	virtual Vec2i getPosition() const {return Vec2i{};}

	virtual void setSize(Vec2ui _size) {}
	virtual Vec2ui getSize() const {return Vec2ui{};}
	virtual float getAspect() const {return float{};}

	virtual void setTitle(std::string _title) {}
	virtual std::string getTitle() const {return "";}

	virtual void close() {
		m_isRunning = false;
	}
	virtual bool isRunning() const {
		return m_isRunning;
	}

	virtual bool isFocused() const {return false;}

	virtual void setFullScreen(bool _fullScreen) {}
	virtual bool isFullScreen() const {return false;}

public:
	::XEvent m_event;
	::XIM m_xIM;
	::XIC m_xIC;
	::Atom m_deleteWM;

	::Display* m_display;
	::Window m_window;
	int m_screenID;

	std::string m_title;
	bool m_isRunning;
	bool m_isFullScreen;
};

}
}