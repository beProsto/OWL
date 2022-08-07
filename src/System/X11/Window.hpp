#pragma once

#include <OWL/Utility/Config.hpp>
#include <OWL/OS/Linux.hpp>

#include "../Window.hpp"

namespace OWL {
namespace Impl {

class OWL_API X11Window: public Window {
public:
	X11Window(Vec2ui _size, std::string _title, Keyboard* _keyboardImpl, Mouse* _mouseImpl, Gamepads* _gamepadsImpl) {

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