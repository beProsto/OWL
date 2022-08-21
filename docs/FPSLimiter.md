# FPSLimiter
FPSLimiter is a class used to limit frames per second in our program.

It has 3 functions:
- `setDesiredFPS()` - It takes in the ammount of desired frames per second, then sets that to be the limit.
- `start()` - It starts measuring how mush time passes in the frame.
- `end()` - It ends measuring, calculates how much time passed during frame and delays the next one if needed.

__Example of usage:__
```cpp
// before main loop
OWL::FPSLimiter fps;
fps.setDesiredFPS(60);

// at the start of the main loop, after polling the events (OWL::Window::pollEvents())
fps.start();

// at the end of main loop, after finishing the drawing
fps.end();
```