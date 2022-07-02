#pragma once

#include <OWL/Utility/Config.hpp>
#include <OWL/Utility/Vec2.hpp>
#include <string>

// #include <OWL/System/Input/Mouse.hpp>
// #include <OWL/System/Input/Keyboard.hpp>
// #include <OWL/System/Input/Gamepad.hpp>

// #include <OWL/System/Graphics/Context.hpp>

namespace OWL {

namespace Impl {
class OWL_API Window;
}

class OWL_API Window {
public:
	Window(Vec2ui _size = Vec2ui(640, 360), std::string _title = "beprosto.github.io/OWL");
	~Window();

	void PollEvents();

	// void SetContext(Graphics::Context& _context);
	// Graphics::Context& GetContext();

	void SetPosition(const Vec2i& _position);
	Vec2i GetPosition() const;

	void SetSize(const Vec2ui& _size);
	Vec2ui GetSize() const;
	float GetAspect() const;

	void SetTitle(const std::string& _title);
	const std::string& GetTitle() const;

	void Close();
	bool IsRunning() const;

	bool IsFocused() const;

	void SetFullScreen(bool _fullScreen);
	bool IsFullScreen() const;

private:
	Impl::Window* m_Impl;
};

}