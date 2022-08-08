#pragma once

#include "../Gamepad.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Windows.hpp>

#include <xinput.h>

namespace OWL {
namespace Impl {
class OWL_API WinAPIGamepads: public Gamepads {
public:
	WinAPIGamepads() {
		m_gamepadsCount = 4;
		m_gamepads = new Gamepad[m_gamepadsCount]();
	}
	virtual ~WinAPIGamepads() {
		delete[] m_gamepads;
	}

	virtual void setCount(unsigned int _gamepadsCount) {
		if(_gamepadsCount != m_gamepadsCount) {
			delete[] m_gamepads;

			m_gamepadsCount = _gamepadsCount;
			m_gamepads = new Gamepad[m_gamepadsCount]();
		}
	}

public:
	virtual void pollPreparation() {
		for(unsigned int i = 0; i < m_gamepadsCount; i++) {
			// Setting up the controller's state
			XINPUT_STATE state;
			ZeroMemory(&state, sizeof(XINPUT_STATE)); // why? what's the difference if i don't? it's not allocated on the heap so it technically should zero itself out by.. itself... But then why do the docs tell me to do this?
			// Simply get the state of the controller from XInput.
			if((m_gamepads[i].m_isConnected = (XInputGetState(i, &state) == ERROR_SUCCESS))) {
				// Controller is connected
				m_gamepads[i].m_leftStick = stickNorm(state.Gamepad.sThumbLX, state.Gamepad.sThumbLY);
				m_gamepads[i].m_rightStick = stickNorm(state.Gamepad.sThumbRX, state.Gamepad.sThumbRY);
				
				m_gamepads[i].m_leftTrigger = (float)state.Gamepad.bLeftTrigger / 255;
				m_gamepads[i].m_rightTrigger = (float)state.Gamepad.bRightTrigger / 255;

				m_gamepads[i].m_buttons[OWL::Gamepad::A] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0;
				m_gamepads[i].m_buttons[OWL::Gamepad::B] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_B) != 0;
				m_gamepads[i].m_buttons[OWL::Gamepad::X] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_X) != 0;
				m_gamepads[i].m_buttons[OWL::Gamepad::Y] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) != 0;
				
				m_gamepads[i].m_buttons[OWL::Gamepad::Start] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_START) != 0;
				m_gamepads[i].m_buttons[OWL::Gamepad::Back] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) != 0;

				m_gamepads[i].m_buttons[OWL::Gamepad::ShoulderLeft] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) != 0;
				m_gamepads[i].m_buttons[OWL::Gamepad::ShoulderRight] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) != 0;

				m_gamepads[i].m_buttons[OWL::Gamepad::ThumbLeft] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) != 0;
				m_gamepads[i].m_buttons[OWL::Gamepad::ThumbRight] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) != 0;

				m_gamepads[i].m_buttons[OWL::Gamepad::DPadUp] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) != 0;
				m_gamepads[i].m_buttons[OWL::Gamepad::DPadDown] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) != 0;
				m_gamepads[i].m_buttons[OWL::Gamepad::DPadLeft] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) != 0;
				m_gamepads[i].m_buttons[OWL::Gamepad::DPadRight] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) != 0;
			}
		}
	}
	virtual void pollSpecificEvents() {

	}
};
}
}