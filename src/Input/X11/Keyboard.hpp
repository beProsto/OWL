#pragma once

#include "../Keyboard.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Linux.hpp>

namespace OWL {
namespace Impl {
#define Win(x) static_cast<X11Window*>(x)

class OWL_API X11Keyboard: public Keyboard {
public:
	X11Keyboard() {
		m_keyMap[OWL::Keyboard::Key::ShiftLeft] = XK_Shift_L;
		m_keyMap[OWL::Keyboard::Key::ShiftRight] = XK_Shift_R;
		m_keyMap[OWL::Keyboard::Key::CtrlLeft] = XK_Control_L;
		m_keyMap[OWL::Keyboard::Key::CtrlRight] = XK_Control_R;
		m_keyMap[OWL::Keyboard::Key::Enter] = XK_Return;
		m_keyMap[OWL::Keyboard::Key::CapsLock] = XK_Caps_Lock;
		m_keyMap[OWL::Keyboard::Key::Tab] = XK_Tab;
		m_keyMap[OWL::Keyboard::Key::Apostrophe] = XK_apostrophe;
		m_keyMap[OWL::Keyboard::Key::Escape] = XK_Escape;
		m_keyMap[OWL::Keyboard::Key::AltLeft] = XK_Alt_L;
		m_keyMap[OWL::Keyboard::Key::AltRight] = XK_Alt_R;
		m_keyMap[OWL::Keyboard::Key::Backspace] = XK_BackSpace;
		m_keyMap[OWL::Keyboard::Key::Space] = XK_space;
		m_keyMap[OWL::Keyboard::Key::Num1] = XK_1;
		m_keyMap[OWL::Keyboard::Key::Num2] = XK_2;
		m_keyMap[OWL::Keyboard::Key::Num3] = XK_3;
		m_keyMap[OWL::Keyboard::Key::Num4] = XK_4;
		m_keyMap[OWL::Keyboard::Key::Num5] = XK_5;
		m_keyMap[OWL::Keyboard::Key::Num6] = XK_6;
		m_keyMap[OWL::Keyboard::Key::Num7] = XK_7;
		m_keyMap[OWL::Keyboard::Key::Num8] = XK_8;
		m_keyMap[OWL::Keyboard::Key::Num9] = XK_9;
		m_keyMap[OWL::Keyboard::Key::Num0] = XK_0;
		m_keyMap[OWL::Keyboard::Key::NumPad1] = XK_KP_1;
		m_keyMap[OWL::Keyboard::Key::NumPad2] = XK_KP_2;
		m_keyMap[OWL::Keyboard::Key::NumPad3] = XK_KP_3;
		m_keyMap[OWL::Keyboard::Key::NumPad4] = XK_KP_4;
		m_keyMap[OWL::Keyboard::Key::NumPad5] = XK_KP_5;
		m_keyMap[OWL::Keyboard::Key::NumPad6] = XK_KP_6;
		m_keyMap[OWL::Keyboard::Key::NumPad7] = XK_KP_7;
		m_keyMap[OWL::Keyboard::Key::NumPad8] = XK_KP_8;
		m_keyMap[OWL::Keyboard::Key::NumPad9] = XK_KP_9;
		m_keyMap[OWL::Keyboard::Key::NumPad0] = XK_KP_0;
		m_keyMap[OWL::Keyboard::Key::Q] = XK_Q;
		m_keyMap[OWL::Keyboard::Key::W] = XK_W;
		m_keyMap[OWL::Keyboard::Key::E] = XK_E;
		m_keyMap[OWL::Keyboard::Key::R] = XK_R;
		m_keyMap[OWL::Keyboard::Key::T] = XK_T;
		m_keyMap[OWL::Keyboard::Key::Y] = XK_Y;
		m_keyMap[OWL::Keyboard::Key::U] = XK_U;
		m_keyMap[OWL::Keyboard::Key::I] = XK_I;
		m_keyMap[OWL::Keyboard::Key::O] = XK_O;
		m_keyMap[OWL::Keyboard::Key::P] = XK_P;
		m_keyMap[OWL::Keyboard::Key::A] = XK_A;
		m_keyMap[OWL::Keyboard::Key::S] = XK_S;
		m_keyMap[OWL::Keyboard::Key::D] = XK_D;
		m_keyMap[OWL::Keyboard::Key::F] = XK_F;
		m_keyMap[OWL::Keyboard::Key::G] = XK_G;
		m_keyMap[OWL::Keyboard::Key::H] = XK_H;
		m_keyMap[OWL::Keyboard::Key::J] = XK_J;
		m_keyMap[OWL::Keyboard::Key::K] = XK_K;
		m_keyMap[OWL::Keyboard::Key::L] = XK_L;
		m_keyMap[OWL::Keyboard::Key::Z] = XK_Z;
		m_keyMap[OWL::Keyboard::Key::X] = XK_X;
		m_keyMap[OWL::Keyboard::Key::C] = XK_C;
		m_keyMap[OWL::Keyboard::Key::V] = XK_V;
		m_keyMap[OWL::Keyboard::Key::B] = XK_B;
		m_keyMap[OWL::Keyboard::Key::N] = XK_N;
		m_keyMap[OWL::Keyboard::Key::M] = XK_M;
		m_keyMap[OWL::Keyboard::Key::Comma] = XK_KP_Separator;
		m_keyMap[OWL::Keyboard::Key::Period] = XK_period;
		m_keyMap[OWL::Keyboard::Key::Slash] = XK_slash;
		m_keyMap[OWL::Keyboard::Key::SlashBack] = XK_backslash;
		m_keyMap[OWL::Keyboard::Key::Semicolon] = XK_semicolon;
		m_keyMap[OWL::Keyboard::Key::BracketOpen] = XK_bracketleft;
		m_keyMap[OWL::Keyboard::Key::BracketClose] = XK_bracketright;
		m_keyMap[OWL::Keyboard::Key::Minus] = XK_minus;
		m_keyMap[OWL::Keyboard::Key::Equals] = XK_equal;
		m_keyMap[OWL::Keyboard::Key::Super] = XK_Super_L;
		m_keyMap[OWL::Keyboard::Key::Menu] = XK_Menu;
		m_keyMap[OWL::Keyboard::Key::F1] = XK_F1;
		m_keyMap[OWL::Keyboard::Key::F2] = XK_F2;
		m_keyMap[OWL::Keyboard::Key::F3] = XK_F3;
		m_keyMap[OWL::Keyboard::Key::F4] = XK_F4;
		m_keyMap[OWL::Keyboard::Key::F5] = XK_F5;
		m_keyMap[OWL::Keyboard::Key::F6] = XK_F6;
		m_keyMap[OWL::Keyboard::Key::F7] = XK_F7;
		m_keyMap[OWL::Keyboard::Key::F8] = XK_F8;
		m_keyMap[OWL::Keyboard::Key::F9] = XK_F9;
		m_keyMap[OWL::Keyboard::Key::F10] = XK_F10;
		m_keyMap[OWL::Keyboard::Key::F11] = XK_F11;
		m_keyMap[OWL::Keyboard::Key::F12] = XK_F12;
		m_keyMap[OWL::Keyboard::Key::NumLock] = XK_Num_Lock;
		m_keyMap[OWL::Keyboard::Key::NumPadMultiply] = XK_KP_Multiply;
		m_keyMap[OWL::Keyboard::Key::NumPadDivide] = XK_KP_Divide;
		m_keyMap[OWL::Keyboard::Key::NumPadMinus] = XK_KP_Subtract;
		m_keyMap[OWL::Keyboard::Key::NumPadPlus] = XK_KP_Add;
		// m_keyMap[OWL::Keyboard::Key::NumPadEnter] = XK_KP_Enter;
		m_keyMap[OWL::Keyboard::Key::NumPadDelete] = XK_KP_Delete;
		m_keyMap[OWL::Keyboard::Key::ArrowUp] = XK_Up;
		m_keyMap[OWL::Keyboard::Key::ArrowDown] = XK_Down;
		m_keyMap[OWL::Keyboard::Key::ArrowLeft] = XK_Left;
		m_keyMap[OWL::Keyboard::Key::ArrowRight] = XK_Right;
		m_keyMap[OWL::Keyboard::Key::PrintScreen] = XK_Sys_Req;
		m_keyMap[OWL::Keyboard::Key::ScrollLock] = XK_Scroll_Lock;
		m_keyMap[OWL::Keyboard::Key::Pause] = XK_Pause;
		m_keyMap[OWL::Keyboard::Key::Insert] = XK_Insert;
		m_keyMap[OWL::Keyboard::Key::Home] = XK_Home;
		m_keyMap[OWL::Keyboard::Key::PageUp] = XK_Page_Up;
		m_keyMap[OWL::Keyboard::Key::Delete] = XK_Delete;
		m_keyMap[OWL::Keyboard::Key::End] = XK_End;
		m_keyMap[OWL::Keyboard::Key::PageDown] = XK_Page_Down;
		m_keyMap[OWL::Keyboard::Key::BackQuote] = XK_quoteleft;
	}
	virtual ~X11Keyboard() {

	}

