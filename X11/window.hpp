#ifndef _OWL_X11_WINDOW_HPP_HEADER_FILE_GUARD
#define _OWL_X11_WINDOW_HPP_HEADER_FILE_GUARD

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <linux/joystick.h>
#include <fcntl.h>
#include <unistd.h>
#include <cmath>

#include "X11.hpp"
#include "context.hpp"

namespace OWL {
namespace X11 {
class Window {
public:
	class GamepadEvent {
	public:
		GamepadEvent(Window* _window = nullptr) {
			m_Window = _window;
			m_LeftStick = Vec2<float>(0.0f);
			m_RightStick = Vec2<float>(0.0f);
			m_LeftStickInternal = Vec2<float>(0.0f);
			m_RightStickInternal  = Vec2<float>(0.0f);
			m_LeftTrigger = 0.0f;
			m_LeftTrigger = 0.0f;
			for(unsigned int i = 0; i < 15; i++) {
				m_Buttons[i] = false;
			}

			m_JS = -1;
		}
		~GamepadEvent() {
			close(m_JS);
		}

		bool IsConnected() const {
			return (m_JS != -1);
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
			ShoulderLeft = 4,
			ShoulderRight = 5,
			Back = 6,
			Start = 7,
			Logo = 8,
			ThumbLeft = 9,
			ThumbRight = 10,
			DPadLeft = 11,
			DPadRight = 12,
			DPadUp = 13,
			DPadDown = 14
		};

	protected:
		Vec2<float> m_LeftStickInternal;
		Vec2<float> m_RightStickInternal;
		Vec2<float> m_LeftStick;
		Vec2<float> m_RightStick;
		float m_LeftTrigger;
		float m_RightTrigger;
		bool m_Buttons[15];

		int m_JS;

		Window* m_Window;

		friend class Window;
	};
	class MouseEvent {
	public:
		MouseEvent(Window* _window = nullptr) {
			m_Window = _window;
			m_Visible = true;
			m_Position = OWL::Vec2i(0);
		}
		~MouseEvent() {

		}

		void SetVisibility(bool _visible) {
			if(_visible && _visible != m_Visible) {
				Cursor cursor;
				cursor = XCreateFontCursor(m_Window->m_Display, XC_left_ptr);
				XDefineCursor(m_Window->m_Display, m_Window->m_Section, cursor);
				XFreeCursor(m_Window->m_Display, cursor);
			}
			else if(!_visible && _visible != m_Visible) {
				Cursor invisibleCursor;
				Pixmap bitmapNoData;
				XColor black;
				static char noData[] = {0, 0, 0, 0, 0, 0, 0, 0};
				black.red = black.green = black.blue = 0;

				bitmapNoData = XCreateBitmapFromData(m_Window->m_Display, m_Window->m_Section, noData, 8, 8);
				invisibleCursor = XCreatePixmapCursor(m_Window->m_Display, bitmapNoData, bitmapNoData, 
													 &black, &black, 0, 0);
				XDefineCursor(m_Window->m_Display, m_Window->m_Section, invisibleCursor);
				XFreeCursor(m_Window->m_Display, invisibleCursor);
				XFreePixmap(m_Window->m_Display, bitmapNoData);
			}
			m_Visible = _visible;
		}
		bool IsVisible() const {
			return m_Visible;
		}

		void SetPosition(const Vec2<int>& _position) {
			XWarpPointer(m_Window->m_Display, None, m_Window->m_Section, 0, 0, 0, 0, _position.x, _position.y);
		}
		Vec2<int> GetPosition() const {
			int xReturned, yReturned;

			int tmpInt; ::Window tmpRoot, tmpWin;
			XQueryPointer(m_Window->m_Display, m_Window->m_Section, &tmpRoot, &tmpWin, &tmpInt, &tmpInt, &xReturned, &yReturned, (unsigned int*)&tmpInt);
			
			return OWL::Vec2<int>(xReturned, yReturned);
		}
		const Vec2<int>& GetPositionFromEvent() const {
			return m_Position;
		}

