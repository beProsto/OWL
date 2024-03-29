#pragma once

#include "../OpenGLContext.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Windows.hpp>

#include <OWL/OS/OpenGL.hpp>

namespace OWL {
namespace Impl {
#define Win(x) static_cast<WinAPIWindow*>(x)

class OWL_API WinAPIOpenGLContext: public OpenGLContext {
public:
	WinAPIOpenGLContext() {

	}
	virtual ~WinAPIOpenGLContext() {

	}

	virtual bool create()  {
		return true;
	}
	virtual bool validate() {
		m_hdc = GetDC(Win(m_windowImpl)->m_hwnd);
		
		PIXELFORMATDESCRIPTOR pfd;
		int iFormat;
		
		ZeroMemory(&pfd, sizeof (pfd));
		pfd.nSize = sizeof(pfd);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = 32;
		pfd.cDepthBits = 24;
		pfd.cStencilBits = 8;
		pfd.iLayerType = PFD_MAIN_PLANE;
		iFormat = ChoosePixelFormat(m_hdc, &pfd);
		SetPixelFormat(m_hdc, iFormat, &pfd);

		m_hrc = wglCreateContext(m_hdc);
		wglMakeCurrent(m_hdc, m_hrc);

		OSInfo::get()->opengl32ModuleHandle = LoadLibraryA("opengl32.dll");

		return true;
	}

	virtual void destroy() {
		FreeLibrary(OSInfo::get()->opengl32ModuleHandle);
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(m_hrc);
		ReleaseDC(Win(m_windowImpl)->m_hwnd, m_hdc);
	}

	virtual OpenGLLoaderFunction getLoaderFunction() {
		return [](const char* name) {
			void *p = (void *)wglGetProcAddress(name);
			if(
				p == 0 ||
				(p == (void*)0x1) || 
				(p == (void*)0x2) || 
				(p == (void*)0x3) ||
				(p == (void*)-1)
			) {
				p = (void *)::GetProcAddress(OSInfo::get()->opengl32ModuleHandle, name);
			}
			return p;
		};
	}
	virtual void swapBuffers() {
		::SwapBuffers(m_hdc);
	}

public:
	HDC m_hdc;
	HGLRC m_hrc;

};
}
}