#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/Graphics/Context.hpp>

namespace OWL {

class OWL_API OpenGLContext: public Context {
public:
	OpenGLContext();
	~OpenGLContext();
	
	void SwapBuffers();
};

}