		int GetWheelRotation() const {
			return m_Wheel;
		}
		
		bool IsButtonPressed(unsigned int _button) const {
			unsigned int buttonPressed;

			int tmpInt; ::Window tmpRoot, tmpWin;
			XQueryPointer(m_Window->m_Display, m_Window->m_Section, &tmpRoot, &tmpWin, &tmpInt, &tmpInt, &tmpInt, &tmpInt, &buttonPressed);
			
			return (buttonPressed & _button);
		}

	public:
		enum Button {
			Left = 1<<8,
			Middle = 1<<9,
			Right = 1<<10,
			Backward = 1<<15,
			Forward = 1<<16,
		};

	protected:
		Window* m_Window;
		int m_Wheel;
		bool m_Visible;
		Vec2<int> m_Position;

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
			bool returnedBool = false;

			char keys[1024];
			XQueryKeymap(m_Window->m_Display, keys);
			::KeyCode key = XKeysymToKeycode(m_Window->m_Display, _key);
			returnedBool = !!(keys[key>>3] & (1<<(key&7)));

			return returnedBool;
		}

		KeyData GetKeyData() const {
			return m_KeyData;
		}

	public:
		enum Key {
			ShiftLeft = XK_Shift_L,
			ShiftRight = XK_Shift_R,
			CtrlLeft = XK_Control_L,
			CtrlRight = XK_Control_R,
			Enter = XK_Return,
			CapsLock = XK_Caps_Lock,
			Tab = XK_Tab,
			Apostrophe = XK_apostrophe,
			Escape = XK_Escape,
			AltLeft = XK_Alt_L,
			AltRight = XK_Alt_R,
			Backspace = XK_BackSpace,
			Space = XK_space,
			Num1 = XK_1,
			Num2 = XK_2,
			Num3 = XK_3,
			Num4 = XK_4,
			Num5 = XK_5,
			Num6 = XK_6,
			Num7 = XK_7,
			Num8 = XK_8,
			Num9 = XK_9,
			Num0 = XK_0,
			NumPad1 = XK_KP_1,
			NumPad2 = XK_KP_2,
			NumPad3 = XK_KP_3,
			NumPad4 = XK_KP_4,
			NumPad5 = XK_KP_5,
			NumPad6 = XK_KP_6,
			NumPad7 = XK_KP_7,
			NumPad8 = XK_KP_8,
			NumPad9 = XK_KP_9,
			NumPad0 = XK_KP_0,
			Q = XK_Q,
			W = XK_W,
			E = XK_E,
			R = XK_R,
			T = XK_T,
			Y = XK_Y,
			U = XK_U,
			I = XK_I,
			O = XK_O,
			P = XK_P,
			A = XK_A,
			S = XK_S,
			D = XK_D,
			F = XK_F,
			G = XK_G,
			H = XK_H,
			J = XK_J,
			K = XK_K,
			L = XK_L,
			Z = XK_Z,
			X = XK_X,
			C = XK_C,
			V = XK_V,
			B = XK_B,
			N = XK_N,
			M = XK_M,
			Comma = XK_KP_Separator,
			Period = XK_period,
			Slash = XK_slash,
			SlashBack = XK_backslash,
			Semicolon = XK_semicolon,
			BracketOpen = XK_bracketleft,
			BracketClose = XK_bracketright,
			Minus = XK_minus,
			Equals = XK_equal,
			Windows = XK_Super_L, /* "Windows Key" or "Super Key" */
			Super = XK_Super_L, /* "Windows Key" or "Super Key" */
			/*Fn = 70,*/ /* How do i do this? Pls help. */
			Menu = XK_Menu,
			F1 = XK_F1,
			F2 = XK_F2,
			F3 = XK_F3,
			F4 = XK_F4,
			F5 = XK_F5,
			F6 = XK_F6,
			F7 = XK_F7,
			F8 = XK_F8,
			F9 = XK_F9,
			F10 = XK_F10,
			F11 = XK_F11,
			F12 = XK_F12,
			NumLock = XK_Num_Lock,
			NumPadMultiply = XK_KP_Multiply,
			NumPadDivide = XK_KP_Divide,
			NumPadMinus = XK_KP_Subtract,
			NumPadPlus = XK_KP_Add,
			NumPadEnter = XK_KP_Enter,
			NumPadDelete = XK_KP_Delete,
			ArrowUp = XK_Up,
			ArrowDown = XK_Down,
			ArrowLeft = XK_Left,
			ArrowRight = XK_Right,
			PrintScreen = XK_Sys_Req,
			ScrollLock = XK_Scroll_Lock,
			Pause = XK_Pause,
			Insert = XK_Insert,
			Home = XK_Home,
			PageUp = XK_Page_Up,
			Delete = XK_Delete,
			End = XK_End,
			PageDown = XK_Page_Down,
			BackQuote = XK_quoteleft,
		};

