#pragma once

#include <OWL/Utility/Config.hpp>

namespace OWL {
namespace Input {

enum class GamepadButton {
	A,
	B,
	X,
	Y,
	Start,
	Back,
	ShoulderLeft,
	ShoulderRight,
	ThumbLeft,
	ThumbRight,
	DPadUp,
	DPadDown,
	DPadLeft,
	DPadRight,
	Logo
};

namespace Impl {
class OWL_API Gamepad;
class OWL_API Gamepads;
}

class OWL_API Gamepad {
public:
	Gamepad();
	~Gamepad();
	
	bool IsConnected() const;
	
	bool IsButtonPressed(GamepadButton _button) const;

	float GetLeftTrigger() const;
	float GetRightTrigger() const;

	Vec2f GetLeftStick() const;
	Vec2f GetRightStick() const;

private:
	Impl::Gamepad* m_Impl;
};

class OWL_API Gamepads {
public:
	Gamepads();
	~Gamepads();

	const Gamepad& operator[](unsigned int _id) const;

	unsigned int GetMaxGamepadsCount() const;
	void SetMaxGamepadsCount(unsigned int _count);

protected:
	void PollEvents();

	// friend Window;

private:
	Impl::Gamepads* m_Impl;
};

}
}