#pragma once

#include <OWL/Utility/Config.hpp>

#if defined OWL_SYSTEM_LINUX
	// X11 (THESE PROPABLY SHOULDN'T BE INCLUDED IN THE HEADERS)
	extern "C" {
		#include <X11/Xlib.h>

		#include <X11/Xutil.h>
		#include <X11/keysymdef.h>
		#include <X11/cursorfont.h>
		#include <X11/Xatom.h>
		#include <linux/joystick.h>

		#undef Bool
		#undef None
		#undef Status
		#undef True
		#undef False
		#undef RootWindow
		#undef CurrentTime 
		#undef Success 
		#undef DestroyAll 
		#undef COUNT
		#undef CREATE
		#undef DeviceAdded
		#undef DeviceRemoved
	}

	// namespace X11 {
	// 	static const long None = 0L;
	// 	static const long CurrentTime = 0L;
	// 	static const int Success = 0;
	// }


#endif