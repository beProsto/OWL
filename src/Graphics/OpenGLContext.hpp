#pragma once

#include <OWL/OS/OpenGL.hpp>

#include "Context.hpp"

namespace OWL {
namespace Impl {
class OWL_API OpenGLContext: public Context {
public:
	OpenGLContext() {}
	virtual ~OpenGLContext() {}

	virtual bool Create() {return false;}
	virtual bool Validate() {return false;}
	
	virtual void Destroy() {}

	virtual OpenGLLoaderFunction GetLoaderFunction() { return [](const char* name){return static_cast<void*>(nullptr);}; }
	virtual void SwapBuffers() {}
};
}
}

#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/OpenGLContext.hpp"
#elif defined OWL_SYSTEM_LINUX

#endif