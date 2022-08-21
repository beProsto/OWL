<img align="left" width="100" height="100" style="image-rendering: crisp-edges; image-rendering: pixelated"  src="./logo.png">

## OWL (Open Windowing Library)

This is ought to be the complete guide to setting OWL up.

If you have *any* problems setting it up, please [notify me by creating a github issue](https://github.com/beProsto/OWL/issues/new).


## Using OWL:
Using the library should be rather straight forward, just download, check out the [examples](https://github.com/beProsto/OWL/tree/main/examples), or follow along this setup tutorial. :D

## Downloading OWL:
You can do it with `git` like this:
```
git clone https://github.com/beProsto/OWL
```
Or you can simply download the repository by going [here](https://github.com/beProsto/OWL), then pressing `Code` -> `Download ZIP`.

## Creating and Compiling a simple application:
In this section I'll give you a tour around creating and compiling your own simple OWL application

## Project layout:
You can layout your project in any way you'd like, just remember to put the include/ directory of OWL as one of the include directories for your project.

## Creating the main source file:
Just create a simple `main.cpp` or any other way you'd like to call it;

## Filling main.cpp up:
We'll just make it a simple "Hello, World!" window.
```cpp
// Include OWL and Timing (fps limiter and timer)
#include <OWL/OWL.hpp>
#include <OWL/time.hpp>

// This is how a Main function looks like with OWL
int main(int argc, char** argv) {
	// We create a simple OWL window.
	OWL::Window window;
	// We define a software context
	// That means it is ought to draw 
	// using the CPU rather than the GPU.
	OWL::SoftwareContext context;
	// We set the window to use this context.
	window.setContext(context);

	// We create an FPS limiter, it will limit the app's performance 
	// to the given ammount of frames per second.
	OWL::FPSLimiter fps(60);

	// This is the main loop, our programme's every step is defined here.
	while(window.isRunning()) {
		// At the start of every frame we check for any new events.
		window.pollEvents();
		// Update the fps limiter.
		fps.start();

		// If the user presses F11, we toggle fullscreen.
		if(window.keyboard.getKeyData().enum == OWL::keyboard::F11) {
			window.setFullScreen(!window.isFullScreen());
		}
		// If the user presses Escape, we close the app.
		if(window.keyboard.isKeyPressed(OWL::keyboard::Escape)) {
			window.close();
		}

		// We want our context to fit exactly to the window.
		context.setSize(window.getSize());
		// We clear our context's canvas with a given RGBA colour.
		context.clear(OWL::Vec4ub(255, 100, 45, 255)); /* clears the screen in orange color */

		// We blit the context (put the context's image) to the screen.
		context.blitToScreen();
		// Update the fps limiter.
		fps.end();
	}

	return 0;
}
```

Who's to say that we can't have some fun with it, like for instance, put a square on the screen;
```cpp
// Draws a blue rectangle 
for(unsigned int i = 25; i < min(50, context.getSize().x); i++) {
	for(unsigned int j = 60; j < min(170, context.getSize().y); j++) {
		// Draws a blue pixel
		context.getPixelData()[j*context.getSize().x+i] = OWL::Vec4b(60, 90, 200, 255); 
	}
}
```

If we put thios bunch of code right after clearing the screen, a rectangle should be visible after compiling! :D

## Compiling:
This depends on your Operating system. Right now only Linux and Windows are supported.

This will tell you which libraries you should link depending on your os and needs:
- If on linux:
	- `-lX11`
	- If using OpenGL
		- `-lGL` 
		- `-lGLX`
- If on windows:
	- If using OpenGL
		- `-lopengl32`
		- `-lglu32`
	- `-lgdi32`
	- `-luser32`
	- `-lcomctl32`
	- `-lkernel32`
	- `-lshell32`
	- `-lxinput`
- If on mac:
	- (For now unsupported)

### We also need to add the OWL include directory as one of our include directories:
`-I./OWL/include`

### How the final compilation command should look on linux:
`clang++ main.cpp -I./OWL/include -lX11 -lGL -lGLX -std=c++17 -o app`
### How the final compilation command should look on windows:
`clang++ main.cpp -I./OWL/include -lopengl32 -lglu32 -lgdi32 -luser32 -lcomctl32 -lkernel32 -lshell32 -lxinput -std=c++17 -o app.exe`

Please note that you can of course swap clang here for any other C++ compiler. :D

With all this done, a new executable named `app` should be created and ready for you to see if it works!