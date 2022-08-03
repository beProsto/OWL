# OpenGLContext
It's a simple class letting you use OpenGL (GPU) graphics in your project.
It has 1 function:
- `swapBuffers()` - It's a function that swaps main OpenGL frame buffer with the one used by our window.

__Example of usage:__
```cpp
OWL::Window window;
OWL::OpenGLContext context;
window.setContext(context);

glclearColor(1.0f, 0.0f, 0.0f, 1.0f); 
glclear(GL_COLOR_BUFFER_BIT);
/* clears the main buffer with red color */

context.swapBuffers(); 
/* swaps the main buffer with the buffer used by window */
```