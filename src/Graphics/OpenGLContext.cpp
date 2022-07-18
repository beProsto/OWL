#include <OWL/Graphics/OpenGLContext.hpp>

#include "OpenGLContext.hpp"

namespace OWL {

OpenGLContext::OpenGLContext() {
	#if defined OWL_SYSTEM_WINDOWS
		m_Impl = new Impl::WinAPIOpenGLContext;
	#elif defined OWL_SYSTEM_LINUX

	#endif
}
OpenGLContext::~OpenGLContext() {
	delete m_Impl;
}

void OpenGLContext::SwapBuffers() {
	static_cast<Impl::OpenGLContext*>(m_Impl)->SwapBuffers();
}

}