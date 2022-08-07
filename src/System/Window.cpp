#include <OWL/Utility/Config.hpp>

#include <OWL/System/Window.hpp>

#include "Window.hpp"

namespace OWL {

Window::Window(Vec2ui _size, std::string _title) {
	#if defined OWL_SYSTEM_WINDOWS
		m_impl = new Impl::WinAPIWindow(_size, _title, keyboard.m_impl, mouse.m_impl, gamepads.m_impl);
	#elif defined OWL_SYSTEM_LINUX
		m_impl = new Impl::X11Window(_size, _title, keyboard.m_impl, mouse.m_impl, gamepads.m_impl);
	#endif
}

Window::~Window() {
	delete m_impl;
}

void Window::pollEvents() {
	m_impl->pollEvents();
}

void Window::setContext(Context& _context) {
	m_impl->setContext(*_context.m_impl);
}

void Window::setPosition(const Vec2i& _position) {
	m_impl->setPosition(_position);
}
Vec2i Window::getPosition() const {
	return m_impl->getPosition();
}

void Window::setSize(Vec2ui _size) {
	m_impl->setSize(_size);
}
Vec2ui Window::getSize() const {
	return m_impl->getSize();
}
float Window::getAspect() const {
	return m_impl->getAspect();
}

void Window::setTitle(std::string _title) {
	m_impl->setTitle(_title);
}
std::string Window::getTitle() const {
	return m_impl->getTitle();
}

void Window::close() {
	m_impl->close();
}
bool Window::isRunning() const {
	return m_impl->isRunning();
}

bool Window::isFocused() const {
	return m_impl->isFocused();
}

void Window::setFullScreen(bool _fullScreen) {
	m_impl->setFullScreen(_fullScreen);
}
bool Window::isFullScreen() const {
	return m_impl->isFullScreen();
}

}