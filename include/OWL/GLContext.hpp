#pragma once

#include "config.hpp"

/* This file contains typedefs for GLContext type in OWL */
namespace OWL {
enum {
	ContextType_OpenGL = 2,
};
}

#if defined OWL_SYSTEM_WINDOWS
/* WinAPI */
#include "WinAPI/GLContext.hpp"

namespace OWL {
typedef WinAPI::GLContext GLContext;
}

#elif defined __linux__
/* X11 */
#include "X11/GLContext.hpp"

namespace OWL {
typedef X11::GLContext GLContext;
}

#else

#error OWL: Unsupported platform! (Only linux and windows supported currently!)

#endif