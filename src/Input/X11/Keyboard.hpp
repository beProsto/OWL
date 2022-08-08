#pragma once

#include "../Keyboard.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Windows.hpp>

namespace OWL {
namespace Impl {
class OWL_API X11Keyboard: public Keyboard {
public:
	X11Keyboard() {
	// 	m_keyMap[OWL::Keyboard::Key::ShiftLeft] = VK_LSHIFT;
	// 	m_keyMap[OWL::Keyboard::Key::ShiftRight] = VK_RSHIFT;
	// 	m_keyMap[OWL::Keyboard::Key::CtrlLeft] = VK_LCONTROL;
	// 	m_keyMap[OWL::Keyboard::Key::CtrlRight] = VK_RCONTROL;
	// 	m_keyMap[OWL::Keyboard::Key::Enter] = VK_RETURN;
	// 	m_keyMap[OWL::Keyboard::Key::CapsLock] = VK_CAPITAL;
	// 	m_keyMap[OWL::Keyboard::Key::Tab] = VK_TAB;
	// 	m_keyMap[OWL::Keyboard::Key::Apostrophe] = VK_OEM_7;
	// 	m_keyMap[OWL::Keyboard::Key::Escape] = VK_ESCAPE;
	// 	m_keyMap[OWL::Keyboard::Key::AltLeft] = VK_LMENU;
	// 	m_keyMap[OWL::Keyboard::Key::AltRight] = VK_RMENU;
	// 	m_keyMap[OWL::Keyboard::Key::Backspace] = VK_BACK;
	// 	m_keyMap[OWL::Keyboard::Key::Space] = VK_SPACE;
	// 	m_keyMap[OWL::Keyboard::Key::Num1] = 0x31;
	// 	m_keyMap[OWL::Keyboard::Key::Num2] = 0x32;
	// 	m_keyMap[OWL::Keyboard::Key::Num3] = 0x33;
	// 	m_keyMap[OWL::Keyboard::Key::Num4] = 0x34;
	// 	m_keyMap[OWL::Keyboard::Key::Num5] = 0x35;
	// 	m_keyMap[OWL::Keyboard::Key::Num6] = 0x36;
	// 	m_keyMap[OWL::Keyboard::Key::Num7] = 0x37;
	// 	m_keyMap[OWL::Keyboard::Key::Num8] = 0x38;
	// 	m_keyMap[OWL::Keyboard::Key::Num9] = 0x39;
	// 	m_keyMap[OWL::Keyboard::Key::Num0] = 0x30;
	// 	m_keyMap[OWL::Keyboard::Key::NumPad1] = VK_NUMPAD1;
	// 	m_keyMap[OWL::Keyboard::Key::NumPad2] = VK_NUMPAD2;
	// 	m_keyMap[OWL::Keyboard::Key::NumPad3] = VK_NUMPAD3;
	// 	m_keyMap[OWL::Keyboard::Key::NumPad4] = VK_NUMPAD4;
	// 	m_keyMap[OWL::Keyboard::Key::NumPad5] = VK_NUMPAD5;
	// 	m_keyMap[OWL::Keyboard::Key::NumPad6] = VK_NUMPAD6;
	// 	m_keyMap[OWL::Keyboard::Key::NumPad7] = VK_NUMPAD7;
	// 	m_keyMap[OWL::Keyboard::Key::NumPad8] = VK_NUMPAD8;
	// 	m_keyMap[OWL::Keyboard::Key::NumPad9] = VK_NUMPAD9;
	// 	m_keyMap[OWL::Keyboard::Key::NumPad0] = VK_NUMPAD0;
	// 	m_keyMap[OWL::Keyboard::Key::Q] = 0x51;
	// 	m_keyMap[OWL::Keyboard::Key::W] = 0x57;
	// 	m_keyMap[OWL::Keyboard::Key::E] = 0x45;
	// 	m_keyMap[OWL::Keyboard::Key::R] = 0x52;
	// 	m_keyMap[OWL::Keyboard::Key::T] = 0x54;
	// 	m_keyMap[OWL::Keyboard::Key::Y] = 0x59;
	// 	m_keyMap[OWL::Keyboard::Key::U] = 0x55;
	// 	m_keyMap[OWL::Keyboard::Key::I] = 0x49;
	// 	m_keyMap[OWL::Keyboard::Key::O] = 0x4F;
	// 	m_keyMap[OWL::Keyboard::Key::P] = 0x50;
	// 	m_keyMap[OWL::Keyboard::Key::A] = 0x41;
	// 	m_keyMap[OWL::Keyboard::Key::S] = 0x53;
	// 	m_keyMap[OWL::Keyboard::Key::D] = 0x44;
	// 	m_keyMap[OWL::Keyboard::Key::F] = 0x46;
	// 	m_keyMap[OWL::Keyboard::Key::G] = 0x47;
	// 	m_keyMap[OWL::Keyboard::Key::H] = 0x48;
	// 	m_keyMap[OWL::Keyboard::Key::J] = 0x4A;
	// 	m_keyMap[OWL::Keyboard::Key::K] = 0x4B;
	// 	m_keyMap[OWL::Keyboard::Key::L] = 0x4C;
	// 	m_keyMap[OWL::Keyboard::Key::Z] = 0x5A;
	// 	m_keyMap[OWL::Keyboard::Key::X] = 0x58;
	// 	m_keyMap[OWL::Keyboard::Key::C] = 0x43;
	// 	m_keyMap[OWL::Keyboard::Key::V] = 0x56;
	// 	m_keyMap[OWL::Keyboard::Key::B] = 0x42;
	// 	m_keyMap[OWL::Keyboard::Key::N] = 0x4E;
	// 	m_keyMap[OWL::Keyboard::Key::M] = 0x4D;
	// 	m_keyMap[OWL::Keyboard::Key::Comma] = VK_OEM_COMMA;
	// 	m_keyMap[OWL::Keyboard::Key::Period] = VK_OEM_PERIOD;
	// 	m_keyMap[OWL::Keyboard::Key::Slash] = VK_OEM_2;
	// 	m_keyMap[OWL::Keyboard::Key::SlashBack] = VK_OEM_5;
	// 	m_keyMap[OWL::Keyboard::Key::Semicolon] = VK_OEM_1;
	// 	m_keyMap[OWL::Keyboard::Key::BracketOpen] = VK_OEM_4;
	// 	m_keyMap[OWL::Keyboard::Key::BracketClose] = VK_OEM_6;
	// 	m_keyMap[OWL::Keyboard::Key::Minus] = VK_OEM_MINUS;
	// 	m_keyMap[OWL::Keyboard::Key::Equals] = VK_OEM_PLUS;
	// 	m_keyMap[OWL::Keyboard::Key::Super] = VK_LWIN;
	// 	m_keyMap[OWL::Keyboard::Key::Menu] = VK_MENU;
	// 	m_keyMap[OWL::Keyboard::Key::F1] = VK_F1;
	// 	m_keyMap[OWL::Keyboard::Key::F2] = VK_F2;
	// 	m_keyMap[OWL::Keyboard::Key::F3] = VK_F3;
	// 	m_keyMap[OWL::Keyboard::Key::F4] = VK_F4;
	// 	m_keyMap[OWL::Keyboard::Key::F5] = VK_F5;
	// 	m_keyMap[OWL::Keyboard::Key::F6] = VK_F6;
	// 	m_keyMap[OWL::Keyboard::Key::F7] = VK_F7;
	// 	m_keyMap[OWL::Keyboard::Key::F8] = VK_F8;
	// 	m_keyMap[OWL::Keyboard::Key::F9] = VK_F9;
	// 	m_keyMap[OWL::Keyboard::Key::F10] = VK_F10;
	// 	m_keyMap[OWL::Keyboard::Key::F11] = VK_F11;
	// 	m_keyMap[OWL::Keyboard::Key::F12] = VK_F12;
	// 	m_keyMap[OWL::Keyboard::Key::NumLock] = VK_NUMLOCK;
	// 	m_keyMap[OWL::Keyboard::Key::NumPadMultiply] = VK_MULTIPLY;
	// 	m_keyMap[OWL::Keyboard::Key::NumPadDivide] = VK_DIVIDE;
	// 	m_keyMap[OWL::Keyboard::Key::NumPadMinus] = VK_SUBTRACT;
	// 	m_keyMap[OWL::Keyboard::Key::NumPadPlus] = VK_ADD;
	// 	m_keyMap[OWL::Keyboard::Key::NumPadDelete] = VK_SEPARATOR;
	// 	m_keyMap[OWL::Keyboard::Key::ArrowUp] = VK_UP;
	// 	m_keyMap[OWL::Keyboard::Key::ArrowDown] = VK_DOWN;
	// 	m_keyMap[OWL::Keyboard::Key::ArrowLeft] = VK_LEFT;
	// 	m_keyMap[OWL::Keyboard::Key::ArrowRight] = VK_RIGHT;
	// 	m_keyMap[OWL::Keyboard::Key::PrintScreen] = VK_SNAPSHOT;
	// 	m_keyMap[OWL::Keyboard::Key::ScrollLock] = VK_SCROLL;
	// 	m_keyMap[OWL::Keyboard::Key::Pause] = VK_PAUSE;
	// 	m_keyMap[OWL::Keyboard::Key::Insert] = VK_INSERT;
	// 	m_keyMap[OWL::Keyboard::Key::Home] = VK_HOME;
	// 	m_keyMap[OWL::Keyboard::Key::PageUp] = VK_PRIOR;
	// 	m_keyMap[OWL::Keyboard::Key::Delete] = VK_DELETE;
	// 	m_keyMap[OWL::Keyboard::Key::End] = VK_END;
	// 	m_keyMap[OWL::Keyboard::Key::PageDown] = VK_NEXT;
	// 	m_keyMap[OWL::Keyboard::Key::BackQuote] = VK_OEM_3;
	}
	virtual ~X11Keyboard() {

	}

