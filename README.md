<img align="left" width="64" height="64" style="image-rendering: crisp-edges; image-rendering: pixelated"  src="./docs/logo.png">

## OWL (Open Windowing Library)

OWL is intended to be a simple multiplatform windowing library based on Wayland, Xlib and WinAPI (eventually with Cocoa support in the future).

The plan is for OWL to support Software, OpenGL and Vulkan graphics.

To build the library use either `cmake` or `make`:
```
cmake -B ./build
cmake --build ./build
```
or
```
make 
```

This will result in a `libOWL.dll.a` and `libOWL.dll` / `OWL.lib` and `OWL.dll` library files being created in the `./build/` directory.
Additionally 3 examples (executables) will be compiled along with it.

To turn compiling examples off, set: `BUILD_EXAMPLES` to `NO`. For example like this:
```
cmake -B ./build -DBUILD_EXAMPLES=NO
```
or (with make)
```
make BE=NO
```

To compile as static library, set `LIBTYPE` to `STATIC`. For example like this:
```
cmake -B ./build -DLIBTYPE=STATIC
```
or (with make)
```
make LT=STATIC
```