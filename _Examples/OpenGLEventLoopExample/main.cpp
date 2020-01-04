#include <iostream>
#include "OWL/OWL.hpp"
#include "OWL/GLContext.hpp"

int Main(const std::vector<std::string>& _args) {
	/* Initializing an OpenGL rendering context */
	OWL::GLContext context;
	/* Initializing a window using an EventLoop Event Loop Type (Remember - they can be dynamically changed) */
	OWL::Window window(&context, "OWL OpenGL EventLoop Example", OWL::Vec2i(0), OWL::Vec2ui(1280, 720), OWL::EventLoopType::EventLoop);

	/* Setting OpenGL's clearing color to gray */
	glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
	
	/* Main Loop */
	while(window.IsRunning()) {
		/* Polling an event */
		window.PollEvents();

		/* Using some of the polled events */
		Debug::Out::Print("//////////////////////////////////////////////////////\n");
		Debug::Out::Print("[Mouse Position]" + std::to_string(window.Mouse.GetPosition().x) + " " + std::to_string(window.Mouse.GetPosition().y) + "\n");
		Debug::Out::Print("[Left Button Pressed]" + std::to_string(window.Mouse.IsButtonPressed(window.Mouse.Left)) + "\n");
		Debug::Out::Print("[Wheel Rotation]" + std::to_string(window.Mouse.GetWheelRotation()) + "\n");
		Debug::Out::Print("[Window Position]" + std::to_string(window.GetPosition().x) + " " + std::to_string(window.GetPosition().y) + "\n");
		Debug::Out::Print("[Window Size]" + std::to_string(window.GetSize().x) + " " + std::to_string(window.GetSize().y) + "\n");

		/* Clearing the OpenGL's main frame buffer */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swapping OpenGL's main frame buffer with window's frame buffer */
		context.SwapBuffers();
	}
}