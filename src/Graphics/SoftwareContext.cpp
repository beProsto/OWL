#include <OWL/Graphics/SoftwareContext.hpp>

#include "SoftwareContext.hpp"

namespace OWL {

SoftwareContext::SoftwareContext() {
	#if defined OWL_SYSTEM_WINDOWS
		m_impl = new Impl::WinAPISoftwareContext;

	#elif defined OWL_SYSTEM_LINUX
		m_impl = new Impl::X11SoftwareContext;

	#endif
}
SoftwareContext::~SoftwareContext() {
	delete m_impl;
}


void SoftwareContext::setSize(Vec2ui _newSize) {
	static_cast<Impl::SoftwareContext*>(m_impl)->setSize(_newSize);
}
Vec2ui SoftwareContext::getSize() const {
	return static_cast<Impl::SoftwareContext*>(m_impl)->getSize();
}

void SoftwareContext::clear(const Vec4ub& _color) {
	static_cast<Impl::SoftwareContext*>(m_impl)->clear(_color);
}

void SoftwareContext::blitToScreen() {
	static_cast<Impl::SoftwareContext*>(m_impl)->blitToScreen();
}

Vec4ub* SoftwareContext::getPixelData() {
	return static_cast<Impl::SoftwareContext*>(m_impl)->getPixelData();
}

}