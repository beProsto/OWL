# FPSLimiter
FPSLimiter is a class used to limit frames per second in our program.

It has 3 functions:
- SetDesiredFPS() - It takes in the ammount of desired frames per second, then sets that to be the limit.
- Start - It starts measuring how mush time passes in the frame.
- End - It ends measuring, calculates how much time passed during frame and delays the next one if needed.

__Example of usage:__
```cpp
// before main loop
OWL::FPSLimiter fps;
fps.SetDesiredFPS(60);

// at the start of the main loop, after polling the events (OWL::Window::PollEvents())
fps.Start();

// at the end of main loop, after finishing the drawing
fps.End();
```