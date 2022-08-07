#pragma once

#include <OWL/Utility/Config.hpp>

#if defined OWL_SYSTEM_LINUX
	// Most of these prolly shouldn't be included in the headers
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
	#include <X11/keysymdef.h>
	#include <X11/cursorfont.h>
	#include <X11/Xatom.h>
	#include <linux/joystick.h>

#endif