	unsigned int translateFromVirtualKey(unsigned int _key) {
		switch(_key) {
			// case VK_LSHIFT: return OWL::Keyboard::Key::ShiftLeft;
			// case VK_RSHIFT: return OWL::Keyboard::Key::ShiftRight;
	// 		case VK_LCONTROL: return OWL::Keyboard::Key::CtrlLeft;
	// 		case VK_RCONTROL: return OWL::Keyboard::Key::CtrlRight;
	// 		case VK_RETURN: return OWL::Keyboard::Key::Enter;
	// 		case VK_CAPITAL: return OWL::Keyboard::Key::CapsLock;
	// 		case VK_TAB: return OWL::Keyboard::Key::Tab;
	// 		case VK_OEM_7: return OWL::Keyboard::Key::Apostrophe;
	// 		case VK_ESCAPE: return OWL::Keyboard::Key::Escape;
	// 		case VK_LMENU: return OWL::Keyboard::Key::AltLeft;
	// 		case VK_RMENU: return OWL::Keyboard::Key::AltRight;
	// 		case VK_BACK: return OWL::Keyboard::Key::Backspace;
	// 		case VK_SPACE: return OWL::Keyboard::Key::Space;
	// 		case 0x31: return OWL::Keyboard::Key::Num1;
	// 		case 0x32: return OWL::Keyboard::Key::Num2;
	// 		case 0x33: return OWL::Keyboard::Key::Num3;
	// 		case 0x34: return OWL::Keyboard::Key::Num4;
	// 		case 0x35: return OWL::Keyboard::Key::Num5;
	// 		case 0x36: return OWL::Keyboard::Key::Num6;
	// 		case 0x37: return OWL::Keyboard::Key::Num7;
	// 		case 0x38: return OWL::Keyboard::Key::Num8;
	// 		case 0x39: return OWL::Keyboard::Key::Num9;
	// 		case 0x30: return OWL::Keyboard::Key::Num0;
	// 		case VK_NUMPAD1: return OWL::Keyboard::Key::NumPad1;
	// 		case VK_NUMPAD2: return OWL::Keyboard::Key::NumPad2;
	// 		case VK_NUMPAD3: return OWL::Keyboard::Key::NumPad3;
	// 		case VK_NUMPAD4: return OWL::Keyboard::Key::NumPad4;
	// 		case VK_NUMPAD5: return OWL::Keyboard::Key::NumPad5;
	// 		case VK_NUMPAD6: return OWL::Keyboard::Key::NumPad6;
	// 		case VK_NUMPAD7: return OWL::Keyboard::Key::NumPad7;
	// 		case VK_NUMPAD8: return OWL::Keyboard::Key::NumPad8;
	// 		case VK_NUMPAD9: return OWL::Keyboard::Key::NumPad9;
	// 		case VK_NUMPAD0: return OWL::Keyboard::Key::NumPad0;
	// 		case 0x51: return OWL::Keyboard::Key::Q;
	// 		case 0x57: return OWL::Keyboard::Key::W;
	// 		case 0x45: return OWL::Keyboard::Key::E;
	// 		case 0x52: return OWL::Keyboard::Key::R;
	// 		case 0x54: return OWL::Keyboard::Key::T;
	// 		case 0x59: return OWL::Keyboard::Key::Y;
	// 		case 0x55: return OWL::Keyboard::Key::U;
	// 		case 0x49: return OWL::Keyboard::Key::I;
	// 		case 0x4F: return OWL::Keyboard::Key::O;
	// 		case 0x50: return OWL::Keyboard::Key::P;
	// 		case 0x41: return OWL::Keyboard::Key::A;
	// 		case 0x53: return OWL::Keyboard::Key::S;
	// 		case 0x44: return OWL::Keyboard::Key::D;
	// 		case 0x46: return OWL::Keyboard::Key::F;
	// 		case 0x47: return OWL::Keyboard::Key::G;
	// 		case 0x48: return OWL::Keyboard::Key::H;
	// 		case 0x4A: return OWL::Keyboard::Key::J;
	// 		case 0x4B: return OWL::Keyboard::Key::K;
	// 		case 0x4C: return OWL::Keyboard::Key::L;
	// 		case 0x5A: return OWL::Keyboard::Key::Z;
	// 		case 0x58: return OWL::Keyboard::Key::X;
	// 		case 0x43: return OWL::Keyboard::Key::C;
	// 		case 0x56: return OWL::Keyboard::Key::V;
	// 		case 0x42: return OWL::Keyboard::Key::B;
	// 		case 0x4E: return OWL::Keyboard::Key::N;
	// 		case 0x4D: return OWL::Keyboard::Key::M;
	// 		case VK_OEM_COMMA: return OWL::Keyboard::Key::Comma;
	// 		case VK_OEM_PERIOD: return OWL::Keyboard::Key::Period;
	// 		case VK_OEM_2: return OWL::Keyboard::Key::Slash;
	// 		case VK_OEM_5: return OWL::Keyboard::Key::SlashBack;
	// 		case VK_OEM_1: return OWL::Keyboard::Key::Semicolon;
	// 		case VK_OEM_4: return OWL::Keyboard::Key::BracketOpen;
	// 		case VK_OEM_6: return OWL::Keyboard::Key::BracketClose;
	// 		case VK_OEM_MINUS: return OWL::Keyboard::Key::Minus;
	// 		case VK_OEM_PLUS: return OWL::Keyboard::Key::Equals;
	// 		case VK_LWIN: return OWL::Keyboard::Key::Super;
	// 		case VK_MENU: return OWL::Keyboard::Key::Menu;
	// 		case VK_F1: return OWL::Keyboard::Key::F1;
	// 		case VK_F2: return OWL::Keyboard::Key::F2;
	// 		case VK_F3: return OWL::Keyboard::Key::F3;
	// 		case VK_F4: return OWL::Keyboard::Key::F4;
	// 		case VK_F5: return OWL::Keyboard::Key::F5;
	// 		case VK_F6: return OWL::Keyboard::Key::F6;
	// 		case VK_F7: return OWL::Keyboard::Key::F7;
	// 		case VK_F8: return OWL::Keyboard::Key::F8;
	// 		case VK_F9: return OWL::Keyboard::Key::F9;
	// 		case VK_F10: return OWL::Keyboard::Key::F10;
	// 		case VK_F11: return OWL::Keyboard::Key::F11;
	// 		case VK_F12: return OWL::Keyboard::Key::F12;
	// 		case VK_NUMLOCK: return OWL::Keyboard::Key::NumLock;
	// 		case VK_MULTIPLY: return OWL::Keyboard::Key::NumPadMultiply;
	// 		case VK_DIVIDE: return OWL::Keyboard::Key::NumPadDivide;
	// 		case VK_SUBTRACT: return OWL::Keyboard::Key::NumPadMinus;
	// 		case VK_ADD: return OWL::Keyboard::Key::NumPadPlus;
	// 		case VK_SEPARATOR: return OWL::Keyboard::Key::NumPadDelete;
	// 		case VK_UP: return OWL::Keyboard::Key::ArrowUp;
	// 		case VK_DOWN: return OWL::Keyboard::Key::ArrowDown;
	// 		case VK_LEFT: return OWL::Keyboard::Key::ArrowLeft;
	// 		case VK_RIGHT: return OWL::Keyboard::Key::ArrowRight;
	// 		case VK_SNAPSHOT: return OWL::Keyboard::Key::PrintScreen;
	// 		case VK_SCROLL: return OWL::Keyboard::Key::ScrollLock;
	// 		case VK_PAUSE: return OWL::Keyboard::Key::Pause;
	// 		case VK_INSERT: return OWL::Keyboard::Key::Insert;
	// 		case VK_HOME: return OWL::Keyboard::Key::Home;
	// 		case VK_PRIOR: return OWL::Keyboard::Key::PageUp;
	// 		case VK_DELETE: return OWL::Keyboard::Key::Delete;
	// 		case VK_END: return OWL::Keyboard::Key::end;
	// 		case VK_NEXT: return OWL::Keyboard::Key::PageDown;
	// 		case VK_OEM_3: return OWL::Keyboard::Key::BackQuote;
			default: return OWL::Keyboard::None;
		}
	}

	virtual bool isKeyPressed(unsigned int _key) const {
		return false;
	}

public:
	virtual void pollPreparation() {
		m_keyData.keyChar = '\0';
		m_keyData.keyEnum = OWL::Keyboard::None;
	}
	virtual void pollSpecificEvents() {

	}

};
}
}