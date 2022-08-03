#include <OWL/Input/Mouse.hpp>

#include "Mouse.hpp"

namespace OWL {

Mouse::Mouse() {
	#if defined OWL_SYSTEM_WINDOWS
		m_impl = new Impl::WinAPIMouse;
	#elif defined OWL_SYSTEM_LINUX

	#endif
}
Mouse::~Mouse() {
	delete m_impl;
}

void Mouse::SetVisibility(bool _visible) {
	m_impl->SetVisibility(_visible);
}
bool Mouse::IsVisible() const {
	return m_impl->IsVisible();
}

void Mouse::setPosition(const Vec2i& _position) {
	m_impl->setPosition(_position);
}
Vec2i Mouse::getPosition() const {
	return m_impl->getPosition();
}

int Mouse::GetWheelRotation() const {
	return m_impl->GetWheelRotation();
}

bool Mouse::isButtonPressed(unsigned int _button) const {
	return m_impl->isButtonPressed(_button);
}


}