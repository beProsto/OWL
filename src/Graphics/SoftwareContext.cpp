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


void Resize(const Vec2ui& _newSize);
const Vec2ui& GetSize() const;

void Clear(const Vec4ub& _color = Vec4ub(0));

void BlitToScreen();

Vec4ub* GetPixelData();

unsigned int GetType() const;

}