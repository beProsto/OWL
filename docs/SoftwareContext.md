# SoftwareContext
It's a simple class letting you use software (CPU) graphics in your project.
It has 5 functions:
- `setSize()` - It's a function for resizing the pixel data array.
- `getSize()` - Returns the pixel data array's size.
- `clear()` - Sets every color of pixel data array to selected color (takes in a `Vec4ub`) or black.
- `getPixelData()` - returns the pixel data array (in the form of `Vec4ub` array)
- `blitToScreen()` - Just blit's the pixel data array as an image to the screen. 

__Example of usage:__
```cpp
OWL::SoftwareContext context;
OWL::Window window;
window.setContext(context);

context.setSize(window.getSize());
context.clear(OWL::Vec4b(255, 100, 45, 255)); /* clears the screen in orange color */

for(unsigned int i = 25; i < 50; i++) {
	for(unsigned int j = 60; j < 100; j++) {
		context.getPixelData()[j*context.getSize().x+i] = OWL::Vec4ub(60, 90, 200, 255); /* Draws a blue rectangle */
	}
}

context.blitToScreen();
```