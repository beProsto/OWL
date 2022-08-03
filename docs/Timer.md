# Timer
Timer class is used to measure how much time passed between two points in our program.

It has 3 functions:
- `start()` - Starts measuring the time.
- `end()` - Ends measuring the time.
- `getDeltaTime()` - Returns the time in seconds.

__Example of usage:__
```cpp
OWL::Timer helloTimer;

helloTimer.start();
// do things
helloTimer.end();

std::cout << "It took " << helloTimer.getDeltaTime() << " seconds to do things.\n";
```