#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/System/Window.hpp>

#define _OWL_INCLUDE_WITHOUT_IMPLEMENTATION
#include "../Graphics/Context.hpp"
#include "../Input/Keyboard.hpp"
#include "../Input/Mouse.hpp"
#include "../Input/Gamepad.hpp"
#undef _OWL_INCLUDE_WITHOUT_IMPLEMENTATION

namespace OWL {
namespace Impl {

class OWL_API Window {
public:
	Window() {}
	virtual ~Window() {}

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
	Context* m_contextImpl;
	Keyboard* m_keyboardImpl;
	Mouse* m_mouseImpl;
	Gamepads* m_gamepadsImpl;
};

}
}

#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/Window.hpp"
#elif defined OWL_SYSTEM_LINUX
	#include "Wayland/Window.hpp"
	#include "X11/Window.hpp"
#endif