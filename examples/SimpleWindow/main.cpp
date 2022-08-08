#include <OWL/OWL.hpp>
#include <OWL/Main.hpp>
#include <OWL/Time.hpp>

int main(int argc, char** argv) {
	OWL::SoftwareContext context;
	OWL::Window window;
	window.setContext(context);
	OWL::FPSLimiter fps(60);

	while(window.isRunning()) {
		window.pollEvents();
		fps.start();

		if(window.keyboard.getKeyData().keyEnum == window.keyboard.F11) {
			window.setFullScreen(!window.isFullScreen());
		}
		if(window.keyboard.isKeyPressed(window.keyboard.Escape)) {
			window.close();
		}

		context.setSize(window.getSize());
		context.clear(OWL::Vec4ub(255, 100, 45, 255)); /* clears the screen in orange color */

		context.blitToScreen();

		fps.end();
	}

	return 0;
}
