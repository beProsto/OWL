#pragma once

#include <OWL/Utility/Config.hpp>

#include "../Window.hpp"

#include <iostream>

namespace OWL {
namespace Impl {

class OWL_API WinAPIWindow: public Window {
public:
	WinAPIWindow(Vec2ui _size, std::string _title) {
		std::cout << "Created WinAPI window!\n";
		m_Title = _title;
	}
	virtual ~WinAPIWindow() {
		std::cout << "Destructed WinAPI window!\n";
	}

	virtual void PollEvents() {

	}

	virtual void SetPosition(const Vec2i& _position) {

	}
	virtual Vec2i GetPosition() const {
		return Vec2i{};
	}

	virtual void SetSize(const Vec2ui& _size) {

	}
	virtual Vec2ui GetSize() const {
		return Vec2ui{};
	}
	virtual float GetAspect() const {
		return float{};
	}

	virtual void SetTitle(const std::string& _title) {

	}
	virtual const std::string& GetTitle() const {
		return m_Title;
	}

	virtual void Close() {

	}
	virtual bool IsRunning() const {
		return false;
	}

	virtual bool IsFocused() const {
		return false;
	}

	virtual void SetFullScreen(bool _fullScreen) {

	}
	virtual bool IsFullScreen() const {
		return false;
	}

public:
	std::string m_Title;
};

}
}