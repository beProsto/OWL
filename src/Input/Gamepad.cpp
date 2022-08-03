#include <OWL/Input/Gamepad.hpp>

#include "Gamepad.hpp"

#include <string.h>

namespace OWL {

Gamepad::Gamepad() {
	memset(m_buttons, 0, 15);
	m_isConnected = false;
	m_leftStick = Vec2f(0.0f);
	m_rightStick = Vec2f(0.0f);
	m_leftTrigger = 0.0f;
	m_rightTrigger = 0.0f;
}
Gamepad::~Gamepad() {

}

bool Gamepad::isConnected() const {
	return m_isConnected;
}

bool Gamepad::isButtonPressed(uint16_t _button) const {
	return m_buttons[_button];
}

const Vec2f& Gamepad::getLeftStick() const {
	return m_leftStick;
}
const Vec2f& Gamepad::getRightStick() const {
	return m_rightStick;
}

float Gamepad::getLeftTrigger() const {
	return m_leftTrigger;
	
}
float Gamepad::getRightTrigger() const {
	return m_rightTrigger;
}

Gamepads::Gamepads() {
	#if defined OWL_SYSTEM_WINDOWS
		m_impl = new Impl::WinAPIGamepads;
	#elif defined OWL_SYSTEM_LINUX

	#endif
}
Gamepads::~Gamepads() {
	delete m_impl;
}

void Gamepads::setCount(unsigned int _gamepadsCount) {
	m_impl->setCount(_gamepadsCount);
}
unsigned int Gamepads::getCount() const {
	return m_impl->getCount();
}

const Gamepad& Gamepads::operator[](size_t _id) const {
	return m_impl->operator[](_id);
}

}