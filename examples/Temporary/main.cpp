#include <OWL/Main.hpp>
#include <OWL/OWL.hpp>
#include <OWL/Time.hpp>

int main(int argc, char** argv) {
	OWL::Window window;
	OWL::FPSLimiter fps(10);

	while(window.IsRunning()) {
		window.PollEvents();
		fps.Start();

		printf("X%d Y%d!\n", 
			window.Mouse.GetPosition().x, 
			window.Mouse.GetPosition().y
		);
		printf("L%d M%d R%d B%d F%d\n",
			window.Mouse.IsButtonPressed(window.Mouse.Left),
			window.Mouse.IsButtonPressed(window.Mouse.Middle),
			window.Mouse.IsButtonPressed(window.Mouse.Right),
			window.Mouse.IsButtonPressed(window.Mouse.Backward),
			window.Mouse.IsButtonPressed(window.Mouse.Forward)
		);

		if(window.Mouse.IsButtonPressed(window.Mouse.Left)) {
			window.Mouse.SetVisibility(!window.Mouse.IsVisible());
		}

		if(window.Mouse.IsButtonPressed(window.Mouse.Right)) {
			window.Mouse.SetPosition(OWL::Vec2i(0, 0));
		}
		

		fps.End();
	}
	return 0;
}