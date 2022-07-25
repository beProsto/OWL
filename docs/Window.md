# Window
`OWL::Window` is the class that constructs a window for us, initiates a graphics context in it and containt the `Keyboard`, `Mouse` and `Gamepads` elements.

When creating the `Window`, it doesn't need any parameters:

__Example:__
```cpp
OWL::Window window;
```

`Window` class has these public functions:
- `PollEvents()` - Polls every needed event, using the event loop type chosen as `EventLoopType`.
- `SetPosition()` - Sets windows position on screen.
- `GetPosition()` - Returns windows position on screen.
- `SetSize()` - Sets the size of window.
- `GetSize()` - Returns windows size.
- `SetTitle()` - Sets the title of the window.
- `GetTitle()` - Returns the title of the window.
- `Close()` - Closes the window.
- `IsRunning()` - Returns true if the window is running - false otherwise.
- `IsFocused()` - Returns true if the window is currently focused - false otherwise.
- `SetFullScreen()` - Sets the fullscreen mode.
- `IsFullScreen()` - Returns true, if the window is fullscreen - false otherwise.

`Window` class has these public variables:
- `Mouse` - instance of Mouse, contains mouse functionality. 
- `Keyboard` - instance of Keyboard, contains keyboard functionality.
- `Gamepads` - instance of Gamepads, contains gamepad functionality.