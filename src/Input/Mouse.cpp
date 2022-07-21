#include <OWL/Input/Mouse.hpp>

#include "Mouse.hpp"

namespace OWL {

Mouse::Mouse() {
	#if defined OWL_SYSTEM_WINDOWS
		m_Impl = new Impl::WinAPIMouse;
	#elif defined OWL_SYSTEM_LINUX

	#endif
}
Mouse::~Mouse() {
	delete m_Impl;
}

void Mouse::SetVisibility(bool _visible) {
	m_Impl->SetVisibility(_visible);
}
bool Mouse::IsVisible() const {
	return m_Impl->IsVisible();
}

void Mouse::SetPosition(const Vec2i& _position) {
	m_Impl->SetPosition(_position);
}
Vec2i Mouse::GetPosition() const {
	return m_Impl->GetPosition();
}

int Mouse::GetWheelRotation() const {
	return m_Impl->GetWheelRotation();
}

bool Mouse::IsButtonPressed(unsigned int _button) const {
	return m_Impl->IsButtonPressed(_button);
}


}