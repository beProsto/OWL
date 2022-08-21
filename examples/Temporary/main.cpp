#include <OWL/Main.hpp>
#include <OWL/OWL.hpp>
#include <OWL/Time.hpp>
#include <OWL/OpenGL.hpp>

#include <iostream>
#include <string>

// #include <SDL2/SDL.h>
// #include <emscripten/html5.h>

// class AppBoiler {
// public:
// 	AppBoiler() {

// 	}
// 	virtual ~AppBoiler() {

// 	}

// 	virtual void start() {

// 	}
// 	virtual bool Update(double time) {
// 		return true;
// 	}

// protected:
// 	virtual void Init() {
// 		SDL_Init(SDL_INIT_VIDEO);

// 		start();

// 		#ifdef OWL_SYSTEM_EMSCRIPTEN
// 			emscripten_set_main_loop([]() { AppBoiler::m_App->Update(0.0); }, 60, 1);
// 		#else
// 			while(Update());
// 		#endif
// 	}

// 	static AppBoiler* m_App;
// };
// AppBoiler* AppBoiler::m_App = nullptr;

// class App: public AppBoiler {
// public:
// 	App() {
// 		AppBoiler::m_App = this;
// 		Init();
// 	}
// 	virtual ~App() {

// 	}

// 	virtual void start() {
// 		SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);

// 		SDL_SetRenderDrawColor(renderer, /* RGBA: green */ 0x00, 0x80, 0x00, 0xFF);
// 		SDL_Rect rect = {.x = 10, .y = 10, .w = 50, .h = 50};
// 		SDL_RenderFillRect(renderer, &rect);
// 		SDL_RenderPresent(renderer);
// 	}
// 	virtual bool Update(double time) {
// 		SDL_Event event;
// 		SDL_PollEvent(&event);
// 		if (event.type == SDL_QUIT) {
// 			return false;
// 		}
// 		if (movex < width) 
// 			movex += 1;
// 		else movex = 0;

// 		SDL_Rect rect = {.x = movex, .y = 0, .w = 50, .h = 50};
// 		SDL_RenderFillRect(renderer, &rect);
// 		SDL_RenderPresent(renderer);

// 		return true;
// 	}

// protected:
// 	int width = 100;
// 	int height = 100;
// 	int movex;
// 	SDL_Window *window;
// 	SDL_Renderer *renderer;
// };

int main(int argc, char** argv) {
	printf("Hello, Temporary!\n");

	OWL::Timer time;
	OWL::FPSLimiter fps(10);
	fps.start();
	time.start();
	printf("Process\n");
	fps.end();
	time.end();
	printf("It took %f secs!\n", time.getDeltaTime());


	OWL::Window window;
	printf("EA szzorts \n");
	
	OWL::SoftwareContext sc;
	OWL::OpenGLContext gl;

	window.setContext(sc);

	bool cont = false;

	
	std::wstring text;

	while(window.isRunning()) {
		fps.start();
		window.pollEvents();

		if(window.keyboard.isKeyPressed(OWL::Keyboard::Escape)) {
			window.close();
		}

		if(window.keyboard.isKeyPressed(OWL::Keyboard::A)) {
			printf("A pressed\n");
			window.setPosition(OWL::Vec2i(150, 500));
		}
		if(window.keyboard.isKeyPressed(OWL::Keyboard::B)) {
			printf("B pressed\n");
			window.setSize(OWL::Vec2ui(150, 500));
		}

		if(window.keyboard.getKeyData().keyChar == 's') {
			printf("S pressed\n");
			window.mouse.setVisibility(!window.mouse.isVisible());
		}

		if(window.keyboard.getKeyData().keyChar == 'g') {
			cont = !cont;
			if(cont) window.setContext(gl);
			else window.setContext(sc);
		}

		if(!cont) {
			sc.setSize(window.getSize());
			sc.clear(OWL::Vec4ub(255, 255, 0, 255));
			sc.blitToScreen();
		}
		else {
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			gl.swapBuffers();
		}

		if(window.keyboard.getKeyData().keyChar != '\0') {
			text += window.keyboard.getKeyData().keyChar;
			std::wcout << text << std::endl;
		}

		if(window.keyboard.isKeyPressed(OWL::Keyboard::C)) {
			printf("C %d : %d\n", window.getPosition().x, window.getPosition().y);
		}
		if(window.keyboard.isKeyPressed(OWL::Keyboard::D)) {
			printf("D %d : %d\n", window.getSize().x, window.getSize().y);
		}

		if(window.keyboard.getKeyData().keyEnum == OWL::Keyboard::F11) {
			window.setFullScreen(!window.isFullScreen());
		}

		if(window.keyboard.isKeyPressed(OWL::Keyboard::Space)) {
			printf("M: X=%d Y=%d W=%d\n", window.mouse.getPosition().x, window.mouse.getPosition().y, window.mouse.getWheelRotation());
			printf("L(%d)M(%d)R(%d)F(%d)B(%d)\n", 
				window.mouse.isButtonPressed(OWL::Mouse::Left),
				window.mouse.isButtonPressed(OWL::Mouse::Middle),
				window.mouse.isButtonPressed(OWL::Mouse::Right),
				window.mouse.isButtonPressed(OWL::Mouse::Forward),
				window.mouse.isButtonPressed(OWL::Mouse::Backward)
			);
		}
		if(!window.isFocused()) {
			printf("unfocused :c\n");
		}

	// 	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	// 	glClear(GL_COLOR_BUFFER_BIT);

	// 	gl.swapBuffers();

		fps.end();
	}
	
	return 0;
}