	unsigned int translateFromVirtualKey(unsigned int _key) {
		switch(_key) {
			case XK_Shift_L: return OWL::Keyboard::Key::ShiftLeft;
			case XK_Shift_R: return OWL::Keyboard::Key::ShiftRight;
			case XK_Control_L: return OWL::Keyboard::Key::CtrlLeft;
			case XK_Control_R: return OWL::Keyboard::Key::CtrlRight;
			case XK_Return: return OWL::Keyboard::Key::Enter;
			case XK_Caps_Lock: return OWL::Keyboard::Key::CapsLock;
			case XK_Tab: return OWL::Keyboard::Key::Tab;
			case XK_apostrophe: return OWL::Keyboard::Key::Apostrophe;
			case XK_Escape: return OWL::Keyboard::Key::Escape;
			case XK_Alt_L: return OWL::Keyboard::Key::AltLeft;
			case XK_Alt_R: return OWL::Keyboard::Key::AltRight;
			case XK_BackSpace: return OWL::Keyboard::Key::Backspace;
			case XK_space: return OWL::Keyboard::Key::Space;
			case XK_1: return OWL::Keyboard::Key::Num1;
			case XK_2: return OWL::Keyboard::Key::Num2;
			case XK_3: return OWL::Keyboard::Key::Num3;
			case XK_4: return OWL::Keyboard::Key::Num4;
			case XK_5: return OWL::Keyboard::Key::Num5;
			case XK_6: return OWL::Keyboard::Key::Num6;
			case XK_7: return OWL::Keyboard::Key::Num7;
			case XK_8: return OWL::Keyboard::Key::Num8;
			case XK_9: return OWL::Keyboard::Key::Num9;
			case XK_0: return OWL::Keyboard::Key::Num0;
			case XK_KP_1: return OWL::Keyboard::Key::NumPad1;
			case XK_KP_2: return OWL::Keyboard::Key::NumPad2;
			case XK_KP_3: return OWL::Keyboard::Key::NumPad3;
			case XK_KP_4: return OWL::Keyboard::Key::NumPad4;
			case XK_KP_5: return OWL::Keyboard::Key::NumPad5;
			case XK_KP_6: return OWL::Keyboard::Key::NumPad6;
			case XK_KP_7: return OWL::Keyboard::Key::NumPad7;
			case XK_KP_8: return OWL::Keyboard::Key::NumPad8;
			case XK_KP_9: return OWL::Keyboard::Key::NumPad9;
			case XK_KP_0: return OWL::Keyboard::Key::NumPad0;
			case XK_Q: return OWL::Keyboard::Key::Q;
			case XK_W: return OWL::Keyboard::Key::W;
			case XK_E: return OWL::Keyboard::Key::E;
			case XK_R: return OWL::Keyboard::Key::R;
			case XK_T: return OWL::Keyboard::Key::T;
			case XK_Y: return OWL::Keyboard::Key::Y;
			case XK_U: return OWL::Keyboard::Key::U;
			case XK_I: return OWL::Keyboard::Key::I;
			case XK_O: return OWL::Keyboard::Key::O;
			case XK_P: return OWL::Keyboard::Key::P;
			case XK_A: return OWL::Keyboard::Key::A;
			case XK_S: return OWL::Keyboard::Key::S;
			case XK_D: return OWL::Keyboard::Key::D;
			case XK_F: return OWL::Keyboard::Key::F;
			case XK_G: return OWL::Keyboard::Key::G;
			case XK_H: return OWL::Keyboard::Key::H;
			case XK_J: return OWL::Keyboard::Key::J;
			case XK_K: return OWL::Keyboard::Key::K;
			case XK_L: return OWL::Keyboard::Key::L;
			case XK_Z: return OWL::Keyboard::Key::Z;
			case XK_X: return OWL::Keyboard::Key::X;
			case XK_C: return OWL::Keyboard::Key::C;
			case XK_V: return OWL::Keyboard::Key::V;
			case XK_B: return OWL::Keyboard::Key::B;
			case XK_N: return OWL::Keyboard::Key::N;
			case XK_M: return OWL::Keyboard::Key::M;
			case XK_KP_Separator: return OWL::Keyboard::Key::Comma;
			case XK_period: return OWL::Keyboard::Key::Period;
			case XK_slash: return OWL::Keyboard::Key::Slash;
			case XK_backslash: return OWL::Keyboard::Key::SlashBack;
			case XK_semicolon: return OWL::Keyboard::Key::Semicolon;
			case XK_bracketleft: return OWL::Keyboard::Key::BracketOpen;
			case XK_bracketright: return OWL::Keyboard::Key::BracketClose;
			case XK_minus: return OWL::Keyboard::Key::Minus;
			case XK_equal: return OWL::Keyboard::Key::Equals;
			case XK_Super_L: return OWL::Keyboard::Key::Super;
			case XK_Menu: return OWL::Keyboard::Key::Menu;
			case XK_F1: return OWL::Keyboard::Key::F1;
			case XK_F2: return OWL::Keyboard::Key::F2;
			case XK_F3: return OWL::Keyboard::Key::F3;
			case XK_F4: return OWL::Keyboard::Key::F4;
			case XK_F5: return OWL::Keyboard::Key::F5;
			case XK_F6: return OWL::Keyboard::Key::F6;
			case XK_F7: return OWL::Keyboard::Key::F7;
			case XK_F8: return OWL::Keyboard::Key::F8;
			case XK_F9: return OWL::Keyboard::Key::F9;
			case XK_F10: return OWL::Keyboard::Key::F10;
			case XK_F11: return OWL::Keyboard::Key::F11;
			case XK_F12: return OWL::Keyboard::Key::F12;
			case XK_Num_Lock: return OWL::Keyboard::Key::NumLock;
			case XK_KP_Multiply: return OWL::Keyboard::Key::NumPadMultiply;
			case XK_KP_Divide: return OWL::Keyboard::Key::NumPadDivide;
			case XK_KP_Subtract: return OWL::Keyboard::Key::NumPadMinus;
			case XK_KP_Add: return OWL::Keyboard::Key::NumPadPlus;
			case XK_KP_Delete: return OWL::Keyboard::Key::NumPadDelete;
			case XK_Up: return OWL::Keyboard::Key::ArrowUp;
			case XK_Down: return OWL::Keyboard::Key::ArrowDown;
			case XK_Left: return OWL::Keyboard::Key::ArrowLeft;
			case XK_Right: return OWL::Keyboard::Key::ArrowRight;
			case XK_Sys_Req: return OWL::Keyboard::Key::PrintScreen;
			case XK_Scroll_Lock: return OWL::Keyboard::Key::ScrollLock;
			case XK_Pause: return OWL::Keyboard::Key::Pause;
			case XK_Insert: return OWL::Keyboard::Key::Insert;
			case XK_Home: return OWL::Keyboard::Key::Home;
			case XK_Page_Up: return OWL::Keyboard::Key::PageUp;
			case XK_Delete: return OWL::Keyboard::Key::Delete;
			case XK_End: return OWL::Keyboard::Key::End;
			case XK_Page_Down: return OWL::Keyboard::Key::PageDown;
			case XK_quoteleft: return OWL::Keyboard::Key::BackQuote;
			default: return OWL::Keyboard::None;
		}
	}

