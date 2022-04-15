#include <iostream>
#include "OWL/OWL.hpp"

void DrawPixel(OWL::Vec4b* _canvas, const OWL::Vec2ui& _size, const OWL::Vec2i& _position, const OWL::Vec4b& _color) {
	if(_position.x >= 0 && _position.x < _size.x && _position.y >= 0 && _position.y < _size.y) {
		_canvas[_position.y * _size.x + _position.x] = _color;
	}
}

void DrawRect(OWL::Vec4b* _canvas, const OWL::Vec2ui& _size, const OWL::Vec2i& _rectPosition, const OWL::Vec2ui& _rectSize, const OWL::Vec4b& _color) {
	for(int i = _rectPosition.x; i < _rectPosition.x + _rectSize.x; i++) {
		for(int j =_rectPosition.y; j < _rectPosition.y + _rectSize.y; j++) {
			DrawPixel(_canvas, _size, OWL::Vec2i(i, j), _color);
		}
	}
}

int Main(const std::vector<std::string>& _args) {
	/* Initializing a Software rendering context */
	OWL::SoftwareContext context;
	/* Initializing a window using an EventLoop Event Loop Type (Remember - they can be dynamically changed) */
	OWL::Window window(&context, "OWL GUI Application Example", OWL::Vec2i(0), OWL::Vec2ui(1280, 720), OWL::EventLoopType::EventLoop);
	
	/* Creating a color palette */
	OWL::Vec4b colorPalette[5] = {
		OWL::Vec4b(4, 15, 15, 255),
		OWL::Vec4b(36, 130, 50, 255),
		OWL::Vec4b(43, 168, 74, 255),
		OWL::Vec4b(170, 166, 168, 255),
		OWL::Vec4b(252, 255, 252, 255)
	};

	/* Some fancy variables */
	OWL::Vec2i position;
	OWL::Vec2ui size;

	/* Main Loop */
	while(window.IsRunning()) {
		/* Polling an event */
		window.PollEvents();

		/* Resizing the context's pixel array to the window's size */
		context.Resize(window.GetSize());
		context.Clear(colorPalette[4]);

		/* Drawing the rectangles */
		position.x = context.GetSize().x * 0.05f;
		position.y = context.GetSize().y * 0.05f;

		size.x = context.GetSize().x * 0.2f;
		size.y = context.GetSize().y * 0.2f;

		DrawRect(context.GetPixelData(), context.GetSize(), position, size, colorPalette[2]);
		DrawRect(context.GetPixelData(), context.GetSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);


		position.x = context.GetSize().x * 0.05f;
		position.y = context.GetSize().y * 0.3f;

		size.x = context.GetSize().x * 0.2f;
		size.y = context.GetSize().y * 0.65f;

		DrawRect(context.GetPixelData(), context.GetSize(), position, size, colorPalette[1]);
		DrawRect(context.GetPixelData(), context.GetSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);


		position.x = context.GetSize().x * 0.3f;
		position.y = context.GetSize().y * 0.05f;

		size.x = context.GetSize().x * 0.4f;
		size.y = context.GetSize().y * 0.9f;

		DrawRect(context.GetPixelData(), context.GetSize(), position, size, colorPalette[0]);
		DrawRect(context.GetPixelData(), context.GetSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);
		

		position.x = context.GetSize().x * 0.75f;
		position.y = context.GetSize().y * 0.05f;

		size.x = context.GetSize().x * 0.2f;
		size.y = context.GetSize().y * 0.3f;

		DrawRect(context.GetPixelData(), context.GetSize(), position, size, colorPalette[1]);
		DrawRect(context.GetPixelData(), context.GetSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);
		

		position.x = context.GetSize().x * 0.75f;
		position.y = context.GetSize().y * 0.4f;

		size.x = context.GetSize().x * 0.2f;
		size.y = context.GetSize().y * 0.3f;

		DrawRect(context.GetPixelData(), context.GetSize(), position, size, colorPalette[2]);
		DrawRect(context.GetPixelData(), context.GetSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);
		

		position.x = context.GetSize().x * 0.75f;
		position.y = context.GetSize().y * 0.75f;

		size.x = context.GetSize().x * 0.2f;
		size.y = context.GetSize().y * 0.2f;

		DrawRect(context.GetPixelData(), context.GetSize(), position, size, colorPalette[1]);
		DrawRect(context.GetPixelData(), context.GetSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);

		/* Blitting context's pixel data to window's screen */
		context.BlitToScreen();
	}

	return 0;
}