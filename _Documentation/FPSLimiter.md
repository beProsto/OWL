# FPSLimiter
FPSLimiter is a class used to limit frames per second in our program.

It has 2 functions:
- Start - It starts measuring how mush time passes in the frame.
- End - It ends measuring, calculates how much time passed during frame and delays the next one if needed.

__Example of usage:__
```cpp
// before main loop
OWL::FPSLimiter fps;

// at the start of the main loop, after polling the events (OWL::Window::PollEvents())
fps.Start();

// at the end of main loop, after finishing the drawing
fps.End();
```