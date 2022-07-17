#pragma once

#include <OWL/Input/Mouse.hpp>

namespace OWL {
namespace Impl {
class OWL_API Window;

class OWL_API Mouse {
public:
	Mouse() {}
	virtual ~Mouse() {}

	virtual void SetVisibility(bool _visible) {}
	virtual bool IsVisible() const {return false;}

	virtual void SetPosition(const Vec2i& _position) {}
	virtual Vec2i GetPosition() const {return Vec2i{};}

	virtual int GetWheelRotation() const {return 0;}
	virtual bool IsButtonPressed(unsigned int _button) const {return false;}

public:
	unsigned int m_ButtonMap[OWL::Mouse::Button::Count];
	Window* m_WindowImpl;
};
}
}

#if !defined _OWL_INCLUDE_WITHOUT_IMPLEMENTATION
#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/Mouse.hpp"
#elif defined OWL_SYSTEM_LINUX

		// 	m_ButtonMap[0] = 1<<8;
		// 	m_ButtonMap[1] = 1<<9;
		// 	m_ButtonMap[2] = 1<<10;
		// 	m_ButtonMap[3] = 1<<15;
		// 	m_ButtonMap[4] = 1<<16;

#endif
#endif