#pragma once

#include "../OpenGLContext.hpp"
#include "../../System/Window.hpp"

#include <OWL/System/Info.hpp>
#include <OWL/OS/Linux.hpp>

#include <OWL/OS/OpenGL.hpp>

namespace OWL {
namespace Impl {
#define Win(x) static_cast<X11Window*>(x)

class OWL_API X11OpenGLContext: public OpenGLContext {
public:
	X11OpenGLContext() {

	}
	virtual ~X11OpenGLContext() {

	}

	virtual bool create()  {
		int versionGLX[2] = {0, 0}; /* Order: major[0], minor[1] */ 
		glXQueryVersion(OSInfo::get()->displayX11, &versionGLX[0], &versionGLX[1]);

		// printf("OWL: GLX version: %d.%d\n", versionGLX[0], versionGLX[1]);

		int attribsGLX[] = {
			GLX_RGBA,
			GLX_DOUBLEBUFFER,
			GLX_DEPTH_SIZE,     24,
			GLX_STENCIL_SIZE,   8,
			GLX_RED_SIZE,       8,
			GLX_GREEN_SIZE,     8,
			GLX_BLUE_SIZE,      8,
			GLX_ALPHA_SIZE,     8,
			GLX_BUFFER_SIZE,    32,
			GLX_SAMPLE_BUFFERS, 0,
			GLX_SAMPLES,        0,
			0L
		};
		m_visualInfo = glXChooseVisual(OSInfo::get()->displayX11, OSInfo::get()->screenIdX11, attribsGLX);
		if(m_visualInfo == nullptr) {
			printf("OWL: glXChooseVisual doesn't work!\n");
			return false;
		}

		Win(m_windowImpl)->m_depth = m_visualInfo->depth;
		Win(m_windowImpl)->m_visual = m_visualInfo->visual;

		return true;
	}
	virtual bool validate() {
		m_glXContext = glXCreateContext(OSInfo::get()->displayX11, m_visualInfo, 0, true);
		glXMakeCurrent(OSInfo::get()->displayX11, Win(m_windowImpl)->m_window, m_glXContext);

		return true;
	}

	virtual void destroy() {
		glXDestroyContext(OSInfo::get()->displayX11, m_glXContext);
	}

	virtual OpenGLLoaderFunction getLoaderFunction() {
		return [](const char* name) {
			void *p = (void*)glXGetProcAddress((unsigned char*)name);
			return p;
		};
	}
	virtual void swapBuffers() {
		glXSwapBuffers(OSInfo::get()->displayX11, Win(m_windowImpl)->m_window);
	}

public:
	::XVisualInfo* m_visualInfo;
	::GLXContext m_glXContext;
};
}
}