	protected:
		Window* m_Window;
		KeyData m_KeyData;

		friend class Window;
	};

public:
	Window(Context* _context, const std::string& _title = "OWL X11 Window", const Vec2<int>& _position = Vec2<int>(0), const Vec2<unsigned int>& _size = Vec2<unsigned int>(640, 360), const EventLoopType& _eventLoopType = EventLoopType::GameLoop) {
		SetEventLoopType(_eventLoopType);
		Mouse.m_Window = this;
		Keyboard.m_Window = this;
		m_MaxGamepads = 4;
		Gamepad = new GamepadEvent[m_MaxGamepads];
		for(unsigned int i = 0; i < m_MaxGamepads; i++) {
			Gamepad[i].m_Window = this;

			Gamepad[i].m_JS = open(std::string("/dev/input/js" + std::to_string(i)).c_str(), O_NONBLOCK);
			if (Gamepad[i].m_JS == -1) {
				Debug::Out::Print("Could not open joystick[" + std::to_string(i) + "]!\n", Debug::Out::ERR);
			}
		}
		m_Context = _context;
		m_Running = true;
		m_FullScreen = false;

		m_Display = XOpenDisplay(0);
		if(m_Display == nullptr) {
			Debug::Out::Print("Display couldn't open!\n", Debug::Out::Type::ERR);
			assert(false);
		}
		m_ScreenID = DefaultScreen(m_Display);

		m_Context->Create(m_Display, &m_ScreenID, &m_Section, _position, _size);

		XSetLocaleModifiers("");
		m_XIM = XOpenIM(m_Display, 0, 0, 0);
		if(!m_XIM){
			XSetLocaleModifiers("@im=none");
			m_XIM = XOpenIM(m_Display, 0, 0, 0);
		}
		m_XIC = XCreateIC(m_XIM,
							XNInputStyle,   XIMPreeditNothing | XIMStatusNothing,
							XNClientWindow, m_Section,
							XNFocusWindow,  m_Section,
							NULL);
		XSetICFocus(m_XIC);

		SetTitle(_title);

		m_WMDelete = XInternAtom(m_Display, "WM_DELETE_WINDOW", false);
		XSetWMProtocols(m_Display, m_Section, &m_WMDelete, 1);
	}
	~Window() {
		m_Context->Destroy();
		delete[] Gamepad;
		XDestroyIC(m_XIC);
		XCloseIM(m_XIM);
		XDestroyWindow(m_Display, m_Section);
		XCloseDisplay(m_Display);
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
		XMoveWindow(m_Display, m_Section, _position.x, _position.y);
		return *this;
	}
	Vec2<int> GetPosition() const {
		int x, y;
		::Window child;
		::XWindowAttributes xwa;
		XTranslateCoordinates(m_Display, m_Section, XDefaultRootWindow(m_Display), 0, 0, &x, &y, &child);
		XGetWindowAttributes(m_Display, m_Section, &xwa);
		
		return Vec2<int>(x - xwa.x, y - xwa.y);
	}

