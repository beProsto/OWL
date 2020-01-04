# SoftwareContext
It's a simple class letting you use software (CPU) graphics in your project.
It has 6 functions:
- GetType() - It's a function inherited from `Context` class, that returns an `unsigned int`, which represents this context's type (returns `ContextType_Software` enum's value).
- Resize() - It's a function for resizing the pixel data array.
- GetSize() - Returns the pixel data array's size.
- Clear() - Sets every color of pixel data array to selected color (takes in a `Vec4b`) or black.
- GetPixelData() - returns the pixel data array (in the form of `Vec4b` array)
- BlitToScreen() - Just blit's the pixel data array as an image to the screen. 

__Example of usage:__
```cpp
OWL::SoftwareContext context;
OWL::Window window(&context);

context.Resize(window.GetSize());
context.Clear(OWL::Vec4b(255, 100, 45, 255)); /* Clears the screen in orange color */

for(unsigned int i = 25; i < 50; i++) {
	for(unsigned int j = 60; j < 100; j++) {
		context.GetPixelData()[j*context.GetSize().x+i] = OWL::Vec4b(60, 90, 200, 255); /* Draws a blue rectangle */
	}
}

context.BlitToScreen();
```