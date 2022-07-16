#pragma once

#include "../SoftwareContext.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Windows.hpp>

#include <stdio.h>

namespace OWL {
namespace Impl {
class OWL_API WinAPISoftwareContext: public SoftwareContext {
public:
	WinAPISoftwareContext() {

	}
	virtual ~WinAPISoftwareContext() {

	}

	virtual bool Create()  {
		return true;
	}
	virtual bool Validate() {
		m_Hdc = GetDC(static_cast<WinAPIWindow*>(m_WindowImpl)->m_Hwnd);

		m_Data = new unsigned char[0];
		
		return true;
	}


	virtual void SetSize(Vec2ui _newSize) {
		if(m_Size != _newSize) {
			m_Size = _newSize;
			delete[] m_Data;
			m_Data = new unsigned char[m_Size.x * m_Size.y * 4];
		}
	}
	virtual Vec2ui GetSize() const {
		return m_Size;
	}

	virtual void Clear(const Vec4ub& _color) {
		for(size_t i = 0; i < m_Size.x * m_Size.y * 4; i+=4) {
			m_Data[i] = _color.r; /* red */
			m_Data[i+1] = _color.g; /* green */
			m_Data[i+2] = _color.b; /* blue */
			m_Data[i+3] = _color.a; /* alpha */
		}
	}

	virtual void BlitToScreen() {
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
	}

	virtual Vec4ub* GetPixelData() {
		return reinterpret_cast<Vec4ub*>(m_Data);
	}

public:
	Vec2<unsigned int> m_Size;
	unsigned char* m_Data;

	// HWND m_Hwnd;
	HDC m_Hdc;

};
}
}