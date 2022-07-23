#include <iostream>
// #include <thread>

#include <OWL/OWL.hpp>
#include <OWL/Main.hpp>
#include <OWL/Time.hpp>

void DrawPixel(OWL::Vec4ub* _canvas, const OWL::Vec2i& _size, const OWL::Vec2i& _position, const OWL::Vec4ub& _color) {
	if(_position.x >= 0 && _position.x < _size.x && _position.y >= 0 && _position.y < _size.y) {
		_canvas[_position.y * _size.x + _position.x] = _color;
	}
}

void DrawRect(OWL::Vec4ub* _canvas, const OWL::Vec2i& _size, const OWL::Vec2i& _rectPosition, const OWL::Vec2i& _rectSize, const OWL::Vec4ub& _color) {
	for(int i = _rectPosition.x; i < _rectPosition.x + _rectSize.x; i++) {
		for(int j =_rectPosition.y; j < _rectPosition.y + _rectSize.y; j++) {
			DrawPixel(_canvas, _size, OWL::Vec2i(i, j), _color);
		}
	}
}

OWL::Vec4ub colorPalette[5] = {
	OWL::Vec4ub(4, 15, 15, 255),
	OWL::Vec4ub(36, 130, 50, 255),
	OWL::Vec4ub(43, 168, 74, 255),
	OWL::Vec4ub(170, 166, 168, 255),
	OWL::Vec4ub(252, 255, 252, 255)
};

void DrawStickRep(OWL::Vec4ub* _canvas, const OWL::Vec2i& _size, const OWL::Vec2f& _gamepad, bool _pressed, unsigned int _uiSize, float _x, float _y, float _scale) {
	DrawRect(
		_canvas,
		_size,
		OWL::Vec2f(_size) * OWL::Vec2f(_x, _y) - OWL::Vec2i(float(_uiSize) * _scale / 2),
		OWL::Vec2i(float(_uiSize) * _scale),
		colorPalette[3]
	);

	OWL::Vec2f positioning;
	// positioning = ((OWL::Vec2f)window.Mouse.GetPosition() / (OWL::Vec2f)window.GetSize() - OWL::Vec2f(0.5f)) * OWL::Vec2f(2.0f);
	positioning = _gamepad;
	positioning.y = -positioning.y;

	OWL::Vec4ub col = colorPalette[4];
	if(_pressed) col = colorPalette[2];

	DrawRect(
		_canvas,
		_size,
		OWL::Vec2f(_size) * OWL::Vec2f(_x, _y) - OWL::Vec2i(float(_uiSize) * _scale / 4) + positioning * OWL::Vec2i(float(_uiSize) * _scale / 4),
		OWL::Vec2i(float(_uiSize) * _scale / 2),
		col
	);
}

void DrawTriggerRep(OWL::Vec4ub* _canvas, const OWL::Vec2i& _size, float _gamepad, unsigned int _uiSize, float _x, float _y, float _scale) {
	DrawRect(
		_canvas,
		_size,
		OWL::Vec2f(_size) * OWL::Vec2f(_x, _y) - OWL::Vec2i(float(_uiSize) * _scale / 4),
		OWL::Vec2i(float(_uiSize) * _scale * 0.5) * OWL::Vec2f(1.0, 2.0),
		colorPalette[3]
	);

	OWL::Vec2f positioning;
	// positioning = ((OWL::Vec2f)window.Mouse.GetPosition() / (OWL::Vec2f)window.GetSize() - OWL::Vec2f(0.5f)) * OWL::Vec2f(2.0f);
	positioning.y = _gamepad;
	positioning.x = 0.0f;

	DrawRect(
		_canvas,
		_size,
		OWL::Vec2f(_size) * OWL::Vec2f(_x, _y) - OWL::Vec2i(float(_uiSize) * _scale / 6) + positioning * OWL::Vec2i(float(_uiSize) * _scale / 2),
		OWL::Vec2i(float(_uiSize) * _scale / 3),
		colorPalette[2]
	);
}

void DrawButtonRep(OWL::Vec4ub* _canvas, const OWL::Vec2i& _size, bool _gamepad, unsigned int _uiSize, float _x, float _y, float _scale) {
	DrawRect(
		_canvas,
		_size,
		OWL::Vec2f(_size) * OWL::Vec2f(_x, _y) - OWL::Vec2i(float(_uiSize) * _scale / 2),
		OWL::Vec2i(float(_uiSize) * _scale),
		colorPalette[3]
	);
	
	OWL::Vec4ub col = colorPalette[4];
	if(_gamepad) col = colorPalette[1];

	DrawRect(
		_canvas,
		_size,
		OWL::Vec2f(_size) * OWL::Vec2f(_x, _y) - OWL::Vec2i(float(_uiSize) * _scale / 4),
		OWL::Vec2i(float(_uiSize) * _scale / 2),
		col
	);
}

