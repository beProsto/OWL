#pragma once

#include "../SoftwareContext.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Windows.hpp>

#include <stdio.h>

namespace OWL {
namespace Impl {
#define Win(x) static_cast<WinAPIWindow*>(x)

class OWL_API WinAPISoftwareContext: public SoftwareContext {
public:
	WinAPISoftwareContext() {

	}
	virtual ~WinAPISoftwareContext() {

	}

	virtual bool create()  {
		return true;
	}
	virtual bool validate() {
		m_hdc = GetDC(Win(m_windowImpl)->m_hwnd);

		m_data = new unsigned char[0];
		m_size = OWL::Vec2ui(0);
		
		return true;
	}

	virtual void destroy() {
		ReleaseDC(Win(m_windowImpl)->m_hwnd, m_hdc);
		delete[] m_data;
		m_size = OWL::Vec2ui(0);
	}

	virtual void setSize(Vec2ui _newSize) {
		if(m_size != _newSize) {
			m_size = _newSize;
			delete[] m_data;
			m_data = new unsigned char[m_size.x * m_size.y * 4];
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
		/* Our data is in RGBA format, but WinAPI requires BGRA format for some reason */
		/* We have to swap red and blue */
		for(size_t i = 0; i < m_size.x * m_size.y * 4; i += 4) {
			unsigned char red = m_data[i];
			m_data[i] = m_data[i+2]; /* blue */
			m_data[i+2] = red; /* red */
		}
		
		HDC hdcMem = CreateCompatibleDC(m_hdc);
		HBITMAP hBitmap = CreateBitmap(m_size.x, m_size.y, 1, 32, m_data);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(hdcMem, hBitmap);
		
		BitBlt(m_hdc, 0, 0, m_size.x, m_size.y, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem, oldBitmap);
		DeleteObject(hBitmap);
		DeleteDC(hdcMem);
	}

	virtual Vec4ub* getPixelData() {
		return reinterpret_cast<Vec4ub*>(m_data);
	}

public:
	Vec2<unsigned int> m_size;
	unsigned char* m_data;

	HDC m_hdc;

};
}
}