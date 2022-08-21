#include <iostream>
#include <OWL/OWL.hpp>
#include <OWL/Main.hpp>

void DrawPixel(OWL::Vec4ub* _canvas, const OWL::Vec2ui& _size, const OWL::Vec2i& _position, const OWL::Vec4ub& _color) {
	if(_position.x >= 0 && _position.x < _size.x && _position.y >= 0 && _position.y < _size.y) {
		_canvas[_position.y * _size.x + _position.x] = _color;
	}
}

void DrawRect(OWL::Vec4ub* _canvas, const OWL::Vec2ui& _size, const OWL::Vec2i& _rectPosition, const OWL::Vec2ui& _rectSize, const OWL::Vec4ub& _color) {
	for(int i = _rectPosition.x; i < _rectPosition.x + _rectSize.x; i++) {
		for(int j =_rectPosition.y; j < _rectPosition.y + _rectSize.y; j++) {
			DrawPixel(_canvas, _size, OWL::Vec2i(i, j), _color);
		}
	}
}

int main(int argc, char** argv) {
	/* Initializing a Software rendering context */
	OWL::SoftwareContext context;
	/* Initializing a window */
	OWL::Window window;
	window.setContext(context);
	
	/* Creating a color palette */
	OWL::Vec4ub colorPalette[5] = {
		OWL::Vec4ub(4, 15, 15, 255),
		OWL::Vec4ub(36, 130, 50, 255),
		OWL::Vec4ub(43, 168, 74, 255),
		OWL::Vec4ub(170, 166, 168, 255),
		OWL::Vec4ub(252, 255, 252, 255)
	};

	/* Some fancy variables */
	OWL::Vec2i position;
	OWL::Vec2ui size;

	/* Main Loop */
	while(window.isRunning()) {
		/* Polling an event */
		window.pollEvents();

		/* Resizing the context's pixel array to the window's size */
		context.setSize(window.getSize());
		context.clear(colorPalette[4]);

		/* Drawing the rectangles */
		position.x = context.getSize().x * 0.05f;
		position.y = context.getSize().y * 0.05f;

		size.x = context.getSize().x * 0.2f;
		size.y = context.getSize().y * 0.2f;

		DrawRect(context.getPixelData(), context.getSize(), position, size, colorPalette[2]);
		DrawRect(context.getPixelData(), context.getSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);


		position.x = context.getSize().x * 0.05f;
		position.y = context.getSize().y * 0.3f;

		size.x = context.getSize().x * 0.2f;
		size.y = context.getSize().y * 0.65f;

		DrawRect(context.getPixelData(), context.getSize(), position, size, colorPalette[1]);
		DrawRect(context.getPixelData(), context.getSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);


		position.x = context.getSize().x * 0.3f;
		position.y = context.getSize().y * 0.05f;

		size.x = context.getSize().x * 0.4f;
		size.y = context.getSize().y * 0.9f;

		DrawRect(context.getPixelData(), context.getSize(), position, size, colorPalette[0]);
		DrawRect(context.getPixelData(), context.getSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);
		

		position.x = context.getSize().x * 0.75f;
		position.y = context.getSize().y * 0.05f;

		size.x = context.getSize().x * 0.2f;
		size.y = context.getSize().y * 0.3f;

		DrawRect(context.getPixelData(), context.getSize(), position, size, colorPalette[1]);
		DrawRect(context.getPixelData(), context.getSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);
		

		position.x = context.getSize().x * 0.75f;
		position.y = context.getSize().y * 0.4f;

		size.x = context.getSize().x * 0.2f;
		size.y = context.getSize().y * 0.3f;

		DrawRect(context.getPixelData(), context.getSize(), position, size, colorPalette[2]);
		DrawRect(context.getPixelData(), context.getSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);
		

		position.x = context.getSize().x * 0.75f;
		position.y = context.getSize().y * 0.75f;

		size.x = context.getSize().x * 0.2f;
		size.y = context.getSize().y * 0.2f;

		DrawRect(context.getPixelData(), context.getSize(), position, size, colorPalette[1]);
		DrawRect(context.getPixelData(), context.getSize(), position + OWL::Vec2i(2), OWL::Vec2i(10), colorPalette[3]);

		/* Blitting context's pixel data to window's screen */
		context.blitToScreen();
	}

	return 0;
}