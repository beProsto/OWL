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

	bool isConnected() const;

	bool isButtonPressed(uint16_t _button) const;

	const Vec2f& getLeftStick() const;
	const Vec2f& getRightStick() const;

	float getLeftTrigger() const;
	float getRightTrigger() const;

public:
	enum Button {
		A = 0,
		B = 1,
		X = 2,
		Y = 3,
		ShoulderLeft = 4,
		ShoulderRight = 5,
		Back = 6,
		start = 7,
		Logo = 8,
		ThumbLeft = 9,
		ThumbRight = 10,
		DPadLeft = 11,
		DPadRight = 12,
		DPadUp = 13,
		DPadDown = 14
	};

public:
	bool m_isConnected;
	bool m_buttons[15];
	float m_leftTrigger;
	float m_rightTrigger;
	Vec2f m_leftStick;
	Vec2f m_rightStick;
};

class OWL_API Gamepads {
public:
	Gamepads();
	~Gamepads();

	void setCount(unsigned int _gamepadsCount);
	unsigned int getCount() const;

	const Gamepad& operator[](size_t _id) const;

protected:
	Impl::Gamepads* m_impl;

	friend class Window;
};


}