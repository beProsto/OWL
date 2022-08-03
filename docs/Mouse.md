# mouse
`mouse` is an element of `Window`.
It's used for handling mouse events.

It has 6 functions:
- `isButtonPressed()` - Takes in an enum of the mouse button you want to check, and returns it's state as a `bool`.
- `getWheelRotation()` - Returns the rotation of the mouse wheel as an `int`.
- `SetVisibility()` - Sets the visibility of the mouse cursor.
- `IsVisible()` - Returns the visibility of the mouse cursor.
- `setPosition()` - Sets the cursor's position in window.
- `getPosition()` - Returns the cursor's position in window.

__Example of usage:__
```cpp
std::cout << "mouse wheel rotation = " << window.mouse.getWheelRotation() << "\n";
std::cout << "Right button state = " << window.mouse.isButtonPressed(window.mouse.Right) << "\n";
std::cout << "Is cursor visible = " << window.mouse.IsVisible() << "\n";
std::cout << "mouse position = {" << window.mouse.getPosition().x << ", " << window.mouse.getPosition().y << "}\n"
```