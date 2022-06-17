<img align="left" width="64" height="64" style="image-rendering: crisp-edges; image-rendering: pixelated"  src="./docs/logo.png">

## OWL (Open Windowing Library)

OWL is intended to be a simple, multiplatform windowing library, based on Xlib, WinAPI and (maybe) Cocoa.

OWL will of course support Direct3D, OpenGL and Vulkan. :D

*Supports:*
- Xlib
	- Software graphics
	- OpenGL graphics
- WinAPI
	- Software graphics
	- OpenGL graphics

To build the library use either `cmake` or `make`:
```
cmake -B ./build
cmake --build ./build
```
or
```
make 
```
This will result in a `libOWL.a` / `OWL.lib` library file being created in the `./build/` directory.
Additionally 3 examples (executables) will be compiled along with it.

To turn compiling examples off, set: `BUILD_EXAMPLES` to `NO`. For example like this:
```
cmake -B ./build -DBUILD_EXAMPLES=NO
```
