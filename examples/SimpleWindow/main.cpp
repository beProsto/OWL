#include <OWL/OWL.hpp>
#include <OWL/main.hpp>
#include <OWL/time.hpp>

int Main(const std::vector<std::string>& args) {
	OWL::SoftwareContext context;
	OWL::Window window(&context, "Simple Window in OWL Example", OWL::Vec2i(0), OWL::Vec2ui(480, 460));
	OWL::FPSLimiter fps(60);

	window.SetEventLoopType(OWL::EventLoopType::GameLoop);

	while(window.IsRunning()) {
		window.PollEvents();
		fps.Start();

		if(window.Keyboard.GetKeyData().KeyEnum == window.Keyboard.F11) {
			window.SetFullScreen(!window.IsFullScreen());
		}
		if(window.Keyboard.GetKeyData().KeyEnum == window.Keyboard.Escape) {
			window.Close();
		}

		context.Resize(window.GetSize());
		context.Clear(OWL::Vec4ub(255, 100, 45, 255)); /* Clears the screen in orange color */

		context.BlitToScreen();

		fps.End();
	}

	return 0;
}
