#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/System/Window.hpp>

namespace OWL {
namespace Impl {

class OWL_API Window {
public:
	Window() {}
	virtual ~Window() {}
	
	virtual void PollEvents() {}

	virtual void SetPosition(const Vec2i& _position) {}
	virtual Vec2i GetPosition() const {return Vec2i{};}

	virtual void SetSize(const Vec2ui& _size) {}
	virtual Vec2ui GetSize() const {return Vec2ui{};}
	virtual float GetAspect() const {return float{};}

	virtual void SetTitle(std::string _title) {}
	virtual std::string GetTitle() const {return "";}

	virtual void Close() {}
	virtual bool IsRunning() const {return false;}

	virtual bool IsFocused() const {return false;}

	virtual void SetFullScreen(bool _fullScreen) {}
	virtual bool IsFullScreen() const {return false;}
};

}
}

#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/Window.hpp"
#elif defined OWL_SYSTEM_LINUX
	#include "Linux/Wayland/Window.hpp"
	#include "Linux/X11/Window.hpp"
#endif