#ifndef _OWL_UNSUPPORTED_GLCONTEXT_HPP_HEADER_FILE_GUARD
#define _OWL_UNSUPPORTED_GLCONTEXT_HPP_HEADER_FILE_GUARD

#include "context.hpp"

namespace OWL {
namespace Unsupported {
class GLContext: public Context {
public:
	GLContext() {

	}
	~GLContext() {

	}

public:
	GLContext& SwapBuffers() {
		return *this;
	}

	unsigned int GetType() const {
		return ContextType_OpenGL;
	}

protected:
	bool Create() {
		return false;
	}

	friend class Window;

protected:
	friend class Window;
};
	
}
}

#endif/*_OWL_UNSUPPORTED_GLCONTEXT_HPP_HEADER_FILE_GUARD*/

