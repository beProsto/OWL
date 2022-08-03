#pragma once

#include "../keyboard.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Windows.hpp>

namespace OWL {
namespace Impl {
class OWL_API WinAPIKeyboard: public Keyboard {
public:
	WinAPIKeyboard() {
		m_keyMap[OWL::keyboard::Key::ShiftLeft] = VK_LSHIFT;
		m_keyMap[OWL::keyboard::Key::ShiftRight] = VK_RSHIFT;
		m_keyMap[OWL::keyboard::Key::CtrlLeft] = VK_LCONTROL;
		m_keyMap[OWL::keyboard::Key::CtrlRight] = VK_RCONTROL;
		m_keyMap[OWL::keyboard::Key::Enter] = VK_RETURN;
		m_keyMap[OWL::keyboard::Key::CapsLock] = VK_CAPITAL;
		m_keyMap[OWL::keyboard::Key::Tab] = VK_TAB;
		m_keyMap[OWL::keyboard::Key::Apostrophe] = VK_OEM_7;
		m_keyMap[OWL::keyboard::Key::Escape] = VK_ESCAPE;
		m_keyMap[OWL::keyboard::Key::AltLeft] = VK_LMENU;
		m_keyMap[OWL::keyboard::Key::AltRight] = VK_RMENU;
		m_keyMap[OWL::keyboard::Key::Backspace] = VK_BACK;
		m_keyMap[OWL::keyboard::Key::Space] = VK_SPACE;
		m_keyMap[OWL::keyboard::Key::Num1] = 0x31;
		m_keyMap[OWL::keyboard::Key::Num2] = 0x32;
		m_keyMap[OWL::keyboard::Key::Num3] = 0x33;
		m_keyMap[OWL::keyboard::Key::Num4] = 0x34;
		m_keyMap[OWL::keyboard::Key::Num5] = 0x35;
		m_keyMap[OWL::keyboard::Key::Num6] = 0x36;
		m_keyMap[OWL::keyboard::Key::Num7] = 0x37;
		m_keyMap[OWL::keyboard::Key::Num8] = 0x38;
		m_keyMap[OWL::keyboard::Key::Num9] = 0x39;
		m_keyMap[OWL::keyboard::Key::Num0] = 0x30;
		m_keyMap[OWL::keyboard::Key::NumPad1] = VK_NUMPAD1;
		m_keyMap[OWL::keyboard::Key::NumPad2] = VK_NUMPAD2;
		m_keyMap[OWL::keyboard::Key::NumPad3] = VK_NUMPAD3;
		m_keyMap[OWL::keyboard::Key::NumPad4] = VK_NUMPAD4;
		m_keyMap[OWL::keyboard::Key::NumPad5] = VK_NUMPAD5;
		m_keyMap[OWL::keyboard::Key::NumPad6] = VK_NUMPAD6;
		m_keyMap[OWL::keyboard::Key::NumPad7] = VK_NUMPAD7;
		m_keyMap[OWL::keyboard::Key::NumPad8] = VK_NUMPAD8;
		m_keyMap[OWL::keyboard::Key::NumPad9] = VK_NUMPAD9;
		m_keyMap[OWL::keyboard::Key::NumPad0] = VK_NUMPAD0;
		m_keyMap[OWL::keyboard::Key::Q] = 0x51;
		m_keyMap[OWL::keyboard::Key::W] = 0x57;
		m_keyMap[OWL::keyboard::Key::E] = 0x45;
		m_keyMap[OWL::keyboard::Key::R] = 0x52;
		m_keyMap[OWL::keyboard::Key::T] = 0x54;
		m_keyMap[OWL::keyboard::Key::Y] = 0x59;
		m_keyMap[OWL::keyboard::Key::U] = 0x55;
		m_keyMap[OWL::keyboard::Key::I] = 0x49;
		m_keyMap[OWL::keyboard::Key::O] = 0x4F;
		m_keyMap[OWL::keyboard::Key::P] = 0x50;
		m_keyMap[OWL::keyboard::Key::A] = 0x41;
		m_keyMap[OWL::keyboard::Key::S] = 0x53;
		m_keyMap[OWL::keyboard::Key::D] = 0x44;
		m_keyMap[OWL::keyboard::Key::F] = 0x46;
		m_keyMap[OWL::keyboard::Key::G] = 0x47;
		m_keyMap[OWL::keyboard::Key::H] = 0x48;
		m_keyMap[OWL::keyboard::Key::J] = 0x4A;
		m_keyMap[OWL::keyboard::Key::K] = 0x4B;
		m_keyMap[OWL::keyboard::Key::L] = 0x4C;
		m_keyMap[OWL::keyboard::Key::Z] = 0x5A;
		m_keyMap[OWL::keyboard::Key::X] = 0x58;
		m_keyMap[OWL::keyboard::Key::C] = 0x43;
		m_keyMap[OWL::keyboard::Key::V] = 0x56;
		m_keyMap[OWL::keyboard::Key::B] = 0x42;
		m_keyMap[OWL::keyboard::Key::N] = 0x4E;
		m_keyMap[OWL::keyboard::Key::M] = 0x4D;
		m_keyMap[OWL::keyboard::Key::Comma] = VK_OEM_COMMA;
		m_keyMap[OWL::keyboard::Key::Period] = VK_OEM_PERIOD;
		m_keyMap[OWL::keyboard::Key::Slash] = VK_OEM_2;
		m_keyMap[OWL::keyboard::Key::SlashBack] = VK_OEM_5;
		m_keyMap[OWL::keyboard::Key::Semicolon] = VK_OEM_1;
		m_keyMap[OWL::keyboard::Key::BracketOpen] = VK_OEM_4;
		m_keyMap[OWL::keyboard::Key::BracketClose] = VK_OEM_6;
		m_keyMap[OWL::keyboard::Key::Minus] = VK_OEM_MINUS;
		m_keyMap[OWL::keyboard::Key::Equals] = VK_OEM_PLUS;
		m_keyMap[OWL::keyboard::Key::Super] = VK_LWIN;
		m_keyMap[OWL::keyboard::Key::Menu] = VK_MENU;
		m_keyMap[OWL::keyboard::Key::F1] = VK_F1;
		m_keyMap[OWL::keyboard::Key::F2] = VK_F2;
		m_keyMap[OWL::keyboard::Key::F3] = VK_F3;
		m_keyMap[OWL::keyboard::Key::F4] = VK_F4;
		m_keyMap[OWL::keyboard::Key::F5] = VK_F5;
		m_keyMap[OWL::keyboard::Key::F6] = VK_F6;
		m_keyMap[OWL::keyboard::Key::F7] = VK_F7;
		m_keyMap[OWL::keyboard::Key::F8] = VK_F8;
		m_keyMap[OWL::keyboard::Key::F9] = VK_F9;
		m_keyMap[OWL::keyboard::Key::F10] = VK_F10;
		m_keyMap[OWL::keyboard::Key::F11] = VK_F11;
		m_keyMap[OWL::keyboard::Key::F12] = VK_F12;
		m_keyMap[OWL::keyboard::Key::NumLock] = VK_NUMLOCK;
		m_keyMap[OWL::keyboard::Key::NumPadMultiply] = VK_MULTIPLY;
		m_keyMap[OWL::keyboard::Key::NumPadDivide] = VK_DIVIDE;
		m_keyMap[OWL::keyboard::Key::NumPadMinus] = VK_SUBTRACT;
		m_keyMap[OWL::keyboard::Key::NumPadPlus] = VK_ADD;
		m_keyMap[OWL::keyboard::Key::NumPadDelete] = VK_SEPARATOR;
		m_keyMap[OWL::keyboard::Key::ArrowUp] = VK_UP;
		m_keyMap[OWL::keyboard::Key::ArrowDown] = VK_DOWN;
		m_keyMap[OWL::keyboard::Key::ArrowLeft] = VK_LEFT;
		m_keyMap[OWL::keyboard::Key::ArrowRight] = VK_RIGHT;
		m_keyMap[OWL::keyboard::Key::PrintScreen] = VK_SNAPSHOT;
		m_keyMap[OWL::keyboard::Key::ScrollLock] = VK_SCROLL;
		m_keyMap[OWL::keyboard::Key::Pause] = VK_PAUSE;
		m_keyMap[OWL::keyboard::Key::Insert] = VK_INSERT;
		m_keyMap[OWL::keyboard::Key::Home] = VK_HOME;
		m_keyMap[OWL::keyboard::Key::PageUp] = VK_PRIOR;
		m_keyMap[OWL::keyboard::Key::Delete] = VK_DELETE;
		m_keyMap[OWL::keyboard::Key::end] = VK_END;
		m_keyMap[OWL::keyboard::Key::PageDown] = VK_NEXT;
		m_keyMap[OWL::keyboard::Key::BackQuote] = VK_OEM_3;
	}
	virtual ~WinAPIKeyboard() {

	}

