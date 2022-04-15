# MouseEvent
`MouseEvent` is a subclass of `Window`.
It's used for handling polled mouse events.

It has 6 functions:
- IsButtonPressed() - Takes in an enum of the mouse button you want to check, and returns it's state as a `bool`.
- GetWheelRotation() - Returns the rotation of the mouse wheel as an `int`.
- SetVisibility() - Sets the visibility of the mouse cursor.
- IsVisible() - Returns the visibility of the mouse cursor.
- SetPosition() - Sets the cursor's position in window.
- GetPosition() - Returns the cursor's position in window.
- GetPositionFromEvent() - Returns the cursor's position in window based on mouse motion event (useful if GetPosition() doesn't work like you would like it to).

__Example of usage:__
```cpp
std::cout << "Mouse wheel rotation = " << window.Mouse.GetWheelRotation() << "\n";
std::cout << "Right button state = " << window.Mouse.IsButtonPressed(window.Mouse.Right) << "\n";
std::cout << "Is cursor visible = " << window.Mouse.IsVisible() << "\n";
std::cout << "Mouse position = {" << window.Mouse.GetPosition().x << ", " << window.Mouse.GetPosition().y << "}\n"
```