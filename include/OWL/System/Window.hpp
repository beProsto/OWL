#pragma once

#include <OWL/Utility/Config.hpp>
#include <OWL/Utility/Vec2.hpp>
#include <string>

#include <OWL/Input/Mouse.hpp>
#include <OWL/Input/Keyboard.hpp>
#include <OWL/Input/Gamepad.hpp>

#include <OWL/Graphics/Context.hpp>

namespace OWL {

namespace Impl {
class OWL_API Window;
}

class OWL_API Window {
public:
	Window(Vec2ui _size = Vec2ui(640, 360), std::string _title = "beProsto.github.io/OWL");
	~Window();

	void pollEvents();

	void setContext(Context& _context);
	
	void setPosition(const Vec2i& _position);
	Vec2i getPosition() const;

	void setSize(Vec2ui _size);
	Vec2ui getSize() const;
	float getAspect() const;

	void setTitle(std::string _title);
	std::string getTitle() const;

	void close();
	bool isRunning() const;

	bool isFocused() const;

	void setFullScreen(bool _fullScreen);
	bool isFullScreen() const;

public:
	Mouse mouse;
	Keyboard keyboard;
	Gamepads gamepads;

private:
	Impl::Window* m_impl;
};

}