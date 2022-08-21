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
// Include OWL
#include <OWL/OWL.hpp>
// Include OWL's timer and fps limiter 
#include <OWL/Time.hpp>
// Tell OWL that this is the main file
#include <OWL/Main.hpp>

int main(int argc, char** argv) {
	// First we create a window
	OWL::Window window;
	// We give the window a graphics context
	OWL::SoftwareContext context;
	window.setContext(context);
	// We set the fps limit to 60
	OWL::FPSLimiter fps(60);

	// The main loop
	while(window.isRunning()) {
		fps.start();
		
		// Update all window-related events
		window.pollEvents();
		
		// Toggle fullscreen when pressing F11
		if(window.keyboard.getKeyData().keyEnum == window.keyboard.F11) {
			window.setFullScreen(!window.isFullScreen());
		}
		// If the user pressed Escape, close the window
		if(window.keyboard.isKeyPressed(window.keyboard.Escape)) {
			window.close();
		}

		// Resize the context approprietly to the window's size
		context.setSize(window.getSize());
		// Clear the screen with an orange color
		context.clear(OWL::Vec4ub(255, 100, 45, 255)); 

		// Blit the generated image to the screen
		context.blitToScreen();

		fps.end();
	}

	return 0;
}
```

## Compiling:
This depends on your Operating system. Right now only Linux and Windows are supported.
The recommended way to compile OWL is through `CMake`. 
The `CMakeLists.txt` file is in the main directory of the project, along with a `Makefile` for the ones that want to do it the easy way.

To compile using the helper Makefile, you just use make:
```
make 
```
You can also compile directly with CMake:
```
cmake -B ./build
cmake --build ./build
```

OWL should build to a dynamic library (`libOWL.so` on linux / `libOWL.dll` or `OWL.dll` on windows, depending on your compiler).
There should also be a couple of executables in the build directory, these are the examples. They showcase OWL's capabilities.