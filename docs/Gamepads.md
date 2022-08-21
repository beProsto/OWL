# Gamepads
`gamepads` is an element of `Window`.
It's used for handling polled gamepads' events.

It has 2 functions:
- `setCount()` - Takes in an unsigned integer and sets how many gamepads can the app use at once.
- `getCount()` - Returns how many gamepads can the app use at once as an `unsigned int`.
- `operator[]` - Takes in the index of the gamepad we want to reference, and returns said gamepad.
	- `Gamepad` object has these public functions:
		- `getLeftStick()` - Returns the left stick's state as a `Vec2<float>`.
		- `getRightStick()` - Returns the right stick's state as a `Vec2<float>`.
		- `getLeftTrigger()` - Returns the state of the left trigger as a `float`.
		- `getRightTrigger()` - Returns the state of the right trigger as a `float`.
		- `isConnected()` - Returns the state of being connected as a `bool`.
		- `isButtonPressed()` - Takes in the button you want to check, and returns it's state as a `bool`.
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
std::cout << "Left Stick State = {" << window.gamepads[0].getLeftStick().x << ", " <<  window.gamepads[0].getLeftStick().y << "}\n";
std::cout << "Left Trigger State = " << window.gamepads[0].getLeftTrigger() << "\n";
std::cout << "Right Shoulder Button's State = " << window.gamepads[0].isButtonPressed(OWL::Gamepad::ShoulderLeft) << "\n";
std::cout << "There are " << window.gamepads.getCount() << " maximum controllers to plug in.\n";
```