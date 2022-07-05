#include <OWL/Graphics/SoftwareContext.hpp>

#include "SoftwareContext.hpp"

namespace OWL {

SoftwareContext::SoftwareContext() {
	#if defined OWL_SYSTEM_WINDOWS
		m_Impl = new Impl::WinAPISoftwareContext;
	#elif defined OWL_SYSTEM_LINUX

	#endif
}
SoftwareContext::~SoftwareContext() {
	delete m_Impl;
}


void SoftwareContext::Resize(Vec2ui _newSize) {
	static_cast<Impl::SoftwareContext*>(m_Impl)->Resize(_newSize);
}
Vec2ui SoftwareContext::GetSize() const {
	return static_cast<Impl::SoftwareContext*>(m_Impl)->GetSize();
}

void SoftwareContext::Clear(const Vec4ub& _color = Vec4ub(0)) {
	static_cast<Impl::SoftwareContext*>(m_Impl)->Clear(_color);
}

void SoftwareContext::BlitToScreen() {
	static_cast<Impl::SoftwareContext*>(m_Impl)->BlitToScreen();
}

Vec4ub* SoftwareContext::GetPixelData() {
	return static_cast<Impl::SoftwareContext*>(m_Impl)->GetPixelData();
}

unsigned int SoftwareContext::GetType() const {
	return static_cast<Impl::SoftwareContext*>(m_Impl)->GetType();
}

}