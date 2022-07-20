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
		m_GamepadsCount = 4;
		m_Gamepads = new Gamepad[m_GamepadsCount]();
	}
	virtual ~WinAPIGamepads() {
		delete[] m_Gamepads;
	}

	virtual void SetCount(unsigned int _gamepadsCount) {
		if(_gamepadsCount != m_GamepadsCount) {
			delete[] m_Gamepads;

			m_GamepadsCount = _gamepadsCount;
			m_Gamepads = new Gamepad[m_GamepadsCount]();
		}
	}

public:
	virtual void PollSpecificEvents() {
		for(unsigned int i = 0; i < m_GamepadsCount; i++) {
			// Setting up the controller's state
			XINPUT_STATE state;
			ZeroMemory(&state, sizeof(XINPUT_STATE)); // why? what's the difference if i don't? it's not allocated on the heap so it technically should zero itself out by.. itself... But then why do the docs tell me to do this?
			// Simply get the state of the controller from XInput.
			if((m_Gamepads[i].m_IsConnected = (XInputGetState(i, &state) == ERROR_SUCCESS))) {
				// Controller is connected
				m_Gamepads[i].m_LeftStick = StickNorm(state.Gamepad.sThumbLX, state.Gamepad.sThumbLY);
				m_Gamepads[i].m_RightStick = StickNorm(state.Gamepad.sThumbRX, state.Gamepad.sThumbRY);
				
				m_Gamepads[i].m_LeftTrigger = (float)state.Gamepad.bLeftTrigger / 255;
				m_Gamepads[i].m_RightTrigger = (float)state.Gamepad.bRightTrigger / 255;

				m_Gamepads[i].m_Buttons[OWL::Gamepad::A] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0;
				m_Gamepads[i].m_Buttons[OWL::Gamepad::B] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_B) != 0;
				m_Gamepads[i].m_Buttons[OWL::Gamepad::X] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_X) != 0;
				m_Gamepads[i].m_Buttons[OWL::Gamepad::Y] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) != 0;
				
				m_Gamepads[i].m_Buttons[OWL::Gamepad::Start] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_START) != 0;
				m_Gamepads[i].m_Buttons[OWL::Gamepad::Back] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) != 0;

				m_Gamepads[i].m_Buttons[OWL::Gamepad::ShoulderLeft] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) != 0;
				m_Gamepads[i].m_Buttons[OWL::Gamepad::ShoulderRight] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) != 0;

				m_Gamepads[i].m_Buttons[OWL::Gamepad::ThumbLeft] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) != 0;
				m_Gamepads[i].m_Buttons[OWL::Gamepad::ThumbRight] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) != 0;

				m_Gamepads[i].m_Buttons[OWL::Gamepad::DPadUp] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) != 0;
				m_Gamepads[i].m_Buttons[OWL::Gamepad::DPadDown] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) != 0;
				m_Gamepads[i].m_Buttons[OWL::Gamepad::DPadLeft] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) != 0;
				m_Gamepads[i].m_Buttons[OWL::Gamepad::DPadRight] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) != 0;
			}
		}
	}
};
}
}