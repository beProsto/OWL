# KeyboardEvent
`KeyboardEvent` is a subclass of `Window`.
It's used for handling polled keyboard events.

It has 2 functions:
- IsKeyPressed() - Takes in an enum of the key you want to check, and returns it's state as a `bool`.
- GetKeyData() - Returns the data about pressed key, as a `KeyData`.
	- `KeyData` has 2 members:
		- `std::string` String - contains text data (the key presented as text, for example: Key A = `"A"`, Key Enter = `"\n"`)
		- `unsigned int` KeyEnum - contains the enum of the key

__Example of usage:__
```cpp
/* Before the main loop */
std::string text = "";

/* In the main loop */
if(window.Keyboard.GetKeyData().String != "\b") {
	text += window.Keyboard.GetKeyData().String;
}
else {
	text.resize(text.size() - 1);
}

std::cout << "Is F1 key pressed: (" << window.Keyboard.IsKeyPressed(window.Keyboard.F1) << ")\n";
std::cout << "Key pressed: {" << window.Keyboard.GetKeyData().String << "}\n";
std::cout << "Text written: {" << text << "}\n"; 
```