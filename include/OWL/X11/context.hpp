#ifndef _OWL_X11_CONTEXT_HPP_HEADER_FILE_GUARD
#define _OWL_X11_CONTEXT_HPP_HEADER_FILE_GUARD

#include "X11.hpp"

namespace OWL {
namespace X11 {

#define OWL_X11_WINDOW_EVENT_MASKS ExposureMask | ButtonPressMask | ButtonReleaseMask | EnterWindowMask | LeaveWindowMask | PointerMotionMask | PointerMotionHintMask | Button1MotionMask | Button2MotionMask | Button3MotionMask | Button4MotionMask | Button5MotionMask | ButtonMotionMask | KeymapStateMask | KeyPressMask | KeyReleaseMask

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
	virtual bool Create(::Display* _display, int* _screenID, ::Window* _section, const Vec2<int>& _position, const Vec2<unsigned int>& _size) {
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
			XFree(m_Image);
			m_Image = XCreateImage(m_Display, m_Visual, DefaultDepth(m_Display, *m_ScreenID), ZPixmap, 0, m_Data, m_Size.x, m_Size.y, 32, 0);
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
		/* Our data is in RGBA format, but Xlib requires BGRA format for some reason */
		/* We have to swap red and blue */
		for(size_t i = 0; i < m_Size.x * m_Size.y * 4; i += 4) {
			char red = m_Data[i];
			m_Data[i] = m_Data[i+2]; /* blue */
			m_Data[i+2] = red; /* red */
		}

		XPutImage(m_Display, *m_Section, DefaultGC(m_Display, *m_ScreenID), m_Image, 0, 0, 0, 0, m_Size.x, m_Size.y);
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
	bool Create(::Display* _display, int* _screenID, ::Window* _section, const Vec2<int>& _position, const Vec2<unsigned int>& _size) {
		if(!m_Created) {
			m_Display = _display;
			m_ScreenID = _screenID;
			m_Section = _section;
			m_Size = _size;

			m_Visual = DefaultVisual(m_Display, *m_ScreenID);
			m_Data = new char[m_Size.x * m_Size.y * 4];
			m_Image = XCreateImage(m_Display, m_Visual, DefaultDepth(m_Display, *m_ScreenID), ZPixmap, 0, m_Data, m_Size.x, m_Size.y, 32, 0);

			*m_Section = XCreateSimpleWindow(m_Display, RootWindow(m_Display, *m_ScreenID), _position.x, _position.y, m_Size.x, m_Size.y, 1, 0, 0);
			XSelectInput(m_Display, *m_Section, OWL_X11_WINDOW_EVENT_MASKS);
			XMapWindow(m_Display, *m_Section);

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
			XFree(m_Image);
		}
	}

	friend class Window;

protected:
	::Visual* m_Visual;
	::XImage* m_Image;
	char* m_Data;
	bool m_Created;

	::Display* m_Display; 
	int* m_ScreenID; 
	::Window* m_Section;

	Vec2<unsigned int> m_Size;

	friend class Window;
};

}
}

#endif/*_OWL_X11_CONTEXT_HPP_HEADER_FILE_GUARD*/
