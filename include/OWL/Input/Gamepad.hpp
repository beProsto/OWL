#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/Utility/Vec2.hpp>

#include <stdint.h>

namespace OWL {

namespace Impl {
class OWL_API Gamepads;
}

class OWL_API Gamepad {
public:
	Gamepad();
	~Gamepad();

	bool IsConnected() const;

	bool IsButtonPressed(uint16_t _button) const;

	const Vec2f& GetLeftStick() const;
	const Vec2f& GetRightStick() const;

	float GetLeftTrigger() const;
	float GetRightTrigger() const;

public:
	enum Button {
		A = 0,
		B = 1,
		X = 2,
		Y = 3,
		ShoulderLeft = 4,
		ShoulderRight = 5,
		Back = 6,
		Start = 7,
		Logo = 8,
		ThumbLeft = 9,
		ThumbRight = 10,
		DPadLeft = 11,
		DPadRight = 12,
		DPadUp = 13,
		DPadDown = 14
	};

public:
	bool m_IsConnected;
	bool m_Buttons[15];
	float m_LeftTrigger;
	float m_RightTrigger;
	Vec2f m_LeftStick;
	Vec2f m_RightStick;
};

class OWL_API Gamepads {
public:
	Gamepads();
	~Gamepads();

	size_t GetCount() const;

	const Gamepad& operator[](size_t _id) const;

protected:
	Impl::Gamepads* m_Impl;

	friend class Window;
};


}