#ifndef _OWL_WINAPI_GLCONTEXT_HPP_HEADER_FILE_GUARD
#define _OWL_WINAPI_GLCONTEXT_HPP_HEADER_FILE_GUARD

#include "WGL.hpp"
#include "context.hpp"

namespace OWL {
namespace WinAPI {
class GLContext: public Context {
public:
	GLContext() {
		m_Created = false;
	}
	~GLContext() {

	}

public:
	GLContext& SwapBuffers() {
		::SwapBuffers(m_Hdc);
		return *this;
	}

	unsigned int GetType() const {
		return ContextType_OpenGL;
	}

    typedef void(*FuncPtr)();
    static void(*GetProcAddress(const char* name))() {
        void *p = (void *)wglGetProcAddress(name);
        if(
            p == 0 ||
            (p == (void*)0x1) || 
            (p == (void*)0x2) || 
            (p == (void*)0x3) ||
            (p == (void*)-1)
        ) {
            p = (void *)::GetProcAddress(g_WinAPI_Data->hOpengl32Module, name);
        }

        return (FuncPtr)p;
    }

protected:
	bool Create(HWND _hwnd) {
		if(!m_Created) {
			m_Created = true;

			m_Hwnd = _hwnd;
			m_Hdc = GetDC(m_Hwnd);
			
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

            g_WinAPI_Data->hOpengl32Module = LoadLibraryA("opengl32.dll");
			
			return true;
		}
		else {
			Debug::Out::Print("Context being created when it already was!\n", Debug::Out::Type::ERR);
			return false;
		}
	}
	void Destroy() {
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(m_Hrc);
		ReleaseDC(m_Hwnd, m_Hdc);
	}

	friend class Window;

protected:
	bool m_Created;

	HWND m_Hwnd;
	HDC m_Hdc;
	HGLRC m_Hrc;

	friend class Window;
};
	
}
}

#endif/*_OWL_WINAPI_GLCONTEXT_HPP_HEADER_FILE_GUARD*/

