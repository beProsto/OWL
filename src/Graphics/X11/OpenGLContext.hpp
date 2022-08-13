#pragma once

#include "../OpenGLContext.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Linux.hpp>

#include <OWL/OS/OpenGL.hpp>

namespace OWL {
namespace Impl {
class OWL_API X11OpenGLContext: public OpenGLContext {
public:
	X11OpenGLContext() {

	}
	virtual ~X11OpenGLContext() {

	}

	virtual bool create()  {
		return true;
	}
	virtual bool validate() {

		// m_visualInfo->visual = DefaultVisual(static_cast<X11Window*>(m_windowImpl)->m_display, static_cast<X11Window*>(m_windowImpl)->m_screenID);
		
		XMatchVisualInfo(static_cast<X11Window*>(m_windowImpl)->m_display, static_cast<X11Window*>(m_windowImpl)->m_screenID, 32, 0, m_visualInfo);
		
		m_glXContext = glXCreateContext(static_cast<X11Window*>(m_windowImpl)->m_display, m_visualInfo, 0, true);
		glXMakeCurrent(static_cast<X11Window*>(m_windowImpl)->m_display, static_cast<X11Window*>(m_windowImpl)->m_window, m_glXContext);

		return true;
	}

	virtual void destroy() {

	}

	virtual OpenGLLoaderFunction getLoaderFunction() {
		return [](const char* name) {
			void *p = (void*)glXGetProcAddress((unsigned char*)name);
			return p;
		};
	}
	virtual void swapBuffers() {

	}

public:
	::XVisualInfo* m_visualInfo;
	bool m_Created;

	::GLXContext m_glXContext;

};
}
}