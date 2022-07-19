#include <OWL/OWL.hpp>
#include <OWL/Main.hpp>
#include <OWL/Time.hpp>

int main(int argc, char** argv) {
	OWL::SoftwareContext context;
	OWL::Window window;
	window.SetContext(context);
	OWL::FPSLimiter fps(60);

	while(window.IsRunning()) {
		window.PollEvents();
		fps.Start();

		// if(window.Keyboard.GetKeyData().KeyEnum == window.Keyboard.F11) {
		// 	window.SetFullScreen(!window.IsFullScreen());
		// }
		if(window.Keyboard.IsKeyPressed(window.Keyboard.Escape)) {
			window.Close();
		}

		context.SetSize(window.GetSize());
		context.Clear(OWL::Vec4ub(255, 100, 45, 255)); /* Clears the screen in orange color */

		context.BlitToScreen();

		fps.End();
	}

	return 0;
}
