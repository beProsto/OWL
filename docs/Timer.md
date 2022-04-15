# Timer
Timer class is used to measure how much time passed between two points in our program.

It has 3 functions:
- Start - Starts measuring the time.
- End - Ends measuring the time.
- GetDeltaTime - Returns the time in seconds.

__Example of usage:__
```cpp
OWL::Timer helloTimer;

helloTimer.Start();
// do things
helloTimer.End();

std::cout << "It took " << helloTimer.GetDeltaTime() << " seconds to do things.\n";
```