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
	Window();
	~Window();

	void PollEvents();

	// void SetContext(Graphics::Context& _context);
	// Graphics::Context& GetContext();

	void SetPosition(const Vec2<int>& _position);
	Vec2<int> GetPosition() const;

	void SetSize(const Vec2<unsigned int>& _size);
	Vec2<unsigned int> GetSize() const;
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