#include <OWL/Input/Gamepad.hpp>

#include "Gamepad.hpp"

namespace OWL {

Gamepad::Gamepad() {
	memset(m_Buttons, 0, 15);
	m_IsConnected = false;
	m_LeftStick = Vec2f(0.0f);
	m_RightStick = Vec2f(0.0f);
	m_LeftTrigger = 0.0f;
	m_RightTrigger = 0.0f;
}
Gamepad::~Gamepad() {

}

bool Gamepad::IsConnected() const {
	return m_IsConnected;
}

bool Gamepad::IsButtonPressed(uint16_t _button) const {
	return m_Buttons[_button];
}

const Vec2f& Gamepad::GetLeftStick() const {
	return m_LeftStick;
}
const Vec2f& Gamepad::GetRightStick() const {
	return m_RightStick;
}

float Gamepad::GetLeftTrigger() const {
	return m_LeftTrigger;
	
}
float Gamepad::GetRightTrigger() const {
	return m_RightTrigger;
}

Gamepads::Gamepads() {
	#if defined OWL_SYSTEM_WINDOWS
		m_Impl = new Impl::WinAPIGamepads;
	#elif defined OWL_SYSTEM_LINUX

	#endif
}
Gamepads::~Gamepads() {
	delete m_Impl;
}

size_t Gamepads::GetCount() const {
	return m_Impl->GetCount();
}

const Gamepad& Gamepads::operator[](size_t _id) const {
	return m_Impl->operator[](_id);
}

}