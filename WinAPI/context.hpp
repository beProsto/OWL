#ifndef _OWL_WINAPI_CONTEXT_HPP_HEADER_FILE_GUARD
#define _OWL_WINAPI_CONTEXT_HPP_HEADER_FILE_GUARD

#include "WinAPI.hpp"

namespace OWL {
namespace WinAPI {

class Context {
public:
	Context() {

	}
	~Context() {

	}

public:
	virtual unsigned int GetType() const {
		return ContextType_Unknown;
	}

protected:
	virtual bool Create(HWND _hwnd) {
		return false;
	}
	virtual void Destroy() {
		
	}

	friend class Window;
};

class SoftwareContext: public Context {
public:
	SoftwareContext() {
		m_Created = false;
	}
	~SoftwareContext() {
		if(m_Created) {
			delete[] m_Data;
		}
	}

public:
	SoftwareContext& Resize(const Vec2<unsigned int>& _newSize) {
		if(m_Size != _newSize) {
			m_Size = _newSize;
			delete[] m_Data;
			m_Data = new char[m_Size.x * m_Size.y * 4];
		}
		return *this;
	}
	SoftwareContext& Clear(const Vec4<char>& _color = Vec4<char>(0)) {
		for(size_t i = 0; i < m_Size.x * m_Size.y * 4; i+=4) {
			m_Data[i] = _color.r; /* red */
			m_Data[i+1] = _color.g; /* green */
			m_Data[i+2] = _color.b; /* blue */
			m_Data[i+3] = _color.a; /* alpha */
		}	
		return *this;
	}
	SoftwareContext& BlitToScreen() {	
		/* Our data is in RGBA format, but WinAPI requires BGRA format for some reason */
		/* We have to swap red and blue */
		for(size_t i = 0; i < m_Size.x * m_Size.y * 4; i += 4) {
			char red = m_Data[i];
			m_Data[i] = m_Data[i+2]; /* blue */
			m_Data[i+2] = red; /* red */
		}
		
		HDC hdcMem = CreateCompatibleDC(m_Hdc);
		HBITMAP hBitmap = CreateBitmap(m_Size.x, m_Size.y, 1, 32, m_Data);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(hdcMem, hBitmap);
		
		BitBlt(m_Hdc, 0, 0, m_Size.x, m_Size.y, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem, oldBitmap);
		DeleteObject(hBitmap);
		DeleteDC(hdcMem);

		return *this;
	}
	Vec4<char>* GetPixelData() {
		return (Vec4<char>*)m_Data;
	}

	const Vec2<unsigned int>& GetSize() const {
		return m_Size;
	}
	unsigned int GetType() const {
		return ContextType_Software;
	}

protected:
	bool Create(HWND _hwnd) {
		if(!m_Created) {
			m_Created = true;

			m_Hwnd = _hwnd;
			m_Hdc = GetDC(m_Hwnd);

			m_Data = new char[0];
			
			return true;
		}
		else {Debug::Out::Print("Context being created when it already was!\n", Debug::Out::Type::ERR);
			return false;
		}
	}
	void Destroy() {
		if(m_Created) {
			ReleaseDC(m_Hwnd, m_Hdc);
		}
	}

	friend class Window;

protected:
	bool m_Created;

	Vec2<unsigned int> m_Size;
	char* m_Data;

	HWND m_Hwnd;
	HDC m_Hdc;

	friend class Window;
};

}
}

#endif/*_OWL_WINAPI_CONTEXT_HPP_HEADER_FILE_GUARD*/