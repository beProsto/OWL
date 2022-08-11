#pragma once

#include "../Gamepad.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Linux.hpp>

namespace OWL {
namespace Impl {

struct OWL_API X11GamepadMetaData {
	int js = -1;
	Vec2f leftStickInternal = Vec2f(0.0f);
	Vec2f rightStickInternal = Vec2f(0.0f);
};

// THIS IS CURRENTLY MID-DEVELOPEMENT
// THE DEBUG MESSAGES HAVE TO BE HERE FOR AT LEAST A FEW COMMITS

class OWL_API X11Gamepads: public Gamepads {
public:
	X11Gamepads() {
		m_gamepadsCount = 4;
		m_gamepads = new Gamepad[m_gamepadsCount]();
		m_meta = new X11GamepadMetaData[m_gamepadsCount];
	}
	virtual ~X11Gamepads() {
		delete[] m_gamepads;
	}

	virtual void setCount(unsigned int _gamepadsCount) {
		if(_gamepadsCount != m_gamepadsCount) {
			delete[] m_gamepads;
			delete[] m_meta;

			m_gamepadsCount = _gamepadsCount;
			m_gamepads = new Gamepad[m_gamepadsCount]();
			m_meta = new X11GamepadMetaData[m_gamepadsCount];
		}
	}

public:
	virtual void pollPreparation() {
		for(unsigned int i = 0; i < m_gamepadsCount; i++) {
			while(read(m_meta[i].js, &m_jsEvent, sizeof(m_jsEvent)) > 0) {
				if(m_jsEvent.type == JS_EVENT_BUTTON) {
					m_gamepads[i].m_buttons[m_jsEvent.number] = m_jsEvent.value;
				}
				else if(m_jsEvent.type == JS_EVENT_AXIS) {
					switch(m_jsEvent.number) {
						case 0: m_meta[i].leftStickInternal.x = (float)m_jsEvent.value; break;
						case 1: m_meta[i].leftStickInternal.y = (float)m_jsEvent.value; break;
						case 2: m_gamepads[i].m_leftTrigger = (float)m_jsEvent.value / 32767.0f / 2.0f + 0.5f; break;
						case 3: m_meta[i].rightStickInternal.x = (float)m_jsEvent.value; break;
						case 4: m_meta[i].rightStickInternal.y = (float)m_jsEvent.value; break;
						case 5: m_gamepads[i].m_rightTrigger = (float)m_jsEvent.value / 32767.0f / 2.0f + 0.5f; break;
					}
				}
			}

			if(m_meta[i].leftStickInternal != Vec2f(0.0f)) {
				m_gamepads[i].m_leftStick = stickNorm(m_meta[i].leftStickInternal.x, m_meta[i].leftStickInternal.y);
			}
			if(m_meta[i].rightStickInternal != Vec2f(0.0f)) {
				m_gamepads[i].m_rightStick = stickNorm(m_meta[i].rightStickInternal.x, m_meta[i].rightStickInternal.y);
			}

			if(errno == ENODEV || m_meta[i].js == -1) {
				m_meta[i].js = open(std::string("/dev/input/js" + std::to_string(i)).c_str(), O_NONBLOCK);
			}
		}
	}
	virtual void pollSpecificEvents() {

	}

public:
	js_event m_jsEvent;
	X11GamepadMetaData* m_meta;

};
}
}