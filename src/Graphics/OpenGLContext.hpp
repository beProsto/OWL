#pragma once

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

	virtual void SwapBuffers() {}
};
}
}

#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/OpenGLContext.hpp"
#elif defined OWL_SYSTEM_LINUX

#endif