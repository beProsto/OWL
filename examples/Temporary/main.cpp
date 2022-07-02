#include <OWL/Main.hpp>
#include <OWL/OWL.hpp>
#include <OWL/Time.hpp>

int main(int argc, char** argv) {
	OWL::Window window;
	OWL::FPSLimiter fps(60);

	while(window.IsRunning()) {
		window.PollEvents();
		fps.Start();

		fps.End();
	}
	return 0;
}