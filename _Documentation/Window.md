# Window
`OWL::Window` is the most complicated class in the project, most likely because of the fact that it contains a couple of other classes in itself and it also handles all the events. This document is only about how to construct a window, and about the functions in it.

When creating the `Window`, the only thing it has to take in, is a pointer to the graphical `Context` that you want to use for graphics in your window.

__Example:__
```cpp
OWL::SoftwareContext context;
OWL::Window window(&context);
```

`Window` class has these public functions:
- SetEventLoopType() - Sets the `EventLoopType` used for polling events to `EventLoop` or `GameLoop`.
- GetEventLoopType() - Returns the `EventLoopType` used for polling events.
- PollEvents() - Polls every needed event, using the event loop type chosen as `EventLoopType`.
- SetPosition() - Sets windows position on screen.
- GetPosition() - Returns windows position on screen.
- SetSize() - Sets the size of window.
- GetSize() - Returns windows size.
- SetTitle() - Sets the title of the window.
- GetTitle() - Returns the title of the window.
- Close() - Closes the window.
- IsRunning() - Returns true if the window is running - false otherwise.
- SetFullScreen() - Sets the fullscreen mode.
- IsFullScreen() - Returns true, if the window is fullscreen - false otherwise.
- SetMaxGamepads() - Sets the maximum number of connected gamepads.
- GetMaxGamepads() - Returns the maximum number of connected gamepads.

`Window` class has these public variables:
- Mouse - instance of MouseEvent, contains polled mouse event data. 
- Keyboard - instance of KeyboardEvent, contains polled keyboard event data.
- Gamepad - # instances of GamepadEvent, contains polled gamepad event data. (# means the maximum number of connected gamepads. See SetMaxGamepads() and GetMaxGamepads() functions.)