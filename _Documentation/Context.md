# Context
The context class is abstractional, let's say. It's just an interface, based on which we are making other classes, that are actually designed to do something. See `SoftwareContext` and `GLContext`. It's made for us to create graphical context's.
- It doesn't contain any variables
- It contains two virtual functions
	- GetType() - returns an unsigned int that represents the type of the context. It's `public`.
	- Create() - returns a bool that represents if the context was created. It's `protected` (usable only by `Window` class)

If we want to create a custom graphical context, we have to create a class for it. That class has to inherit from from `OWL::Context`.

__Example: (X11)__
```cpp

class MyContext: public OWL::X11::Context {
public:
	MyContext() {

	}
	~MyContext() {

	}

public:
	unsigned int GetType() const {
		return ContextType_Unknown;
	}

protected:
	bool Create(::Display* _display, int* _screenID, ::Window* _section, const Vec2<int>& _position, const Vec2<unsigned int>& _size) {
		/* In this function we have to not only create our context, but also we have to create the window */
		return false;
	}

	friend class Window;
};
```
