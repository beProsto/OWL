#include <OWL/Utility/Config.hpp>

#include <OWL/System/Window.hpp>

#include "Window.hpp"

namespace OWL {

Window::Window(Vec2ui _size, std::string _title) {
	#if defined OWL_SYSTEM_WINDOWS
		m_Impl = new Impl::WinAPIWindow(_size, _title, Mouse.m_Impl);
	#elif defined OWL_SYSTEM_LINUX
		
	#endif
}

Window::~Window() {
	delete m_Impl;
}

void Window::PollEvents() {
	m_Impl->PollEvents();
}

void Window::SetContext(Context& _context) {
	m_Impl->SetContext(*_context.m_Impl);
}

void Window::SetPosition(const Vec2i& _position) {
	m_Impl->SetPosition(_position);
}
Vec2i Window::GetPosition() const {
	return m_Impl->GetPosition();
}

void Window::SetSize(Vec2ui _size) {
	m_Impl->SetSize(_size);
}
Vec2ui Window::GetSize() const {
	return m_Impl->GetSize();
}
float Window::GetAspect() const {
	return m_Impl->GetAspect();
}

void Window::SetTitle(std::string _title) {
	m_Impl->SetTitle(_title);
}
std::string Window::GetTitle() const {
	return m_Impl->GetTitle();
}

void Window::Close() {
	m_Impl->Close();
}
bool Window::IsRunning() const {
	return m_Impl->IsRunning();
}

bool Window::IsFocused() const {
	return m_Impl->IsFocused();
}

void Window::SetFullScreen(bool _fullScreen) {
	m_Impl->SetFullScreen(_fullScreen);
}
bool Window::IsFullScreen() const {
	return m_Impl->IsFullScreen();
}

}