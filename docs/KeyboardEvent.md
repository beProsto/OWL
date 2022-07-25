# KeyboardEvent
`Keyboard` is an element of `Window`.
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
if(window.Keyboard.GetKeyData().Char != '\b') {
	text += window.Keyboard.GetKeyData().Char;
}
else {
	text.resize(text.size() - 1);
}

std::cout << "Is F1 key pressed: (" << window.Keyboard.IsKeyPressed(OWL::Keyboard::F1) << ")\n";
std::cout << "Key pressed: {" << window.Keyboard.GetKeyData().Char << "}\n";
std::cout << "Text written: {" << text << "}\n"; 
```