	unsigned int TranslateFromVirtualKey(unsigned int _key) {
		switch(_key) {
			case VK_LSHIFT: return OWL::keyboard::Key::ShiftLeft;
			case VK_RSHIFT: return OWL::keyboard::Key::ShiftRight;
			case VK_LCONTROL: return OWL::keyboard::Key::CtrlLeft;
			case VK_RCONTROL: return OWL::keyboard::Key::CtrlRight;
			case VK_RETURN: return OWL::keyboard::Key::Enter;
			case VK_CAPITAL: return OWL::keyboard::Key::CapsLock;
			case VK_TAB: return OWL::keyboard::Key::Tab;
			case VK_OEM_7: return OWL::keyboard::Key::Apostrophe;
			case VK_ESCAPE: return OWL::keyboard::Key::Escape;
			case VK_LMENU: return OWL::keyboard::Key::AltLeft;
			case VK_RMENU: return OWL::keyboard::Key::AltRight;
			case VK_BACK: return OWL::keyboard::Key::Backspace;
			case VK_SPACE: return OWL::keyboard::Key::Space;
			case 0x31: return OWL::keyboard::Key::Num1;
			case 0x32: return OWL::keyboard::Key::Num2;
			case 0x33: return OWL::keyboard::Key::Num3;
			case 0x34: return OWL::keyboard::Key::Num4;
			case 0x35: return OWL::keyboard::Key::Num5;
			case 0x36: return OWL::keyboard::Key::Num6;
			case 0x37: return OWL::keyboard::Key::Num7;
			case 0x38: return OWL::keyboard::Key::Num8;
			case 0x39: return OWL::keyboard::Key::Num9;
			case 0x30: return OWL::keyboard::Key::Num0;
			case VK_NUMPAD1: return OWL::keyboard::Key::NumPad1;
			case VK_NUMPAD2: return OWL::keyboard::Key::NumPad2;
			case VK_NUMPAD3: return OWL::keyboard::Key::NumPad3;
			case VK_NUMPAD4: return OWL::keyboard::Key::NumPad4;
			case VK_NUMPAD5: return OWL::keyboard::Key::NumPad5;
			case VK_NUMPAD6: return OWL::keyboard::Key::NumPad6;
			case VK_NUMPAD7: return OWL::keyboard::Key::NumPad7;
			case VK_NUMPAD8: return OWL::keyboard::Key::NumPad8;
			case VK_NUMPAD9: return OWL::keyboard::Key::NumPad9;
			case VK_NUMPAD0: return OWL::keyboard::Key::NumPad0;
			case 0x51: return OWL::keyboard::Key::Q;
			case 0x57: return OWL::keyboard::Key::W;
			case 0x45: return OWL::keyboard::Key::E;
			case 0x52: return OWL::keyboard::Key::R;
			case 0x54: return OWL::keyboard::Key::T;
			case 0x59: return OWL::keyboard::Key::Y;
			case 0x55: return OWL::keyboard::Key::U;
			case 0x49: return OWL::keyboard::Key::I;
			case 0x4F: return OWL::keyboard::Key::O;
			case 0x50: return OWL::keyboard::Key::P;
			case 0x41: return OWL::keyboard::Key::A;
			case 0x53: return OWL::keyboard::Key::S;
			case 0x44: return OWL::keyboard::Key::D;
			case 0x46: return OWL::keyboard::Key::F;
			case 0x47: return OWL::keyboard::Key::G;
			case 0x48: return OWL::keyboard::Key::H;
			case 0x4A: return OWL::keyboard::Key::J;
			case 0x4B: return OWL::keyboard::Key::K;
			case 0x4C: return OWL::keyboard::Key::L;
			case 0x5A: return OWL::keyboard::Key::Z;
			case 0x58: return OWL::keyboard::Key::X;
			case 0x43: return OWL::keyboard::Key::C;
			case 0x56: return OWL::keyboard::Key::V;
			case 0x42: return OWL::keyboard::Key::B;
			case 0x4E: return OWL::keyboard::Key::N;
			case 0x4D: return OWL::keyboard::Key::M;
			case VK_OEM_COMMA: return OWL::keyboard::Key::Comma;
			case VK_OEM_PERIOD: return OWL::keyboard::Key::Period;
			case VK_OEM_2: return OWL::keyboard::Key::Slash;
			case VK_OEM_5: return OWL::keyboard::Key::SlashBack;
			case VK_OEM_1: return OWL::keyboard::Key::Semicolon;
			case VK_OEM_4: return OWL::keyboard::Key::BracketOpen;
			case VK_OEM_6: return OWL::keyboard::Key::BracketClose;
			case VK_OEM_MINUS: return OWL::keyboard::Key::Minus;
			case VK_OEM_PLUS: return OWL::keyboard::Key::Equals;
			case VK_LWIN: return OWL::keyboard::Key::Super;
			case VK_MENU: return OWL::keyboard::Key::Menu;
			case VK_F1: return OWL::keyboard::Key::F1;
			case VK_F2: return OWL::keyboard::Key::F2;
			case VK_F3: return OWL::keyboard::Key::F3;
			case VK_F4: return OWL::keyboard::Key::F4;
			case VK_F5: return OWL::keyboard::Key::F5;
			case VK_F6: return OWL::keyboard::Key::F6;
			case VK_F7: return OWL::keyboard::Key::F7;
			case VK_F8: return OWL::keyboard::Key::F8;
			case VK_F9: return OWL::keyboard::Key::F9;
			case VK_F10: return OWL::keyboard::Key::F10;
			case VK_F11: return OWL::keyboard::Key::F11;
			case VK_F12: return OWL::keyboard::Key::F12;
			case VK_NUMLOCK: return OWL::keyboard::Key::NumLock;
			case VK_MULTIPLY: return OWL::keyboard::Key::NumPadMultiply;
			case VK_DIVIDE: return OWL::keyboard::Key::NumPadDivide;
			case VK_SUBTRACT: return OWL::keyboard::Key::NumPadMinus;
			case VK_ADD: return OWL::keyboard::Key::NumPadPlus;
			case VK_SEPARATOR: return OWL::keyboard::Key::NumPadDelete;
			case VK_UP: return OWL::keyboard::Key::ArrowUp;
			case VK_DOWN: return OWL::keyboard::Key::ArrowDown;
			case VK_LEFT: return OWL::keyboard::Key::ArrowLeft;
			case VK_RIGHT: return OWL::keyboard::Key::ArrowRight;
			case VK_SNAPSHOT: return OWL::keyboard::Key::PrintScreen;
			case VK_SCROLL: return OWL::keyboard::Key::ScrollLock;
			case VK_PAUSE: return OWL::keyboard::Key::Pause;
			case VK_INSERT: return OWL::keyboard::Key::Insert;
			case VK_HOME: return OWL::keyboard::Key::Home;
			case VK_PRIOR: return OWL::keyboard::Key::PageUp;
			case VK_DELETE: return OWL::keyboard::Key::Delete;
			case VK_END: return OWL::keyboard::Key::end;
			case VK_NEXT: return OWL::keyboard::Key::PageDown;
			case VK_OEM_3: return OWL::keyboard::Key::BackQuote;
			default: return OWL::keyboard::None;
		}
	}

	virtual bool IsKeyPressed(unsigned int _key) const {
		return GetKeyState(m_keyMap[_key]) & 0xFFFF0000;
	}

public:
	virtual void pollPreparation() {
		m_keyData.Char = '\0';
		m_keyData.Enum = OWL::keyboard::None;
	}
	virtual void pollSpecificEvents() {
		if(static_cast<WinAPIWindow*>(m_windowImpl)->m_Event.message == WM_KEYDOWN) {
			m_keyData.Enum = TranslateFromVirtualKey(static_cast<WinAPIWindow*>(m_windowImpl)->m_Event.wParam);
		}
		else if(static_cast<WinAPIWindow*>(m_windowImpl)->m_Event.message == WM_CHAR) {
			m_keyData.Char = static_cast<WinAPIWindow*>(m_windowImpl)->m_Event.wParam;
		}
	}

};
}
}