#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/Graphics/Context.hpp>

#include <OWL/OS/OpenGL.hpp>

namespace OWL {

class OWL_API OpenGLContext: public Context {
public:
	OpenGLContext();
	~OpenGLContext();

	OpenGLLoaderFunction GetLoaderFunction();
	void SwapBuffers();
};

}