void DrawTriButtonRep(OWL::Vec4ub* _canvas, const OWL::Vec2i& _size, unsigned int _uiSize, float _x, float _y, float _scale, bool _butts[4]) {
	DrawButtonRep(_canvas, _size, _butts[0], _uiSize, _x - _scale / 2.0f, _y, _scale);
	DrawButtonRep(_canvas, _size, _butts[1], _uiSize, _x, _y - _scale / 1.5f, _scale);
	DrawButtonRep(_canvas, _size, _butts[2], _uiSize, _x + _scale / 2.0f, _y, _scale);
	DrawButtonRep(_canvas, _size, _butts[3], _uiSize, _x, _y + _scale / 1.5f, _scale);
}

int main(int argc, char** args) {
	OWL::SoftwareContext context;
	OWL::Window window;
	window.SetContext(context);

	window.Gamepads.SetCount(1);
	
	OWL::FPSLimiter eventDelay(60);
	while(window.IsRunning()) {
		eventDelay.Start();
		window.PollEvents();

		if(window.Keyboard.IsKeyPressed(window.Keyboard.Escape)) {
			window.Close();
		}
		if(window.Keyboard.GetKeyData().Enum == window.Keyboard.F11) {
			window.SetFullScreen(!window.IsFullScreen());
		}

		context.SetSize(window.GetSize());
		context.Clear(colorPalette[0]);

		unsigned int uiSize = (
			(window.GetSize().x > window.GetSize().y) ? 
			window.GetSize().y : 
			window.GetSize().x
		);
		
		// std::cout << "LeftX = " << window.Gamepads[0].GetLeftStick().x << "\nLeftY = " << window.Gamepads[0].GetLeftStick().y << std::endl;

		DrawStickRep(context.GetPixelData(), context.GetSize(), window.Gamepads[0].GetLeftStick(), window.Gamepads[0].IsButtonPressed(OWL::Gamepad::ThumbLeft), uiSize, 0.25, 0.7, 0.4);
		DrawStickRep(context.GetPixelData(), context.GetSize(), window.Gamepads[0].GetRightStick(), window.Gamepads[0].IsButtonPressed(OWL::Gamepad::ThumbRight), uiSize, 0.75, 0.7, 0.4);

		DrawButtonRep(context.GetPixelData(), context.GetSize(), window.Gamepads[0].IsButtonPressed(OWL::Gamepad::ShoulderLeft), uiSize, 0.12f, 0.1f, 0.12);
		DrawButtonRep(context.GetPixelData(), context.GetSize(), window.Gamepads[0].IsButtonPressed(OWL::Gamepad::ShoulderRight), uiSize, 0.88f, 0.1f, 0.12);

		DrawTriggerRep(context.GetPixelData(), context.GetSize(), window.Gamepads[0].GetLeftTrigger(), uiSize, 0.05, 0.1, 0.25);
		DrawTriggerRep(context.GetPixelData(), context.GetSize(), window.Gamepads[0].GetRightTrigger(), uiSize, 0.95, 0.1, 0.25);

		DrawButtonRep(context.GetPixelData(), context.GetSize(), window.Gamepads[0].IsButtonPressed(OWL::Gamepad::Back),  uiSize, 1.f / 2.f - 0.12 / 2.f, 0.2f, 0.12);
		DrawButtonRep(context.GetPixelData(), context.GetSize(), window.Gamepads[0].IsButtonPressed(OWL::Gamepad::Start), uiSize, 1.f / 2.f + 0.12 / 2.f, 0.2f, 0.12);
		DrawButtonRep(context.GetPixelData(), context.GetSize(), window.Gamepads[0].IsButtonPressed(OWL::Gamepad::Logo),  uiSize, 1.f / 2.f,              0.2f, 0.12);

		bool buttonsABXY[4] = {
			window.Gamepads[0].IsButtonPressed(OWL::Gamepad::X),
			window.Gamepads[0].IsButtonPressed(OWL::Gamepad::Y),
			window.Gamepads[0].IsButtonPressed(OWL::Gamepad::B),
			window.Gamepads[0].IsButtonPressed(OWL::Gamepad::A)
		};

		DrawTriButtonRep(context.GetPixelData(), context.GetSize(), uiSize, 1.f / 5.f * 4.0f, 0.4f, 0.08, buttonsABXY);
		
		bool buttonsDPad[4] = {
			window.Gamepads[0].IsButtonPressed(OWL::Gamepad::DPadLeft),
			window.Gamepads[0].IsButtonPressed(OWL::Gamepad::DPadUp),
			window.Gamepads[0].IsButtonPressed(OWL::Gamepad::DPadRight),
			window.Gamepads[0].IsButtonPressed(OWL::Gamepad::DPadDown)
		};

		DrawTriButtonRep(context.GetPixelData(), context.GetSize(), uiSize, 1.f / 5.f, 0.4f, 0.08, buttonsDPad);

		// for(int i = 0; i < 14; i++) {
		//     float x = i % 7;
		//     float y = i / 7;
		//     DrawButtonRep(context.GetPixelData(), context.GetSize(), window.Gamepads[0].IsButtonPressed(i), uiSize, x / 12.0f + 0.25f, y / 10.0f + 0.2f, 0.15);
		// }

		context.BlitToScreen();
		eventDelay.End();
	}

	return 0;
}