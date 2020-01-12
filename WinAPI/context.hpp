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
	virtual bool Create() {
		return false;
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
	bool Create() {
		if(!m_Created) {
			m_Created = true;
			return true;
		}
		else {Debug::Out::Print("Context being created when it already was!\n", Debug::Out::Type::ERR);
			return false;
		}
	}

	friend class Window;

protected:
	Vec2<unsigned int> m_Size;
	char* m_Data;
	bool m_Created;

	friend class Window;
};

}
}

#endif/*_OWL_WINAPI_CONTEXT_HPP_HEADER_FILE_GUARD*/