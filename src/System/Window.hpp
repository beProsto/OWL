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

	virtual bool Create(Vec2ui _size, std::string _title) {return false;}
	virtual void Destroy() {}
	
	virtual void SetContext(Context& _context) {}

	virtual void PollEvents() {}

	virtual void SetPosition(const Vec2i& _position) {}
	virtual Vec2i GetPosition() const {return Vec2i{};}

	virtual void SetSize(Vec2ui _size) {}
	virtual Vec2ui GetSize() const {return Vec2ui{};}
	virtual float GetAspect() const {return float{};}

	virtual void SetTitle(std::string _title) {}
	virtual std::string GetTitle() const {return "";}

	virtual void Close() {}
	virtual bool IsRunning() const {return false;}

	virtual bool IsFocused() const {return false;}

	virtual void SetFullScreen(bool _fullScreen) {}
	virtual bool IsFullScreen() const {return false;}

public:
	Context* m_ContextImpl;
	Keyboard* m_KeyboardImpl;
	Mouse* m_MouseImpl;
	Gamepads* m_GamepadsImpl;
};

}
}

#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/Window.hpp"
#elif defined OWL_SYSTEM_LINUX
	#include "Wayland/Window.hpp"
	#include "X11/Window.hpp"
#endif