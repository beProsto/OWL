#include <OWL/Main.hpp>
#include <OWL/OWL.hpp>
#include <OWL/Time.hpp>
#include <OWL/OpenGL.hpp>

int main(int argc, char** argv) {
	OWL::Window window;
	OWL::SoftwareContext soft;
	// OWL::SoftwareContext soft2;
	OWL::OpenGLContext gl;

	bool contextSoftware = true;
	window.SetContext(soft);

	OWL::FPSLimiter fps(60);

	OWL::Vec2f offset;

	while(window.IsRunning()) {
		window.PollEvents();
		fps.Start();

		printf("X%d Y%d!\n", 
			window.Mouse.GetPosition().x, 
			window.Mouse.GetPosition().y
		);
		printf("L%d M%d R%d B%d F%d Wh%d\n",
			window.Mouse.IsButtonPressed(OWL::Mouse::Left),
			window.Mouse.IsButtonPressed(OWL::Mouse::Middle),
			window.Mouse.IsButtonPressed(OWL::Mouse::Right),
			window.Mouse.IsButtonPressed(OWL::Mouse::Backward),
			window.Mouse.IsButtonPressed(OWL::Mouse::Forward),
			window.Mouse.GetWheelRotation()
		);

		if(window.Mouse.IsButtonPressed(OWL::Mouse::Left)) {
			window.Mouse.SetVisibility(!window.Mouse.IsVisible());
		}

		if(window.Mouse.IsButtonPressed(OWL::Mouse::Middle) || window.Keyboard.GetKeyData().Enum == OWL::Keyboard::F11) {
			window.SetFullScreen(!window.IsFullScreen());
		}

		if(window.Keyboard.IsKeyPressed(OWL::Keyboard::Escape)) {
			window.Close();
		}

		if(window.Mouse.IsButtonPressed(OWL::Mouse::Right)) {
			contextSoftware = !contextSoftware;
			if(contextSoftware) {
				window.SetContext(soft);
			}
			else {
				window.SetContext(gl);
			}
		}

		if(window.Keyboard.IsKeyPressed(OWL::Keyboard::Space)) {
			window.Gamepads.SetCount(0);
		}
		else {
			window.Gamepads.SetCount(1);
		}

		offset = window.Gamepads[0].GetLeftStick();

		if(contextSoftware) {
			soft.SetSize(window.GetSize());

			soft.Clear(OWL::Vec4ub(0, 255, 0, 255));
			soft.BlitToScreen();
		}
		else {
			glViewport(0,0,window.GetSize().x,window.GetSize().y);

			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glBegin(GL_TRIANGLES);
				glColor3f(0.9f, 0.3f, 0.4f);
				glVertex2f(offset.x + -0.5f, offset.y +  -0.5f);
				glColor3f(0.3f, 0.9f, 0.4f);
				glVertex2f(offset.x +  0.0f, offset.y +   0.5f);
				glColor3f(0.3f, 0.4f, 0.9f);
				glVertex2f(offset.x +  0.5f, offset.y +  -0.5f);
			glEnd();

			gl.SwapBuffers();
		}

		fps.End();
	}
	return 0;
}