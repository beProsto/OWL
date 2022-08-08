#pragma once

#include <OWL/Utility/Config.hpp>
#include <OWL/OS/Linux.hpp>

#include "../Window.hpp"

// ExposureMask | ButtonPressMask | ButtonReleaseMask | EnterWindowMask | LeaveWindowMask | PointerMotionMask | PointerMotionHintMask | Button1MotionMask | Button2MotionMask | Button3MotionMask | Button4MotionMask | Button5MotionMask | ButtonMotionMask | KeymapStateMask | KeyPressMask | KeyReleaseMask

#define OWL_X11_WINDOW_EVENT_MASKS KeymapStateMask | KeyPressMask | KeyReleaseMask

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

		create(_size, _title);
	}
	virtual ~X11Window() {
		destroy();
	}

	virtual bool create(Vec2ui _size, std::string _title) {
		m_title = "";

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
		
		return true;
	}
	virtual void destroy() {
		XDestroyIC(m_xIC);
		XCloseIM(m_xIM);
		XDestroyWindow(m_display, m_window);
		XCloseDisplay(m_display);
	}
	
	virtual void setContext(Context& _context) {}

	virtual void pollEvents() {
		m_mouseImpl->pollPreparation();
		m_keyboardImpl->pollPreparation();
		m_gamepadsImpl->pollPreparation();

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

			m_mouseImpl->pollSpecificEvents();
			m_keyboardImpl->pollSpecificEvents();
			// m_gamepadsImpl->pollSpecificEvents(); // No need
		}
	}

	virtual void setPosition(const Vec2i& _position) {
		XMoveWindow(m_display, m_window, _position.x, _position.y);
	}
	virtual Vec2i getPosition() const {
		int x, y;
		::Window child;
		::XWindowAttributes xwa;
		XTranslateCoordinates(m_display, m_window, XDefaultRootWindow(m_display), 0, 0, &x, &y, &child);
		XGetWindowAttributes(m_display, m_window, &xwa);
		
		return Vec2i(x - xwa.x, y - xwa.y);
	}

	virtual void setSize(Vec2ui _size) {
		XResizeWindow(m_display, m_window, _size.x, _size.y);
	}
	virtual Vec2ui getSize() const {
		Vec2ui sizeReturned;

		::Window tmpRoot; unsigned int tmpUnsignedInt; int tmpInt;
		XGetGeometry(m_display, m_window, &tmpRoot, &tmpInt, &tmpInt, &sizeReturned.x, &sizeReturned.y, &tmpUnsignedInt, &tmpUnsignedInt);

		return sizeReturned;
	}
	virtual float getAspect() const {
		Vec2f size = getSize();
		return size.x / size.y;
	}

	virtual void setTitle(std::string _title) {
		if(m_title != _title) {
			m_title = _title;
			XStoreName(m_display, m_window, m_title.c_str());
		}
	}
	virtual std::string getTitle() const {
		return m_title;
	}

	virtual void close() {
		m_isRunning = false;
	}
	virtual bool isRunning() const {
		return m_isRunning;
	}

	virtual bool isFocused() const {
		::Window focused;
		int revert_to;
		XGetInputFocus(m_display, &focused, &revert_to);
		return focused == m_window;
	}

	virtual void setFullScreen(bool _fullScreen) {		
		if(m_isFullScreen != _fullScreen) {
			XEvent event;
			Atom stateAtom;
			Atom fsAtom;

			stateAtom = XInternAtom(m_display, "_NET_WM_STATE", 0);
			fsAtom = XInternAtom(m_display, "_NET_WM_STATE_FULLSCREEN", 0);

			event.xclient.type = ClientMessage;
			event.xclient.serial = 0;
			event.xclient.send_event = 1;
			event.xclient.window = m_window;
			event.xclient.message_type = stateAtom;
			event.xclient.format = 32;
			event.xclient.data.l[0] = _fullScreen; /* usage of atoms: 0 (false) - remove atom; 1 (true) - add atom; 2 - toggle; */
			event.xclient.data.l[1] = fsAtom;
			event.xclient.data.l[2] = 0;

			XSendEvent(m_display, XDefaultRootWindow(m_display), 0, SubstructureRedirectMask | SubstructureNotifyMask, &event);
			m_isFullScreen = _fullScreen;
		}
	}
	virtual bool isFullScreen() const {
		return m_isFullScreen;
	}

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