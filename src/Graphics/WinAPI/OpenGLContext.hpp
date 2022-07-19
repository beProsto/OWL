#pragma once

#include "../OpenGLContext.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Windows.hpp>

#include <OWL/OS/OpenGL.hpp>

namespace OWL {
namespace Impl {
class OWL_API WinAPIOpenGLContext: public OpenGLContext {
public:
	WinAPIOpenGLContext() {

	}
	virtual ~WinAPIOpenGLContext() {

	}

	virtual bool Create()  {
		return true;
	}
	virtual bool Validate() {
		m_Hdc = GetDC(static_cast<WinAPIWindow*>(m_WindowImpl)->m_Hwnd);
		
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
		iFormat = ChoosePixelFormat(m_Hdc, &pfd);
		SetPixelFormat(m_Hdc, iFormat, &pfd);

		m_Hrc = wglCreateContext(m_Hdc);
		wglMakeCurrent(m_Hdc, m_Hrc);

		OSInfo::Get()->Opengl32ModuleHandle = LoadLibraryA("opengl32.dll");

		return true;
	}

	virtual void Destroy() {
		FreeLibrary(OSInfo::Get()->Opengl32ModuleHandle);
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(m_Hrc);
		ReleaseDC(static_cast<WinAPIWindow*>(m_WindowImpl)->m_Hwnd, m_Hdc);
	}

	virtual OpenGLLoaderFunction GetLoaderFunction() {
		return [](const char* name) {
			void *p = (void *)wglGetProcAddress(name);
			if(
				p == 0 ||
				(p == (void*)0x1) || 
				(p == (void*)0x2) || 
				(p == (void*)0x3) ||
				(p == (void*)-1)
			) {
				p = (void *)::GetProcAddress(OSInfo::Get()->Opengl32ModuleHandle, name);
			}
			return p;
		};
	}
	virtual void SwapBuffers() {
		::SwapBuffers(m_Hdc);
	}

public:
	HDC m_Hdc;
	HGLRC m_Hrc;

};
}
}