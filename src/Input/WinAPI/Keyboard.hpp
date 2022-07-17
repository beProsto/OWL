#pragma once

#include "../Keyboard.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Windows.hpp>

namespace OWL {
namespace Impl {
class OWL_API WinAPIKeyboard: public Keyboard {
public:
	WinAPIKeyboard() {
		m_KeyMap[OWL::Keyboard::Key::ShiftLeft] = VK_LSHIFT;
		m_KeyMap[OWL::Keyboard::Key::ShiftRight] = VK_RSHIFT;
		m_KeyMap[OWL::Keyboard::Key::CtrlLeft] = VK_LCONTROL;
		m_KeyMap[OWL::Keyboard::Key::CtrlRight] = VK_RCONTROL;
		m_KeyMap[OWL::Keyboard::Key::Enter] = VK_RETURN;
		m_KeyMap[OWL::Keyboard::Key::CapsLock] = VK_CAPITAL;
		m_KeyMap[OWL::Keyboard::Key::Tab] = VK_TAB;
		m_KeyMap[OWL::Keyboard::Key::Apostrophe] = VK_OEM_7;
		m_KeyMap[OWL::Keyboard::Key::Escape] = VK_ESCAPE;
		m_KeyMap[OWL::Keyboard::Key::AltLeft] = VK_LMENU;
		m_KeyMap[OWL::Keyboard::Key::AltRight] = VK_RMENU;
		m_KeyMap[OWL::Keyboard::Key::Backspace] = VK_BACK;
		m_KeyMap[OWL::Keyboard::Key::Space] = VK_SPACE;
		m_KeyMap[OWL::Keyboard::Key::Num1] = 0x31;
		m_KeyMap[OWL::Keyboard::Key::Num2] = 0x32;
		m_KeyMap[OWL::Keyboard::Key::Num3] = 0x33;
		m_KeyMap[OWL::Keyboard::Key::Num4] = 0x34;
		m_KeyMap[OWL::Keyboard::Key::Num5] = 0x35;
		m_KeyMap[OWL::Keyboard::Key::Num6] = 0x36;
		m_KeyMap[OWL::Keyboard::Key::Num7] = 0x37;
		m_KeyMap[OWL::Keyboard::Key::Num8] = 0x38;
		m_KeyMap[OWL::Keyboard::Key::Num9] = 0x39;
		m_KeyMap[OWL::Keyboard::Key::Num0] = 0x30;
		m_KeyMap[OWL::Keyboard::Key::NumPad1] = VK_NUMPAD1;
		m_KeyMap[OWL::Keyboard::Key::NumPad2] = VK_NUMPAD2;
		m_KeyMap[OWL::Keyboard::Key::NumPad3] = VK_NUMPAD3;
		m_KeyMap[OWL::Keyboard::Key::NumPad4] = VK_NUMPAD4;
		m_KeyMap[OWL::Keyboard::Key::NumPad5] = VK_NUMPAD5;
		m_KeyMap[OWL::Keyboard::Key::NumPad6] = VK_NUMPAD6;
		m_KeyMap[OWL::Keyboard::Key::NumPad7] = VK_NUMPAD7;
		m_KeyMap[OWL::Keyboard::Key::NumPad8] = VK_NUMPAD8;
		m_KeyMap[OWL::Keyboard::Key::NumPad9] = VK_NUMPAD9;
		m_KeyMap[OWL::Keyboard::Key::NumPad0] = VK_NUMPAD0;
		m_KeyMap[OWL::Keyboard::Key::Q] = 0x51;
		m_KeyMap[OWL::Keyboard::Key::W] = 0x57;
		m_KeyMap[OWL::Keyboard::Key::E] = 0x45;
		m_KeyMap[OWL::Keyboard::Key::R] = 0x52;
		m_KeyMap[OWL::Keyboard::Key::T] = 0x54;
		m_KeyMap[OWL::Keyboard::Key::Y] = 0x59;
		m_KeyMap[OWL::Keyboard::Key::U] = 0x55;
		m_KeyMap[OWL::Keyboard::Key::I] = 0x49;
		m_KeyMap[OWL::Keyboard::Key::O] = 0x4F;
		m_KeyMap[OWL::Keyboard::Key::P] = 0x50;
		m_KeyMap[OWL::Keyboard::Key::A] = 0x41;
		m_KeyMap[OWL::Keyboard::Key::S] = 0x53;
		m_KeyMap[OWL::Keyboard::Key::D] = 0x44;
		m_KeyMap[OWL::Keyboard::Key::F] = 0x46;
		m_KeyMap[OWL::Keyboard::Key::G] = 0x47;
		m_KeyMap[OWL::Keyboard::Key::H] = 0x48;
		m_KeyMap[OWL::Keyboard::Key::J] = 0x4A;
		m_KeyMap[OWL::Keyboard::Key::K] = 0x4B;
		m_KeyMap[OWL::Keyboard::Key::L] = 0x4C;
		m_KeyMap[OWL::Keyboard::Key::Z] = 0x5A;
		m_KeyMap[OWL::Keyboard::Key::X] = 0x58;
		m_KeyMap[OWL::Keyboard::Key::C] = 0x43;
		m_KeyMap[OWL::Keyboard::Key::V] = 0x56;
		m_KeyMap[OWL::Keyboard::Key::B] = 0x42;
		m_KeyMap[OWL::Keyboard::Key::N] = 0x4E;
		m_KeyMap[OWL::Keyboard::Key::M] = 0x4D;
		m_KeyMap[OWL::Keyboard::Key::Comma] = VK_OEM_COMMA;
		m_KeyMap[OWL::Keyboard::Key::Period] = VK_OEM_PERIOD;
		m_KeyMap[OWL::Keyboard::Key::Slash] = VK_OEM_2;
		m_KeyMap[OWL::Keyboard::Key::SlashBack] = VK_OEM_5;
		m_KeyMap[OWL::Keyboard::Key::Semicolon] = VK_OEM_1;
		m_KeyMap[OWL::Keyboard::Key::BracketOpen] = VK_OEM_4;
		m_KeyMap[OWL::Keyboard::Key::BracketClose] = VK_OEM_6;
		m_KeyMap[OWL::Keyboard::Key::Minus] = VK_OEM_MINUS;
		m_KeyMap[OWL::Keyboard::Key::Equals] = VK_OEM_PLUS;
		m_KeyMap[OWL::Keyboard::Key::Super] = VK_LWIN;
		m_KeyMap[OWL::Keyboard::Key::Menu] = VK_MENU;
		m_KeyMap[OWL::Keyboard::Key::F1] = VK_F1;
		m_KeyMap[OWL::Keyboard::Key::F2] = VK_F2;
		m_KeyMap[OWL::Keyboard::Key::F3] = VK_F3;
		m_KeyMap[OWL::Keyboard::Key::F4] = VK_F4;
		m_KeyMap[OWL::Keyboard::Key::F5] = VK_F5;
		m_KeyMap[OWL::Keyboard::Key::F6] = VK_F6;
		m_KeyMap[OWL::Keyboard::Key::F7] = VK_F7;
		m_KeyMap[OWL::Keyboard::Key::F8] = VK_F8;
		m_KeyMap[OWL::Keyboard::Key::F9] = VK_F9;
		m_KeyMap[OWL::Keyboard::Key::F10] = VK_F10;
		m_KeyMap[OWL::Keyboard::Key::F11] = VK_F11;
		m_KeyMap[OWL::Keyboard::Key::F12] = VK_F12;
		m_KeyMap[OWL::Keyboard::Key::NumLock] = VK_NUMLOCK;
		m_KeyMap[OWL::Keyboard::Key::NumPadMultiply] = VK_MULTIPLY;
		m_KeyMap[OWL::Keyboard::Key::NumPadDivide] = VK_DIVIDE;
		m_KeyMap[OWL::Keyboard::Key::NumPadMinus] = VK_SUBTRACT;
		m_KeyMap[OWL::Keyboard::Key::NumPadPlus] = VK_ADD;
		m_KeyMap[OWL::Keyboard::Key::NumPadDelete] = VK_SEPARATOR;
		m_KeyMap[OWL::Keyboard::Key::ArrowUp] = VK_UP;
		m_KeyMap[OWL::Keyboard::Key::ArrowDown] = VK_DOWN;
		m_KeyMap[OWL::Keyboard::Key::ArrowLeft] = VK_LEFT;
		m_KeyMap[OWL::Keyboard::Key::ArrowRight] = VK_RIGHT;
		m_KeyMap[OWL::Keyboard::Key::PrintScreen] = VK_SNAPSHOT;
		m_KeyMap[OWL::Keyboard::Key::ScrollLock] = VK_SCROLL;
		m_KeyMap[OWL::Keyboard::Key::Pause] = VK_PAUSE;
		m_KeyMap[OWL::Keyboard::Key::Insert] = VK_INSERT;
		m_KeyMap[OWL::Keyboard::Key::Home] = VK_HOME;
		m_KeyMap[OWL::Keyboard::Key::PageUp] = VK_PRIOR;
		m_KeyMap[OWL::Keyboard::Key::Delete] = VK_DELETE;
		m_KeyMap[OWL::Keyboard::Key::End] = VK_END;
		m_KeyMap[OWL::Keyboard::Key::PageDown] = VK_NEXT;
		m_KeyMap[OWL::Keyboard::Key::BackQuote] = VK_OEM_3;
	}
	virtual ~WinAPIKeyboard() {

	}

	virtual bool IsKeyPressed(unsigned int _key) const {
		return GetKeyState(m_KeyMap[_key]) & 0xFFFF0000;
	}

};
}
}