# Window
`OWL::Window` is the class that constructs a window for us, initiates a graphics context in it and containt the `keyboard`, `mouse` and `gamepads` elements.

When creating the `Window`, it doesn't need any parameters:

__Example:__
```cpp
OWL::Window window;
```

`Window` class has these public functions:
- `pollEvents()` - Polls every needed event, using the event loop type chosen as `EventLoopType`.
- `setPosition()` - Sets windows position on screen.
- `getPosition()` - Returns windows position on screen.
- `setSize()` - Sets the size of window.
- `getSize()` - Returns windows size.
- `setTitle()` - Sets the title of the window.
- `getTitle()` - Returns the title of the window.
- `close()` - Closes the window.
- `isRunning()` - Returns true if the window is running - false otherwise.
- `isFocused()` - Returns true if the window is currently focused - false otherwise.
- `setFullScreen()` - Sets the fullscreen mode.
- `isFullScreen()` - Returns true, if the window is fullscreen - false otherwise.

`Window` class has these public variables:
- `mouse` - instance of Mouse, contains mouse functionality. 
- `keyboard` - instance of Keyboard, contains keyboard functionality.
- `gamepads` - instance of Gamepads, contains gamepad functionality.