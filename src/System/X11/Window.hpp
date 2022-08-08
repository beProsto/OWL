#pragma once

#include <OWL/Utility/Config.hpp>
#include <OWL/OS/Linux.hpp>

#include "../Window.hpp"

namespace OWL {
namespace Impl {

class OWL_API X11Window: public Window {
public:
	X11Window(Vec2ui _size, std::string _title, Keyboard* _keyboardImpl, Mouse* _mouseImpl, Gamepads* _gamepadsImpl) {
		m_Running = true;
		m_FullScreen = false;

		*m_Section = XCreateSimpleWindow(m_Display, RootWindow(m_Display, *m_ScreenID), _position.x, _position.y, m_Size.x, m_Size.y, 1, 0, 0);
		XSelectInput(m_Display, *m_Section, OWL_X11_WINDOW_EVENT_MASKS);
		XMapWindow(m_Display, *m_Section);

		XSetLocaleModifiers("");
		m_XIM = XOpenIM(m_Display, 0, 0, 0);
		if(!m_XIM){
		XSetLocaleModifiers("@im=none");
		m_XIM = XOpenIM(m_Display, 0, 0, 0);
		}
		m_XIC = XCreateIC(m_XIM,
		XNInputStyle,   XIMPreeditNothing | XIMStatusNothing,
		XNClientWindow, m_Section,
		XNFocusWindow,  m_Section,
		NULL);
		XSetICFocus(m_XIC);

		SetTitle(_title);

		m_WMDelete = XInternAtom(m_Display, "WM_DELETE_WINDOW", false);
		XSetWMProtocols(m_Display, m_Section, &m_WMDelete, 1);
	}
	virtual ~X11Window() {
		
	}

	virtual bool create(Vec2ui _size, std::string _title) {return false;}
	virtual void destroy() {}
	
	virtual void setContext(Context& _context) {}

	virtual void pollEvents() {}

	virtual void setPosition(const Vec2i& _position) {}
	virtual Vec2i getPosition() const {return Vec2i{};}

	virtual void setSize(Vec2ui _size) {}
	virtual Vec2ui getSize() const {return Vec2ui{};}
	virtual float getAspect() const {return float{};}

	virtual void setTitle(std::string _title) {}
	virtual std::string getTitle() const {return "";}

	virtual void close() {}
	virtual bool isRunning() const {return false;}

	virtual bool isFocused() const {return false;}

	virtual void setFullScreen(bool _fullScreen) {}
	virtual bool isFullScreen() const {return false;}

public:
	Context* m_Context;

	js_event m_JSEvent;
	unsigned int m_MaxGamepads;

	::XEvent m_Event;
	::XIM m_XIM;
	::XIC m_XIC;
	::Atom m_WMDelete;

	::Display* m_Display;
	::Window m_Section;
	int m_ScreenID;

	std::string m_Title;
	bool m_Running;
	bool m_FullScreen;
};

}
}