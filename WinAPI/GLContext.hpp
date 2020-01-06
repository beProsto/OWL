#ifndef _OWL_WINAPI_GLCONTEXT_HPP_HEADER_FILE_GUARD
#define _OWL_WINAPI_GLCONTEXT_HPP_HEADER_FILE_GUARD

#include "context.hpp"

namespace OWL {
namespace WinAPI {
class GLContext: public Context {
public:
	GLContext() {
		m_Created = false;
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
		if(!m_Created) {
			m_Created = true;
			return true;
		}
		else {
			Debug::Out::Print("Context being created when it already was!\n", Debug::Out::Type::ERROR);
			return false;
		}
	}

	friend class Window;

protected:
	bool m_Created;

	friend class Window;
};
	
}
}

#endif/*_OWL_WINAPI_GLCONTEXT_HPP_HEADER_FILE_GUARD*/
