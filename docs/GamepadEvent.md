# Gamepads
`Gamepads` is an element of `Window`.
It's used for handling polled gamepads' events.

It has 2 functions:
- `SetCount()` - Takes in an unsigned integer and sets how many gamepads can the app use at once.
- `GetCount()` - Returns how many gamepads can the app use at once as an `unsigned int`.
- `operator[]` - Takes in the index of the gamepad we want to reference, and returns said gamepad.
	- `Gamepad` object has these public functions:
		- `GetLeftStick()` - Returns the left stick's state as a `Vec2<float>`.
		- `GetRightStick()` - Returns the right stick's state as a `Vec2<float>`.
		- `GetLeftTrigger()` - Returns the state of the left trigger as a `float`.
		- `GetRightTrigger()` - Returns the state of the right trigger as a `float`.
		- `IsConnected()` - Returns the state of being connected as a `bool`.
		- `IsButtonPressed()` - Takes in the button you want to check, and returns it's state as a `bool`.
			- The buttons available are based on the XBOX360 controller layout:
				- `A`
				- `B`
				- `X`
				- `Y`
				- `Start`
				- `Back`
				- `ShoulderLeft`
				- `ShoulderRight`
				- `ThumbLeft`
				- `ThumbRight`
				- `DPadUp`
				- `DPadDown`	
				- `DPadLeft`
				- `DPadRight`
				- `Logo`

__Example of usage:__
```cpp
std::cout << "Left Stick State = {" << window.Gamepads[0].GetLeftStick().x << ", " <<  window.Gamepads[0].GetLeftStick().y << "}\n";
std::cout << "Left Trigger State = " << window.Gamepads[0].GetLeftTrigger() << "\n";
std::cout << "Right Shoulder Button's State = " << window.Gamepads[0].IsButtonPressed(OWL::Gamepad::ShoulderLeft) << "\n";
std::cout << "There are " << window.Gamepads.GetCount() << " maximum controllers to plug in.\n";
```