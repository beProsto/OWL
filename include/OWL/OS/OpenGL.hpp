#pragma once

#include <OWL/Utility/Config.hpp>

namespace OWL {
	using OpenGLLoaderFunction = void*(*)(const char*); 
}

#if defined OWL_SYSTEM_EMSCRIPTEN
	#include <OWL/OS/Emscripten.hpp>
	#include <GLES2/gl2.h>

#elif defined OWL_SYSTEM_WINDOWS
	#include <OWL/OS/Windows.hpp>
	#include <gl/gl.h>

#elif defined OWL_SYSTEM_LINUX
	#include <OWL/OS/Linux.hpp>
	#include <GL/gl.h>
	#include <GL/glx.h>

#endif