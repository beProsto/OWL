#include <OWL/Main.hpp>
#include <OWL/OWL.hpp>
#include <OWL/Time.hpp>
#include <OWL/OpenGL.hpp>

#include <SDL2/SDL.h>
#include <emscripten/html5.h>

class AppBoiler {
public:
	AppBoiler() {

	}
	virtual ~AppBoiler() {

	}

	virtual void Start() {

	}
	virtual bool Update(double time) {
		return true;
	}

protected:
	virtual void Init() {
		SDL_Init(SDL_INIT_VIDEO);

		Start();

		#ifdef OWL_SYSTEM_EMSCRIPTEN
			emscripten_set_main_loop([]() { AppBoiler::m_App->Update(0.0); }, 60, 1);
		#else
			while(Update());
		#endif
	}

	static AppBoiler* m_App;
};
AppBoiler* AppBoiler::m_App = nullptr;

class App: public AppBoiler {
public:
	App() {
		AppBoiler::m_App = this;
		Init();
	}
	virtual ~App() {

	}

	virtual void Start() {
		SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);

		SDL_SetRenderDrawColor(renderer, /* RGBA: green */ 0x00, 0x80, 0x00, 0xFF);
		SDL_Rect rect = {.x = 10, .y = 10, .w = 50, .h = 50};
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}
	virtual bool Update(double time) {
		SDL_Event event;
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			return false;
		}
		if (movex < width) 
			movex += 1;
		else movex = 0;

		SDL_Rect rect = {.x = movex, .y = 0, .w = 50, .h = 50};
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);

		return true;
	}

protected:
	int width = 100;
	int height = 100;
	int movex;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

int main(int argc, char** argv) {
	printf("Hello, Temporary!\n");

	App app;

	return 0;
}