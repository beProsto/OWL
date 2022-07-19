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
	bool IsButtonPressed(unsigned int _button) const;

	const Vec2f& GetLeftStick() const;
	const Vec2f& GetRightStick() const;
	float GetLeftTrigger() const;
	float GetRightTrigger() const;

public:
	enum Button {
		A = 1,
		B = 2,
		X = 4,
		Y = 8,
		ShoulderLeft = 16,
		ShoulderRight = 32,
		Back = 64,
		Start = 128,
		Logo = 256,
		ThumbLeft = 512,
		ThumbRight = 1024,
		DPadLeft = 2048,
		DPadRight = 4096,
		DPadUp = 8192,
		DPadDown = 16384
	};

protected:
	uint16_t m_Buttons;

	friend class Gamepads;
	friend class Window;
};

class OWL_API Gamepads {
public:
	Gamepads();
	~Gamepads();

	const Gamepad& operator[](size_t _id) const;

protected:
	Impl::Gamepads* m_Gamepads;

	friend class Window;
};


}