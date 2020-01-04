#ifndef _OWL_WINAPI_WINDOW_HPP_HEADER_FILE_GUARD
#define _OWL_WINAPI_WINDOW_HPP_HEADER_FILE_GUARD

#include <string>
#include <iostream>
#include <cassert>
#include <vector>

#include "WinAPI.hpp"
#include "context.hpp"

namespace OWL {
namespace WinAPI {
class Window {
public:
	class GamepadEvent {
	public:
		GamepadEvent(Window* _window = nullptr) {
			m_Window = _window;
		}
		~GamepadEvent() {
		}

		bool IsButtonPressed(unsigned int _buttonID) const {
			return false;
		}
		const Vec2<float>& GetLeftStick() const {
			return Vec2<float>(0.0f);
		}
		const Vec2<float>& GetRightStick() const {
			return Vec2<float>(0.0f);
		}
		float GetLeftTrigger() const {
			return 0.0f;
		}
		float GetRightTrigger() const {
			return 0.0f;
		}

	protected:
		Window* m_Window;

		friend class Window;
	};
	class MouseEvent {
	public:
		MouseEvent(Window* _window = nullptr) {
			m_Window = _window;
		}
		~MouseEvent() {

		}

		void SetVisibility(bool _visible) {

		}
		bool IsVisible() const {
			return false;
		}

		void SetPosition(const Vec2<int>& _position) {

		}
		Vec2<int> GetPosition() const {
			return Vec2<int>(0);
		}
		Vec2<int> GetPositionFromEvent() const {
			return Vec2<int>(0);
		}

		int GetWheelRotation() const {
			return m_Wheel;
		}
		
		bool IsButtonPressed(unsigned int _button) const {
			return false;
		}

	public:
		enum Button {
			Left = VK_LBUTTON,
			Middle = VK_MBUTTON,
			Right = VK_RBUTTON,
			Backward = VK_XBUTTON1,
			Forward = VK_XBUTTON2,
		};

	protected:
		Window* m_Window;
		int m_Wheel;

		friend class Window;
	};
	class KeyboardEvent {
	public:
		KeyboardEvent(Window* _window = nullptr) {
			m_Window = _window;
		}
		~KeyboardEvent() {

		}
		
		bool IsKeyPressed(unsigned int _key) const {
			return false;
		}

		KeyData GetKeyData() const {
			return m_KeyData;
		}

	public:
		enum Key {
			ShiftLeft = VK_LShift,
			ShiftRight = VK_RShift,
			CtrlLeft = VK_LControl,
			CtrlRight = VK_RControl,
			Enter = VK_Return,
			CapsLock = VK_CAPITAL,
			Tab = VK_TAB,
			Apostrophe = VK_OEM_7,
			Escape = VK_ESCAPE,
			AltLeft = VK_LMENU,
			AltRight = VK_RMENU,
			Backspace = VK_BACK,
			Space = VK_SPACE,
			Num1 = 0x31,
			Num2 = 0x32,
			Num3 = 0x33,
			Num4 = 0x34,
			Num5 = 0x35,
			Num6 = 0x36,
			Num7 = 0x37,
			Num8 = 0x38,
			Num9 = 0x39,
			Num0 = 0x30,
			NumPad1 = VK_NUMPAD1,
			NumPad2 = VK_NUMPAD2,
			NumPad3 = VK_NUMPAD3,
			NumPad4 = VK_NUMPAD4,
			NumPad5 = VK_NUMPAD5,
			NumPad6 = VK_NUMPAD6,
			NumPad7 = VK_NUMPAD7,
			NumPad8 = VK_NUMPAD8,
			NumPad9 = VK_NUMPAD9,
			NumPad0 = VK_NUMPAD0,
			Q = 0x51,
			W = 0x57,
			E = 0x45,
			R = 0x52,
			T = 0x54,
			Y = 0x59,
			U = 0x55,
			I = 0x49,
			O = 0x4F,
			P = 0x50,
			A = 0x41,
			S = 0x53,
			D = 0x44,
			F = 0x46,
			G = 0x47,
			H = 0x48,
			J = 0x4A,
			K = 0x4B,
			L = 0x4C,
			Z = 0x5A,
			X = 0x58,
			C = 0x43,
			V = 0x56,
			B = 0x42,
			N = 0x4E,
			M = 0x4D,
			Comma = VK_OEM_COMMA,
			Period = VK_OEM_PERIOD,
			Slash = VK_OEM_2,
			SlashBack = VK_OEM_5,
			Semicolon = VK_OEM_1,
			BracketOpen = VK_OEM_4,
			BracketClose = VK_OEM_6,
			Minus = VK_OEM_MINUS,
			Equals = VK_OEM_PLUS,
			Windows = VK_LWIN, /* "Windows Key" or "Super Key" */
			Super = VK_LWIN, /* "Windows Key" or "Super Key" */
			/*Fn = 70,*/ /* How do i do this? Pls help. */
			Menu = VK_MENU,
			F1 = VK_F1,
			F2 = VK_F2,
			F3 = VK_F3,
			F4 = VK_F4,
			F5 = VK_F5,
			F6 = VK_F6,
			F7 = VK_F7,
			F8 = VK_F8,
			F9 = VK_F9,
			F10 = VK_F10,
			F11 = VK_F11,
			F12 = VK_F12,
			NumLock = VK_NUMLOCK,
			NumPadMultiply = VK_MULTIPLY,
			NumPadDivide = VK_DIVIDE,
			NumPadMinus = VK_SUBTRACT,
			NumPadPlus = VK_ADD,
			NumPadEnter = 0, /* Help pls */
			NumPadDelete = VK_SEPARATOR,
			ArrowUp = VK_UP,
			ArrowDown = VK_DOWN,
			ArrowLeft = VK_LEFT,
			ArrowRight = VK_RIGHT,
			PrintScreen = VK_SNAPSHOT,
			ScrollLock = VK_SCROLL,
			Pause = VK_PAUSE,
			Insert = VK_INSERT,
			Home = VK_HOME,
			PageUp = VK_PRIOR,
			Delete = VK_DELETE,
			End = VK_END,
			PageDown = VK_NEXT,
			BackQuote = VK_OEM_3,
		};

