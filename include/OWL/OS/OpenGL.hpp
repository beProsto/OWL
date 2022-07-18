#pragma once

#include <OWL/Utility/Config.hpp>

#if defined OWL_SYSTEM_WINDOWS
	#include <gl/gl.h>

#elif defined OWL_SYSTEM_LINUX
	#include <GL/gl.h>
	#include <GL/glx.h>

#endif