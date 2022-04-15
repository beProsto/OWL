#ifndef _OWL_X11_GLCONTEXT_HPP_HEADER_FILE_GUARD
#define _OWL_X11_GLCONTEXT_HPP_HEADER_FILE_GUARD

#include "context.hpp"
#include "GLX.hpp"

namespace OWL {
namespace X11 {
class GLContext: public Context {
public:
	GLContext() {
		m_Created = false;
	}
	~GLContext() {

	}

public:
	GLContext& SwapBuffers() {
		glXSwapBuffers(m_Display, *m_Section);
		return *this;
	}

	unsigned int GetType() const {
		return ContextType_OpenGL;
	}

	static void(*GetProcAddress(unsigned char* name))() {
		return glXGetProcAddress(name);
	}

protected:
	bool Create(::Display* _display, int* _screenID, ::Window* _section, const Vec2<int>& _position, const Vec2<unsigned int>& _size) {
		if(!m_Created) {
			m_Display = _display;
			m_ScreenID = _screenID;
			m_Section = _section;

			int versionGLX[2] = {0, 0}; /* Order: major[0], minor[1] */ 
			glXQueryVersion(m_Display, &versionGLX[0], &versionGLX[1]);
			Debug::Out::Print("GLX Verion: " + std::to_string(versionGLX[0]) + "." + std::to_string(versionGLX[1]) + "\n", Debug::Out::Type::COMM);

			int attribsGLX[] = {
				GLX_RGBA,
				GLX_DOUBLEBUFFER,
				GLX_DEPTH_SIZE,     24,
				GLX_STENCIL_SIZE,   8,
				GLX_RED_SIZE,       8,
				GLX_GREEN_SIZE,     8,
				GLX_BLUE_SIZE,      8,
				GLX_ALPHA_SIZE,     8,
				GLX_BUFFER_SIZE,    32,
				GLX_SAMPLE_BUFFERS, 0,
				GLX_SAMPLES,        0,
				None
			};
			m_Visual = glXChooseVisual(m_Display, *m_ScreenID, attribsGLX);
			if(m_Visual == nullptr) {
				Debug::Out::Print("Couldn't choose visual!\n", Debug::Out::Type::ERR);
				return false;
			}

			m_WindowAttribs.border_pixel = BlackPixel(m_Display, *m_ScreenID);
			m_WindowAttribs.background_pixel = WhitePixel(m_Display, *m_ScreenID);
			m_WindowAttribs.override_redirect = True;
			m_WindowAttribs.colormap = XCreateColormap(m_Display, RootWindow(m_Display, *m_ScreenID), m_Visual->visual, AllocNone);
			m_WindowAttribs.event_mask = OWL_X11_WINDOW_EVENT_MASKS;

			*m_Section = XCreateWindow(m_Display, RootWindow(m_Display, *m_ScreenID), _position.x, _position.y, _size.x, _size.y, 
										0, m_Visual->depth, InputOutput, m_Visual->visual, 
										CWBackPixel | CWColormap | CWBorderPixel | CWEventMask, &m_WindowAttribs);

			m_GLContext = glXCreateContext(m_Display, m_Visual, 0, GL_TRUE);
			glXMakeCurrent(m_Display, *m_Section, m_GLContext);

			XClearWindow(m_Display, *m_Section);
			XMapRaised(m_Display, *m_Section);

			// Debug::Out::Print("GL Vendor: " + std::string((const char*)glGetString(GL_VENDOR)) + "\n");
			// Debug::Out::Print("GL Renderer: " + std::string((const char*)glGetString(GL_RENDERER)) + "\n");
			// Debug::Out::Print("GL Version: " + std::string((const char*)glGetString(GL_VERSION)) + "\n");
			// Debug::Out::Print("GLSL Version: " + std::string((const char*)glGetString(GL_SHADING_LANGUAGE_VERSION)) + "\n");

			m_Created = true;
			return true;
		}
		else {
			Debug::Out::Print("Context being created when it already was!\n", Debug::Out::Type::ERR);
			return false;
		}
	}
	void Destroy() {
		if(m_Created) {
			glXDestroyContext(m_Display, m_GLContext);
			XFree(m_Visual);
			
			XFreeColormap(m_Display, m_WindowAttribs.colormap);
		}
	}

	friend class Window;

protected:
	::XVisualInfo* m_Visual;
	bool m_Created;

	::GLXContext m_GLContext;

	::Display* m_Display;
	int* m_ScreenID;
	::Window* m_Section;

	::XSetWindowAttributes m_WindowAttribs;

	friend class Window;
};
	
}
}

#endif/*_OWL_X11_GLCONTEXT_HPP_HEADER_FILE_GUARD*/

