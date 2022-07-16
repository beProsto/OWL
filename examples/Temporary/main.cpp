#include <OWL/Main.hpp>
#include <OWL/OWL.hpp>
#include <OWL/Time.hpp>

int main(int argc, char** argv) {
	OWL::Window window;
	OWL::SoftwareContext soft;
	window.SetContext(soft);

	OWL::FPSLimiter fps(10);

	while(window.IsRunning()) {
		window.PollEvents();
		fps.Start();

		printf("X%d Y%d!\n", 
			window.Mouse.GetPosition().x, 
			window.Mouse.GetPosition().y
		);
		printf("L%d M%d R%d B%d F%d\n",
			window.Mouse.IsButtonPressed(OWL::Mouse::Left),
			window.Mouse.IsButtonPressed(OWL::Mouse::Middle),
			window.Mouse.IsButtonPressed(OWL::Mouse::Right),
			window.Mouse.IsButtonPressed(OWL::Mouse::Backward),
			window.Mouse.IsButtonPressed(OWL::Mouse::Forward)
		);

		if(window.Mouse.IsButtonPressed(OWL::Mouse::Left)) {
			window.Mouse.SetVisibility(!window.Mouse.IsVisible());
		}

		if(window.Mouse.IsButtonPressed(OWL::Mouse::Middle) || window.Keyboard.IsKeyPressed(OWL::Keyboard::F11)) {
			window.SetFullScreen(!window.IsFullScreen());
		}

		if(window.Keyboard.IsKeyPressed(OWL::Keyboard::Escape)) {
			window.Close();
		}

		soft.SetSize(window.GetSize());

		soft.Clear(OWL::Vec4ub(0, 255, 0, 255));
		soft.BlitToScreen();

		fps.End();
	}
	return 0;
}