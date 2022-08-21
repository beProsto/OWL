#include <OWL/Graphics/OpenGLContext.hpp>

#include "OpenGLContext.hpp"

namespace OWL {

OpenGLContext::OpenGLContext() {
	#if defined OWL_SYSTEM_WINDOWS
		m_impl = new Impl::WinAPIOpenGLContext;

	#elif defined OWL_SYSTEM_LINUX
		m_impl = new Impl::X11OpenGLContext;

	#endif
}
OpenGLContext::~OpenGLContext() {
	delete m_impl;
}

OpenGLLoaderFunction OpenGLContext::getLoaderFunction() {
	return static_cast<Impl::OpenGLContext*>(m_impl)->getLoaderFunction();
}
void OpenGLContext::swapBuffers() {
	static_cast<Impl::OpenGLContext*>(m_impl)->swapBuffers();
}

}