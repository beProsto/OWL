#pragma once

#include "../SoftwareContext.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Linux.hpp>

#include <stdio.h>

namespace OWL {
namespace Impl {
#define Win(x) static_cast<X11Window*>(x)

class OWL_API X11SoftwareContext: public SoftwareContext {
public:
	X11SoftwareContext() {

	}
	virtual ~X11SoftwareContext() {

	}

	virtual bool create()  {
		m_data = new unsigned char[0];
		m_size = OWL::Vec2ui(0);

		Win(m_windowImpl)->m_visual = DefaultVisual(Win(m_windowImpl)->m_display, Win(m_windowImpl)->m_screenID);
		Win(m_windowImpl)->m_depth = 0;

		return true;
	}
	virtual bool validate() {
		m_image = XCreateImage(Win(m_windowImpl)->m_display, Win(m_windowImpl)->m_visual, DefaultDepth(Win(m_windowImpl)->m_display, Win(m_windowImpl)->m_screenID), ZPixmap, 0, reinterpret_cast<char*>(m_data), 0, 0, 32, 0);
		
		return true;
	}

	virtual void destroy() {
		XFree(m_image);
		delete[] m_data;
		m_size = OWL::Vec2ui(0);
	}

	virtual void setSize(Vec2ui _newSize) {
		if(m_size != _newSize) {
			m_size = _newSize;
			
			delete[] m_data;
			m_data = new unsigned char[m_size.x * m_size.y * 4];
			
			XFree(m_image);
			m_image = XCreateImage(Win(m_windowImpl)->m_display, Win(m_windowImpl)->m_visual, DefaultDepth(Win(m_windowImpl)->m_display, Win(m_windowImpl)->m_screenID), ZPixmap, 0, reinterpret_cast<char*>(m_data), m_size.x, m_size.y, 32, 0);
		}
	}
	virtual Vec2ui getSize() const {
		return m_size;
	}

	virtual void clear(const Vec4ub& _color) {
		for(size_t i = 0; i < m_size.x * m_size.y * 4; i+=4) {
			m_data[i] = _color.r; /* red */
			m_data[i+1] = _color.g; /* green */
			m_data[i+2] = _color.b; /* blue */
			m_data[i+3] = _color.a; /* alpha */
		}
	}

	virtual void blitToScreen() {
		/* Our data is in RGBA format, but Xlib requires BGRA format for some reason */
		/* We have to swap red and blue */
		for(size_t i = 0; i < m_size.x * m_size.y * 4; i += 4) {
			char red = m_data[i];
			m_data[i] = m_data[i+2]; /* blue */
			m_data[i+2] = red; /* red */
		}

		XPutImage(Win(m_windowImpl)->m_display, Win(m_windowImpl)->m_window, DefaultGC(Win(m_windowImpl)->m_display, Win(m_windowImpl)->m_screenID), m_image, 0, 0, 0, 0, m_size.x, m_size.y);
	}

	virtual Vec4ub* getPixelData() {
		return reinterpret_cast<Vec4ub*>(m_data);
	}

public:
	Vec2<unsigned int> m_size;
	unsigned char* m_data;

	::XImage* m_image;
};
}
}