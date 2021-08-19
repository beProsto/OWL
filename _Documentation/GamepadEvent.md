# GamepadEvent
`GamepadEvent` is a subclass of `Window`.
It's used for handling polled gamepad events.

It has 5 functions:
- IsButtonPressed() - Takes in an index of the button you want to check, and returns it's state as a `bool`.
- GetButtonsAmmount() - Returns the ammount of buttons on the gamepad as an `unsigned int`.
- GetLeftStick() - Returns the left stick's state as a `Vec2<float>`.
- GetRightStick() - Returns the right stick's state as a `Vec2<float>`.
- GetLeftTrigger() - Returns the state of the left trigger as a `float`.
- GetRightTrigger() - Returns the state of the right trigger as a `float`.
- IsConnected() - Returns the state of being connected as a `bool`.

__Example of usage:__
```cpp
std::cout << "Left Stick State = {" << window.Gamepad[0].GetLeftStick().x << ", " <<  window.Gamepad[0].GetLeftStick().y << "}\n";
std::cout << "Left Trigger State = " << window.Gamepad[0].GetLeftTrigger() << "\n";
std::cout << "Button[0] State = " << window.Gamepad[0].IsButtonPressed(0) << "\n";
std::cout << "There are " << window.Gamepad[0].GetButtonsAmmount() << " buttons on the gamepad.\n";
```