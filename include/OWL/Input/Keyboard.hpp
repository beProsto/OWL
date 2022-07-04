#pragma once

#include <OWL/Utility/Config.hpp>

namespace OWL {

namespace Impl {
class OWL_API Keyboard;
}

class OWL_API Keyboard {
public:
	Keyboard();
	~Keyboard();

	bool IsKeyPressed(unsigned int _key) const;

public:
	enum Key {
		None = 0,
		ShiftLeft,
		ShiftRight,
		CtrlLeft,
		CtrlRight,
		Enter,
		CapsLock,
		Tab,
		Apostrophe,
		Escape,
		AltLeft,
		AltRight,
		Backspace,
		Space,
		Num1,
		Num2,
		Num3,
		Num4,
		Num5,
		Num6,
		Num7,
		Num8,
		Num9,
		Num0,
		NumPad1,
		NumPad2,
		NumPad3,
		NumPad4,
		NumPad5,
		NumPad6,
		NumPad7,
		NumPad8,
		NumPad9,
		NumPad0,
		Q,
		W,
		E,
		R,
		T,
		Y,
		U,
		I,
		O,
		P,
		A,
		S,
		D,
		F,
		G,
		H,
		J,
		K,
		L,
		Z,
		X,
		C,
		V,
		B,
		N,
		M,
		Comma,
		Period,
		Slash,
		SlashBack,
		Semicolon,
		BracketOpen,
		BracketClose,
		Minus,
		Equals,
		Super, /* "Windows Key" or "Super Key" */
		Menu,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		NumLock,
		NumPadMultiply,
		NumPadDivide,
		NumPadMinus,
		NumPadPlus,
		NumPadDelete,
		ArrowUp,
		ArrowDown,
		ArrowLeft,
		ArrowRight,
		PrintScreen,
		ScrollLock,
		Pause,
		Insert,
		Home,
		PageUp,
		Delete,
		End,
		PageDown,
		BackQuote,
		Count
	};

	/// Later in the code we translate them to OS specific :
	// https://codereview.stackexchange.com/questions/24154/mapping-enum-to-enum

protected:
	Impl::Keyboard* m_Impl;

	friend class Window;
};

}