	protected:
		Window* m_Window;
		KeyData m_KeyData;

		friend class Window;
	};

public:
	Window(Context* _context, const std::string& _title = "OWL WinAPI Window", const Vec2<int>& _position = Vec2<int>(0), const Vec2<unsigned int>& _size = Vec2<unsigned int>(640, 360), const EventLoopType& _eventLoopType = EventLoopType::EventLoop) {
		SetEventLoopType(_eventLoopType);
		Mouse.m_Window = this;
		Keyboard.m_Window = this;
		m_MaxGamepads = 4;
		Gamepad = new GamepadEvent[m_MaxGamepads];
		for(unsigned int i = 0; i < m_MaxGamepads; i++) {
			Gamepad[i].m_Window = this;
		}
		m_Context = _context;
		m_Running = true;
		m_FullScreen = false;
	}
	~Window() {
		delete[] Gamepad;
	}

	Window& PollEvents() {
		m_PollEventsFunction(*this);
		return *this;
	}

	Window& SetEventLoopType(const EventLoopType& _eventLoopType) {
		m_EventLoopType = _eventLoopType;
		if(m_EventLoopType == EventLoopType::EventLoop) {
			m_PollEventsFunction = &EventLoopPollEvents;
		}
		else {
			m_PollEventsFunction = &GameLoopPollEvents;
		}
		return *this;
	}
	const EventLoopType& GetEventLoopType() const {
		return m_EventLoopType;
	}

	Window& SetPosition(const Vec2<int>& _position) {
		return *this;
	}
	Vec2<int> GetPosition() const {
		return Vec2<int>(0);
	}

	Window& SetSize(const Vec2<unsigned int>& _size) {
		return *this;
	}
	Vec2<unsigned int> GetSize() const {
		return Vec2<unsigned int>(0);
	}

	Window& SetTitle(const std::string& _title) {
		if(m_Title != _title) {
			m_Title = _title;
		}
		return *this;
	}
	const std::string& GetTitle() const {
		return m_Title;
	}

	Window& Close() {
		m_Running = false;
		return *this;
	}
	bool IsRunning() const {
		return m_Running;
	}

	Window& SetFullScreen(bool _fullScreen) {
		if(m_FullScreen != _fullScreen) {
			m_FullScreen = _fullScreen;
		}
		return *this;
	}
	bool IsFullScreen() const {
		return m_FullScreen;
	}

	void SetMaxGamepads(unsigned int _maxGamepads) {
		if(m_MaxGamepads != _maxGamepads) {
			m_MaxGamepads = _maxGamepads;

			delete[] Gamepad;
			Gamepad = new GamepadEvent[m_MaxGamepads];

			for(unsigned int i = 0; i < m_MaxGamepads; i++) {
				Gamepad[i].m_Window = this;
			}
		}
	}
	unsigned int GetMaxGamepads() const {
		return m_MaxGamepads;
	}

private:
	static void EventLoopPollEvents(Window& _self) {
		_self.Keyboard.m_KeyData = {"", 0};
		_self.Mouse.m_Wheel = 0;
	}
	static void GameLoopPollEvents(Window& _self) {
		_self.Keyboard.m_KeyData = {"", 0};
		_self.Mouse.m_Wheel = 0;
	}
	static void PollEventsStandard(Window& _self) {	

	}

public:
	MouseEvent Mouse;
	KeyboardEvent Keyboard;
	GamepadEvent* Gamepad;

protected:
	EventLoopType m_EventLoopType;
	void (*m_PollEventsFunction)(Window&);

	Context* m_Context;
	
	unsigned int m_MaxGamepads;

	std::string m_Title;
	bool m_Running;
	bool m_FullScreen;
};

}
}

#endif/*_OWL_WINAPI_WINDOW_HPP_HEADER_FILE_GUARD*/