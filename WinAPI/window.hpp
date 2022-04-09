#ifndef _OWL_WINAPI_WINDOW_HPP_HEADER_FILE_GUARD
#define _OWL_WINAPI_WINDOW_HPP_HEADER_FILE_GUARD

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

#include "WinAPI.hpp"
#include "context.hpp"

namespace OWL {
namespace WinAPI {

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg) {
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
			
		case WM_DESTROY:
			break;
			
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

class Window {
public:
	class GamepadEvent {
	public:
		GamepadEvent(Window* _window = nullptr) {
			m_Window = _window;
			m_LeftStick = Vec2<float>(0.0f);
			m_RightStick = Vec2<float>(0.0f);
			m_LeftTrigger = 0.0f;
			m_LeftTrigger = 0.0f;
			for(unsigned int i = 0; i < 15; i++) {
				m_Buttons[i] = false;
			}
			m_Connected = false;
		}
		~GamepadEvent() {

		}

		bool IsConnected() const {
			return m_Connected;
		}

		bool IsButtonPressed(unsigned int _buttonID) const {
			return m_Buttons[_buttonID];
		}
		unsigned int GetButtonsAmmount() const {
			return 15;
		}
		const Vec2<float>& GetLeftStick() const {
			return m_LeftStick;
		}
		const Vec2<float>& GetRightStick() const {
			return m_RightStick;
		}
		float GetLeftTrigger() const {
			return m_LeftTrigger;
		}
		float GetRightTrigger() const {
			return m_RightTrigger;
		}

	public:
		enum Button {
			A = 0,
			B = 1,
			X = 2,
			Y = 3,
			Start = 4,
			Back = 5,
			ShoulderLeft = 6,
			ShoulderRight = 7,
			ThumbLeft = 8,
			ThumbRight = 9,
			DPadUp = 10,
			DPadDown = 11,			
			DPadLeft = 12,
			DPadRight = 13,
			Logo = 14
		};

	protected:
		Window* m_Window;
		Vec2<float> m_LeftStick;
		Vec2<float> m_RightStick;
		float m_LeftTrigger;
		float m_RightTrigger;
		bool m_Buttons[15];

		bool m_Connected;

		friend class Window;
	};
	class MouseEvent {
	public:
		MouseEvent(Window* _window = nullptr) {
			m_Window = _window;
			m_Visible = true;
		}
		~MouseEvent() {

		}

		void SetVisibility(bool _visible) {
			ShowCursor(_visible);
			m_Visible = _visible;
		}
		bool IsVisible() const {
			return m_Visible;
		}

		void SetPosition(const Vec2<int>& _position) {
			POINT p;
			p.x = _position.x;
			p.y = _position.y;
			ClientToScreen(m_Window->m_Hwnd, &p);
			SetCursorPos(p.x, p.y);
		}
		Vec2<int> GetPosition() const {
			POINT p;
			GetCursorPos(&p);
			ScreenToClient(m_Window->m_Hwnd, &p);
			return Vec2<int>(p.x, p.y);
		}
		const Vec2<int>& GetPositionFromEvent() const {
			return m_Position;
		}

		int GetWheelRotation() const {
			return m_Wheel;
		}
		
		bool IsButtonPressed(unsigned int _button) const {
			return GetKeyState(_button) & 0x100;
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
		Vec2<int> m_Position;
		bool m_Visible;

		friend class Window;
	};
	class KeyboardEvent {
	public:
		KeyboardEvent(Window* _window = nullptr) {
			m_Window = _window;
		}
		~KeyboardEvent() {

		}
		
		bool IsKeyPressed(int _key) const {
			return GetKeyState(_key) & 0xFFFF0000;
		}

		KeyData GetKeyData() const {
			return m_KeyData;
		}

	public:
		enum Key {
			ShiftLeft = VK_LSHIFT,
			ShiftRight = VK_RSHIFT,
			CtrlLeft = VK_LCONTROL,
			CtrlRight = VK_RCONTROL,
			Enter = VK_RETURN,
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
	Window(Context* _context, const std::string& _title = "OWL WinAPI Window", const Vec2<int>& _position = Vec2<int>(0), const Vec2<unsigned int>& _size = Vec2<unsigned int>(640, 360), const EventLoopType& _eventLoopType = EventLoopType::GameLoop) {
		SetEventLoopType(_eventLoopType);
		Mouse.m_Window = this;
		Keyboard.m_Window = this;
		m_MaxGamepads = 4;
		Gamepad = new GamepadEvent[m_MaxGamepads];
		for(unsigned int i = 0; i < m_MaxGamepads; i++) {
			Gamepad[i].m_Window = this;

			// Setting up the controller's state
			XINPUT_STATE state;
			ZeroMemory(&state, sizeof(XINPUT_STATE));

			// Simply get the state of the controller from XInput.
			DWORD dwResult = XInputGetState(i, &state);

			if(dwResult == ERROR_SUCCESS) {
				// Controller is connected
				Gamepad[i].m_Connected = true;
			}
			else {
				// Controller is not connected
				Gamepad[i].m_Connected = false;
				Debug::Out::Print("Could not open joystick[" + std::to_string(i) + "]!\n", Debug::Out::ERR);
			}
		}
		m_Context = _context;
		m_Running = true;
		m_FullScreen = false;
		m_Title = _title;

		m_ClassName = "WinAPI_Window_ClassName";

		m_Window.cbSize = sizeof(WNDCLASSEX);
		m_Window.style = 0;
		m_Window.lpfnWndProc = WndProc;
		m_Window.cbClsExtra = 0;
		m_Window.cbWndExtra = 0;
		m_Window.hInstance = g_WinAPI_Data->hInstance;
		m_Window.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		m_Window.hCursor = LoadCursor(NULL, IDC_ARROW);
		m_Window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		m_Window.lpszMenuName = nullptr;
		m_Window.lpszClassName = m_ClassName;
		m_Window.hIconSm = nullptr;
	
		if(!RegisterClassEx(&m_Window)) {
			Debug::Out::Print("Error registering the window!", Debug::Out::Type::ERR);
			return;
		}

		m_Hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, m_ClassName, &m_Title[0], WS_OVERLAPPEDWINDOW, _position.x, _position.y, _size.x, _size.y, NULL, NULL, g_WinAPI_Data->hInstance, NULL);
	
		if(m_Hwnd == NULL) {
			Debug::Out::Print("Error creating the window!", Debug::Out::Type::ERR);
			return;
		}

		SetSize(_size);

		if(m_Context != nullptr) {
			m_Context->Create(m_Hwnd);
		}
	
		ShowWindow(m_Hwnd, g_WinAPI_Data->nCmdShow);
		UpdateWindow(m_Hwnd);
	}
	~Window() {
		delete[] Gamepad;
		DestroyWindow(m_Hwnd);
		if(m_Context != nullptr) {
			m_Context->Destroy();
		}
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
		SetWindowPos(m_Hwnd, 0, _position.x, _position.y, 0, 0, SWP_NOSIZE);
		return *this;
	}
	Vec2<int> GetPosition() const {
		RECT rect;
		GetWindowRect(m_Hwnd, &rect);
		return Vec2<int>(rect.left, rect.top);
	}

	Window& SetSize(const Vec2<unsigned int>& _size) {
		if(GetSize() != _size) {
			OWL::Vec2<unsigned int> finalSize;

			SetWindowPos(m_Hwnd, 0, 0, 0, _size.x, _size.y, SWP_NOMOVE);

			finalSize = GetSize();
			if(finalSize != _size) {
				finalSize = _size + (_size - finalSize);
				SetWindowPos(m_Hwnd, 0, 0, 0, finalSize.x, finalSize.y, SWP_NOMOVE);
			}
		}
		return *this;
	}
	Vec2<unsigned int> GetSize() const {
		RECT rect;
		GetClientRect(m_Hwnd, &rect);
		return Vec2<unsigned int>(rect.right - rect.left, rect.bottom - rect.top);
	}
	float GetAspect() const {
		Vec2<unsigned int> size = GetSize();
		return static_cast<float>(size.x) / static_cast<float>(size.y);
	}

	Window& SetTitle(const std::string& _title) {
		if(m_Title != _title) {
			m_Title = _title;
			SetWindowText(m_Hwnd, &m_Title[0]);
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

			if(m_FullScreen) {
				m_WasMaximized = IsZoomed(m_Hwnd);

				LONG style = GetWindowLong(m_Hwnd, GWL_STYLE);
				LONG exStyle = GetWindowLong(m_Hwnd, GWL_EXSTYLE);
				
				SetWindowLong(m_Hwnd, GWL_STYLE, style & ~(WS_CAPTION | WS_THICKFRAME));
				SetWindowLong(m_Hwnd, GWL_EXSTYLE, exStyle & ~(WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE));

				SendMessage(m_Hwnd, WM_SYSCOMMAND, SC_RESTORE, 0);
				SendMessage(m_Hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
			}
			else {
				LONG style = GetWindowLong(m_Hwnd, GWL_STYLE);
				LONG exStyle = GetWindowLong(m_Hwnd, GWL_EXSTYLE);
				
				SetWindowLong(m_Hwnd, GWL_STYLE, style | (WS_CAPTION | WS_THICKFRAME));
				SetWindowLong(m_Hwnd, GWL_EXSTYLE, exStyle | (WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE));

				SendMessage(m_Hwnd, WM_SYSCOMMAND, SC_RESTORE, 0);
				if(m_WasMaximized) {
					SendMessage(m_Hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
				}
			}

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
				
				// Setting up the controller's state
				XINPUT_STATE state;
				ZeroMemory(&state, sizeof(XINPUT_STATE));

				// Simply get the state of the controller from XInput.
				DWORD dwResult = XInputGetState(i, &state);

				if(dwResult == ERROR_SUCCESS) {
					// Controller is connected
					Gamepad[i].m_Connected = true;
				}
				else {
					// Controller is not connected
					Gamepad[i].m_Connected = false;
					Debug::Out::Print("Could not open joystick[" + std::to_string(i) + "]!\n", Debug::Out::ERR);
				}
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

		if(GetMessage(&_self.m_Event, 0, 0, 0)) {
			TranslateMessage(&_self.m_Event);
			DispatchMessage(&_self.m_Event);
			
			PollEventsStandard(_self);
		}
		else {
			_self.Close();
		}
	}
	static void GameLoopPollEvents(Window& _self) {
		_self.Keyboard.m_KeyData = {"", 0};
		_self.Mouse.m_Wheel = 0;

		while(PeekMessage(&_self.m_Event, 0, 0, 0, PM_REMOVE))
		{
			if(_self.m_Event.message == WM_QUIT) {
				_self.Close();
			}
			TranslateMessage(&_self.m_Event);
			DispatchMessage(&_self.m_Event);

			PollEventsStandard(_self);
		}

		PollEventsGamepad(_self);
	}

	static void PollEventsStandard(Window& _self) {
		if(_self.m_Event.message == WM_KEYDOWN) {
			std::string m(1, '\0');
			char a = MapVirtualKey(_self.m_Event.wParam, MAPVK_VK_TO_CHAR);
			if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a >= 65 && a <= 90) {
				m[m.size() - 1] = a;
			}
			else if(a >= 65 && a <= 90) {
				m[m.size() - 1] = a + 32;
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '`') {
				m[m.size() - 1] = '~';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '1') {
				m[m.size() - 1] = '!';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '2') {
				m[m.size() - 1] = '@';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '3') {
				m[m.size() - 1] = '#';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '4') {
				m[m.size() - 1] = '$';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '5') {
				m[m.size() - 1] = '%';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '6') {
				m[m.size() - 1] = '^';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '7') {
				m[m.size() - 1] = '&';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '8') {
				m[m.size() - 1] = '*';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '9') {
				m[m.size() - 1] = '(';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '0') {
				m[m.size() - 1] = ')';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '-') {
				m[m.size() - 1] = '_';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '=') {
				m[m.size() - 1] = '+';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '[') {
				m[m.size() - 1] = '{';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == ']') {
				m[m.size() - 1] = '}';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '\\') {
				m[m.size() - 1] = '|';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == ';') {
				m[m.size() - 1] = ':';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '\'') {
				m[m.size() - 1] = '"';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == ',') {
				m[m.size() - 1] = '<';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '.') {
				m[m.size() - 1] = '>';
			}
			else if(_self.Keyboard.IsKeyPressed(VK_SHIFT) && a == '/') {
				m[m.size() - 1] = '?';
			}
			else {
				m[m.size() - 1] = a;
			}

			if(_self.m_Event.wParam == VK_TAB) {
				m[m.size() - 1] = '\t';
			}
			else if(_self.m_Event.wParam == VK_ESCAPE) {
				m[m.size() - 1] = '\e';
			}
			else if(_self.m_Event.wParam == VK_BACK) {
				m[m.size() - 1] = '\b';
			}
			else if(_self.m_Event.wParam == VK_RETURN) {
				m[m.size() - 1] = '\n';
			}
			else if(_self.m_Event.wParam == VK_SHIFT) {
				m = "";
			}
			else if(_self.m_Event.wParam == VK_CONTROL) {
				m = "";
			}
			else if(_self.m_Event.wParam == VK_MENU) {
				m = "";
			}

			_self.Keyboard.m_KeyData = {m, (unsigned int)_self.m_Event.wParam};
		}
		else if(_self.m_Event.message == WM_MOUSEMOVE) {
			_self.Mouse.m_Position.x = MAKEPOINTS(_self.m_Event.lParam).x;
			_self.Mouse.m_Position.y = MAKEPOINTS(_self.m_Event.lParam).y;
		}
		else if(_self.m_Event.message == WM_MOUSEWHEEL) {
			_self.Mouse.m_Wheel = GET_WHEEL_DELTA_WPARAM(_self.m_Event.wParam);
		}
	}

	static inline OWL::Vec2f _STICK_NORM(float _x, float _y) { // I SWEAR I will implement this in the X11 one i just need to know where to actually even put this lol
		float magnitude = std::sqrt(_x*_x + _y*_y);

		float normalizedLX = _x / magnitude;
		float normalizedLY = _y / magnitude;

		float normalizedMagnitude = 0;

		if (magnitude > 7849) {
			if (magnitude > 32767) magnitude = 32767;
			magnitude -= 7849;
			normalizedMagnitude = magnitude / (32767 - 7849);
		}
		else {
			magnitude = 0.0;
			normalizedMagnitude = 0.0;
		}

		return OWL::Vec2f(normalizedLX * normalizedMagnitude, normalizedLY * normalizedMagnitude);
	}
	static void PollEventsGamepad(Window& _self) {
		for(unsigned int i = 0; i < _self.m_MaxGamepads; i++) {
			// Setting up the controller's state
			XINPUT_STATE state;
			ZeroMemory(&state, sizeof(XINPUT_STATE)); // why? what's the difference if i don't? it's not allocated on the heap so it technically should zero itself out by.. itself... But then why do the docs tell me to do this?
			// Simply get the state of the controller from XInput.
			if(_self.Gamepad[i].m_Connected = (XInputGetState(i, &state) == ERROR_SUCCESS)) {
				// Controller is connected
				_self.Gamepad[i].m_LeftStick = _STICK_NORM(state.Gamepad.sThumbLX, state.Gamepad.sThumbLY);
				_self.Gamepad[i].m_RightStick = _STICK_NORM(state.Gamepad.sThumbRX, state.Gamepad.sThumbRY);
				
				_self.Gamepad[i].m_LeftTrigger = (float)state.Gamepad.bLeftTrigger / 255;
				_self.Gamepad[i].m_RightTrigger = (float)state.Gamepad.bRightTrigger / 255;

				_self.Gamepad[i].m_Buttons[0] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0;
				_self.Gamepad[i].m_Buttons[1] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_B) != 0;
				_self.Gamepad[i].m_Buttons[2] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_X) != 0;
				_self.Gamepad[i].m_Buttons[3] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) != 0;
				
				_self.Gamepad[i].m_Buttons[4] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_START) != 0;
				_self.Gamepad[i].m_Buttons[5] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) != 0;

				_self.Gamepad[i].m_Buttons[6] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) != 0;
				_self.Gamepad[i].m_Buttons[7] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) != 0;

				_self.Gamepad[i].m_Buttons[8] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) != 0;
				_self.Gamepad[i].m_Buttons[9] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) != 0;

				_self.Gamepad[i].m_Buttons[10] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) != 0;
				_self.Gamepad[i].m_Buttons[11] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) != 0;
				_self.Gamepad[i].m_Buttons[12] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) != 0;
				_self.Gamepad[i].m_Buttons[13] = (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) != 0;
			}
			else {
				// Controller is not connected
				Debug::Out::Print("Could not open joystick[" + std::to_string(i) + "]!\n", Debug::Out::ERR);
			}
		}
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
	bool m_WasMaximized;

	LPSTR m_ClassName;
	WNDCLASSEX m_Window;
	HWND m_Hwnd;
	MSG m_Event;
};

}
}

#endif/*_OWL_WINAPI_WINDOW_HPP_HEADER_FILE_GUARD*/