	Window& SetSize(const Vec2<unsigned int>& _size) {
		XResizeWindow(m_Display, m_Section, _size.x, _size.y);
		return *this;
	}
	Vec2<unsigned int> GetSize() const {
		Vec2<unsigned int> sizeReturned;

		::Window tmpRoot; unsigned int tmpUnsignedInt; int tmpInt;
		XGetGeometry(m_Display, m_Section, &tmpRoot, &tmpInt, &tmpInt, &sizeReturned.x, &sizeReturned.y, &tmpUnsignedInt, &tmpUnsignedInt);

		return sizeReturned;
	}
	float GetAspect() const {
		Vec2<unsigned int> size = GetSize();
		return static_cast<float>(size.x) / static_cast<float>(size.y);
	}

	Window& SetTitle(const std::string& _title) {
		if(m_Title != _title) {
			m_Title = _title;
			XStoreName(m_Display, m_Section, m_Title.c_str());
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
			XEvent event;
			Atom stateAtom;
			Atom fsAtom;

			stateAtom = XInternAtom(m_Display, "_NET_WM_STATE", False);
			fsAtom = XInternAtom(m_Display, "_NET_WM_STATE_FULLSCREEN", False);

			event.xclient.type = ClientMessage;
			event.xclient.serial = 0;
			event.xclient.send_event = True;
			event.xclient.window = m_Section;
			event.xclient.message_type = stateAtom;
			event.xclient.format = 32;
			event.xclient.data.l[0] = _fullScreen; /* usage of atoms: 0 (false) - remove atom; 1 (true) - add atom; 2 - toggle; */
			event.xclient.data.l[1] = fsAtom;
			event.xclient.data.l[2] = 0;

			XSendEvent(m_Display, XDefaultRootWindow(m_Display), False, SubstructureRedirectMask | SubstructureNotifyMask, &event);
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

				Gamepad[i].m_JS = open(std::string("/dev/input/js" + std::to_string(i)).c_str(), O_NONBLOCK);
				if (Gamepad[i].m_JS == -1) {
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
		
		XNextEvent(_self.m_Display, &_self.m_Event);
		PollEventsStandard(_self);
		
		PollEventsGamepad(_self);
	}
	static void GameLoopPollEvents(Window& _self) {
		_self.Keyboard.m_KeyData = {"", 0};
		_self.Mouse.m_Wheel = 0;

		while(XPending(_self.m_Display) > 0) {
			XNextEvent(_self.m_Display, &_self.m_Event);
			if(XFilterEvent(&_self.m_Event, None)) {
				continue;
			}
			PollEventsStandard(_self);
		}

		PollEventsGamepad(_self);
	}
	static void PollEventsStandard(Window& _self) {			
		if(_self.m_Event.type == ButtonPress) {
			if(_self.m_Event.xbutton.button == Button4) {
				_self.Mouse.m_Wheel += 1;
			}
			else if(_self.m_Event.xbutton.button == Button5) {
				_self.Mouse.m_Wheel -= 1;
			}
		}

		else if(_self.m_Event.type == MotionNotify) {
			_self.Mouse.m_Position = OWL::Vec2<int>(_self.m_Event.xmotion.x, _self.m_Event.xmotion.y);
		}


		else if(_self.m_Event.type == KeyPress) {
			Status status;
			KeySym keysym = NoSymbol;
			char text[32] = {};

			Xutf8LookupString(_self.m_XIC, &_self.m_Event.xkey, text, sizeof(text) - 1, &keysym, &status);

			if(status == XLookupChars) {
				if(text[0] == '\r') {
					_self.Keyboard.m_KeyData = {"\n", (unsigned int)XK_Return};
				}
				else {
					_self.Keyboard.m_KeyData = {text, 0};
				}
			}
			else if(status == XLookupBoth) {
				if(text[0] == '\r') {
					_self.Keyboard.m_KeyData = {"\n", (unsigned int)XK_Return};
				}
				else {
					_self.Keyboard.m_KeyData = {text, 0};
				}
			}
			else if(status == XLookupKeySym){
				_self.Keyboard.m_KeyData = {"", (unsigned int)keysym};
			}
		}

		
		else if(_self.m_Event.type == ClientMessage) {
			if(_self.m_Event.xclient.data.l[0] == _self.m_WMDelete) {
				_self.Close();
			}
		}
	}
	
	static inline OWL::Vec2f _STICK_NORM(OWL::Vec2f _pos) { // I SWEAR I will implement this in the X11 one i just need to know where to actually even put this lol
		float magnitude = std::sqrt(_pos.x*_pos.x + _pos.y*_pos.y);

		float normalizedLX = _pos.x / magnitude;
		float normalizedLY = -_pos.y / magnitude;

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
			while(read(_self.Gamepad[i].m_JS, &_self.m_JSEvent, sizeof(_self.m_JSEvent)) > 0) {
				if(_self.m_JSEvent.type == JS_EVENT_BUTTON) {
					_self.Gamepad[i].m_Buttons[_self.m_JSEvent.number] = _self.m_JSEvent.value;
				}
				else if(_self.m_JSEvent.type == JS_EVENT_AXIS) {
					if(_self.m_JSEvent.number == 0) {
						_self.Gamepad[i].m_LeftStickInternal.x = (float)_self.m_JSEvent.value;
					}
					else if(_self.m_JSEvent.number == 1) {
						_self.Gamepad[i].m_LeftStickInternal.y = (float)_self.m_JSEvent.value;
					}
					else if(_self.m_JSEvent.number == 2) {
						_self.Gamepad[i].m_LeftTrigger = (float)_self.m_JSEvent.value / 32767.0f / 2.0f + 0.5f;
					}
					else if(_self.m_JSEvent.number == 3) {
						_self.Gamepad[i].m_RightStickInternal.x = (float)_self.m_JSEvent.value;
					}
					else if(_self.m_JSEvent.number == 4) {
						_self.Gamepad[i].m_RightStickInternal.y = (float)_self.m_JSEvent.value;
					}
					else if(_self.m_JSEvent.number == 5) {
						_self.Gamepad[i].m_RightTrigger = (float)_self.m_JSEvent.value / 32767.0f / 2.0f + 0.5f;
					}
				}
			}

			if(_self.Gamepad[i].m_LeftStickInternal != Vec2f(0))
				_self.Gamepad[i].m_LeftStick = _STICK_NORM(_self.Gamepad[i].m_LeftStickInternal);
			if(_self.Gamepad[i].m_RightStickInternal != Vec2f(0))
				_self.Gamepad[i].m_RightStick = _STICK_NORM(_self.Gamepad[i].m_RightStickInternal);

			if(errno == ENODEV || _self.Gamepad[i].m_JS == -1) {
				_self.Gamepad[i].m_JS = open(std::string("/dev/input/js" + std::to_string(i)).c_str(), O_NONBLOCK);
				if(_self.Gamepad[i].m_JS == -1) {
					Debug::Out::Print("Could not open joystick[" + std::to_string(i) + "]!\n", Debug::Out::ERR);
				}
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

	js_event m_JSEvent;
	unsigned int m_MaxGamepads;

	::XEvent m_Event;
	::XIM m_XIM;
	::XIC m_XIC;
	::Atom m_WMDelete;

	::Display* m_Display;
	::Window m_Section;
	int m_ScreenID;

	std::string m_Title;
	bool m_Running;
	bool m_FullScreen;
};

}
}

#endif/*_OWL_X11_WINDOW_HPP_HEADER_FILE_GUARD*/