	virtual bool isKeyPressed(unsigned int _key) const {
		bool returnedBool = false;

		char keys[1024];
		XQueryKeymap(OSInfo::get()->displayX11, keys);
		::KeyCode key = XKeysymToKeycode(OSInfo::get()->displayX11, m_keyMap[_key]);
		returnedBool = !!(keys[key>>3] & (1<<(key&7)));

		return returnedBool;
	}

public:
	virtual void pollPreparation() {
		m_keyData.keyChar = '\0';
		m_keyData.keyEnum = OWL::Keyboard::None;
	}
	virtual void pollSpecificEvents() {
		if(Win(m_windowImpl)->m_event.type == KeyPress) {
			int status;
			KeySym keysym = NoSymbol;
			wchar_t text[32] = {};

			XwcLookupString(Win(m_windowImpl)->m_xIC, &Win(m_windowImpl)->m_event.xkey, text, sizeof(text) - 1, &keysym, &status);

			if(status == XLookupChars || status == XLookupBoth) {
				if(text[0] == '\r') {
					m_keyData = KeyData{'\n', OWL::Keyboard::Enter};
				}
				else {
					m_keyData = KeyData{text[0], (status == XLookupBoth ? translateFromVirtualKey(keysym) : OWL::Keyboard::None)};
				}
			}
			else if(status == XLookupKeySym){
				m_keyData = KeyData{'\0', translateFromVirtualKey(keysym)};
			}
		}
		else if(Win(m_windowImpl)->m_event.type == MappingNotify) {
			XRefreshKeyboardMapping(&Win(m_windowImpl)->m_event.xmapping);
		}
	}

};
}
}