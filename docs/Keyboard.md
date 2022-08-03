# KeyboardEvent
`keyboard` is an element of `Window`.
It's used for handling keyboard events.

It has 2 functions:
- `IsKeyPressed()` - Takes in an enum of the key you want to check, and returns it's state as a `bool`.
- `GetKeyData()` - Returns the data about pressed key, as a `KeyData`.
	- `KeyData` has 2 members:
		- `wchar_t` Char - contains text data (the key presented as text, for example: Key A = `'A'`, Key Enter = `'\n'`)
		- `unsigned int` Enum - contains the enum of the key

__Example of usage:__
```cpp
/* Before the main loop */
std::wstring text = "";

/* In the main loop */
if(window.keyboard.GetKeyData().Char != '\b') {
	text += window.keyboard.GetKeyData().Char;
}
else {
	text.resize(text.size() - 1);
}

std::cout << "Is F1 key pressed: (" << window.keyboard.IsKeyPressed(OWL::keyboard::F1) << ")\n";
std::cout << "Key pressed: {" << window.keyboard.GetKeyData().Char << "}\n";
std::cout << "Text written: {" << text << "}\n"; 
```