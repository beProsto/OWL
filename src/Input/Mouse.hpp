#pragma once

#include <OWL/Input/Mouse.hpp>

namespace OWL {
namespace Impl {
class OWL_API Window;

class OWL_API Mouse {
public:
	Mouse() {}
	virtual ~Mouse() {}

	virtual void setVisibility(bool _visible) {}
	virtual bool isVisible() const {return false;}

	virtual void setPosition(const Vec2i& _position) {}
	virtual Vec2i getPosition() const {return Vec2i{};}

	virtual int getWheelRotation() const {return 0;}

	virtual bool isButtonPressed(unsigned int _button) const {return false;}

public:
	virtual void pollPreparation() {}
	virtual void pollSpecificEvents() {}

public:
	unsigned int m_buttonMap[OWL::Mouse::Button::Count];
	Window* m_windowImpl;
};
}
}

#if !defined _OWL_INCLUDE_WITHOUT_IMPLEMENTATION
#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/Mouse.hpp"

#elif defined OWL_SYSTEM_LINUX
	#include "X11/Mouse.hpp"

#endif
#endif