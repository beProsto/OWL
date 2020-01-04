# GLContext
It's a simple class letting you use OpenGL (GPU) graphics in your project.
It has 2 functions:
- GetType() - It's a function inherited from `Context` class, that returns an `unsigned int`, which represents this context's type (returns `ContextType_OpenGL` enum's value).
- SwapBuffers() - It's a function that swaps main OpenGL frame buffer with the one used by our window.

__Example of usage:__
```cpp
OWL::GLContext context;
OWL::Window window(&context);

glClearColor(1.0f, 0.0f, 0.0f, 1.0f); 
glClear(GL_COLOR_BUFFER_BIT);
/* clears the main buffer with red color */

context.SwapBuffers(); 
/* swaps the main buffer with the buffer used by window */
```