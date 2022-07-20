#pragma once

#include <OWL/Input/Gamepad.hpp>

#include <cmath>

namespace OWL {
namespace Impl {
class OWL_API Window;

class OWL_API Gamepads {
public:
	Gamepads() {}
	virtual ~Gamepads() {}
	
	virtual void SetCount(unsigned int _gamepadsCount) {}
	virtual size_t GetCount() const { return m_GamepadsCount; }
	
	virtual const Gamepad& operator[](size_t _id) const { return m_Gamepads[_id]; }

	virtual void PollSpecificEvents() {}

	static inline OWL::Vec2f StickNorm(float _x, float _y) {
		float magnitude = std::sqrt(_x*_x + _y*_y);
		float normalizedLX = _x / magnitude;
		float normalizedLY = _y / magnitude;
		float normalizedMagnitude = 0;
		if (magnitude > 7849) {
			if (magnitude > 32767) magnitude = 32767;
			magnitude -= 7849;
			normalizedMagnitude = magnitude / (32767 - 7849);
		}
		else {
			magnitude = 0.0;
			normalizedMagnitude = 0.0;
		}
		return OWL::Vec2f(normalizedLX * normalizedMagnitude, normalizedLY * normalizedMagnitude);
	}

public:
	size_t m_GamepadsCount;
	Gamepad* m_Gamepads;
	Window* m_WindowImpl;
};
}
}

#if !defined _OWL_INCLUDE_WITHOUT_IMPLEMENTATION
#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/Gamepad.hpp"
#elif defined OWL_SYSTEM_LINUX

#endif
#endif