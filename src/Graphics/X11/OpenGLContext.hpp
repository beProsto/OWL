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

		return true;
	}

	virtual void destroy() {

	}

	virtual OpenGLLoaderFunction getLoaderFunction() {
		return [](const char* name) {
			void *p = nullptr;
			return p;
		};
	}
	virtual void swapBuffers() {

	}

public:

};
}
}