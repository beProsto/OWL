#pragma once

#include <OWL/OS/OpenGL.hpp>

#include "Context.hpp"

namespace OWL {
namespace Impl {
class OWL_API OpenGLContext: public Context {
public:
	OpenGLContext() {}
	virtual ~OpenGLContext() {}

	virtual bool create() {return false;}
	virtual bool validate() {return false;}
	
	virtual void destroy() {}

	virtual OpenGLLoaderFunction getLoaderFunction() { return [](const char* name){return static_cast<void*>(nullptr);}; }
	virtual void swapBuffers() {}
};
}
}

#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/OpenGLContext.hpp"

#elif defined OWL_SYSTEM_LINUX
	#include "X11/OpenGLContext.hpp"

#endif