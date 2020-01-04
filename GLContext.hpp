#ifndef _OWL_GLCONTEXT_HPP_HEADER_FILE_GUARD
#define _OWL_GLCONTEXT_HPP_HEADER_FILE_GUARD

/* This file contains typedefs for GLContext type in OWL */
namespace OWL {
enum {
	ContextType_OpenGL = 2,
};
}

#ifdef _WIN32
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

#elif defined __APPLE__
/* Mac stuff */
#include "Unsupported/GLContext.hpp"

namespace OWL {
typedef Unsupported::GLContext GLContext;
}

#endif

#endif/*_OWL_GLCONTEXT_HPP_HEADER_FILE_GUARD*/