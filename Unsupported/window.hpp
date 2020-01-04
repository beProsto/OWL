#ifndef _OWL_UNSUPPORTED_WINDOW_HPP_HEADER_FILE_GUARD
#define _OWL_UNSUPPORTED_WINDOW_HPP_HEADER_FILE_GUARD

namespace OWL {
namespace Unsupported {
class Window {
public:
	class MouseEvent {
	public:
		MouseEvent(Window* _window = nullptr) {

		}
		~MouseEvent() {

		}

		Vec2<int> GetPosition() const {
			return Vec2<int>(0);
		}
		int GetWheelRotation() const {
			return 0;
		}
		bool IsButtonPressed(unsigned int _button) const {
			return false;
		}

	public:
		enum Button {
			Left = 1,
			Middle = 2,
			Right = 3,
			Backward = 4,
			Forward = 5,
		};
	};
	class KeyboardEvent {
	public:
		KeyboardEvent(Window* _window = nullptr) {
			
		}
		~KeyboardEvent() {

		}
		
		bool IsKeyPressed(unsigned int _key) const {
			return false;
		}

	public:
		enum Key {
			ShiftLeft = 0,
			ShiftRight = 1,
			CtrlLeft = 2,
			CtrlRight = 3,
			Enter = 4,
			CapsLock = 5,
			Tab = 6,
			Apostrophe = 7,
			Escape = 8,
			AltLeft = 9,
			AltRight = 10,
			Backspace = 11,
			Space = 12,
			Num1 = 13,
			Num2 = 14,
			Num3 = 15,
			Num4 = 16,
			Num5 = 17,
			Num6 = 18,
			Num7 = 19,
			Num8 = 20,
			Num9 = 21,
			Num0 = 22,
			NumPad1 = 23,
			NumPad2 = 24,
			NumPad3 = 25,
			NumPad4 = 26,
			NumPad5 = 27,
			NumPad6 = 28,
			NumPad7 = 29,
			NumPad8 = 30,
			NumPad9 = 31,
			NumPad0 = 32,
			Q = 33,
			W = 34,
			E = 35,
			R = 36,
			T = 37,
			Y = 38,
			U = 39,
			I = 40,
			O = 41,
			P = 42,
			A = 43,
			S = 44,
			D = 45,
			F = 46,
			G = 47,
			H = 48,
			J = 49,
			K = 50,
			L = 51,
			Z = 52,
			X = 53,
			C = 54,
			V = 55,
			B = 56,
			N = 57,
			M = 58,
			Comma = 59,
			Period = 60,
			Slash = 61,
			SlashBack = 62,
			Semicolon = 63,
			BracketOpen = 64,
			BracketClose = 65,
			Minus = 66,
			Equals = 67,
			Windows = 68,
			Super = 69,
			/*Fn = 70,*/
			Menu = 71,
			F1 = 72,
			F2 = 73,
			F3 = 74,
			F4 = 75,
			F5 = 76,
			F6 = 77,
			F7 = 78,
			F8 = 79,
			F9 = 80,
			F10 = 81,
			F11 = 82,
			F12 = 83,
			NumLock = 84,
			NumPadSlash = 85,
			NumPadMultiply = 86,
			NumPadMinus = 87,
			NumPadPlus = 88,
			NumPadEnter = 89,
			NumPadDelete = 90,
			ArrowUp = 91,
			ArrowDown = 92,
			ArrowLeft = 93,
			ArrowRight = 94,
			PrintScreen = 95,
			ScrollLock = 96,
			Pause = 97,
			Insert = 98,
			Home = 99,
			PageUp = 100,
			Delete = 101,
			End = 102,
			PageDown = 103,
			BackQuote = 104,
		};

	protected:
		friend class Window;
	};
	
public:
	Window(Context* _context, const Vec2<int>& _position = Vec2<int>(0), const Vec2<unsigned int>& _size = Vec2<unsigned int>(640, 360), const EventLoopType& _eventLoopType = EventLoopType::EventLoop) {

	}
	~Window() {

	}

	Window& PollEvent() {
		return *this;
	}

	Window& SetEventLoopType(const EventLoopType& _eventLoopType) {
		return *this;
	}
	const EventLoopType& GetEventLoopType() const {
		return EventLoopType::EventLoop;
	}

	Vec2<int> GetPosition() const {
		return Vec2<int>(0);
	}
	Vec2<unsigned int> GetSize() const {
		return Vec2<unsigned int>(0);
	}

	Window& SetTitle() {
		return *this;
	}
	std::string GetTitle() const {
		return "";
	}

public:
	MouseEvent Mouse;
};

}
}

#endif/*_OWL_UNSUPPORTED_WINDOW_HPP_HEADER_FILE_GUARD*/
