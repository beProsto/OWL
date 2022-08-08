#pragma once

#include "../SoftwareContext.hpp"
#include "../../System/Window.hpp"

#include <OWL/OS/Linux.hpp>

#include <stdio.h>

namespace OWL {
namespace Impl {
class OWL_API X11SoftwareContext: public SoftwareContext {
public:
	X11SoftwareContext() {

	}
	virtual ~X11SoftwareContext() {

	}

	virtual bool create()  {
		return true;
	}
	virtual bool validate() {


		m_data = new unsigned char[0];
		m_size = OWL::Vec2ui(0);
		
		return true;
	}

	virtual void destroy() {

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

	}

	virtual Vec4ub* getPixelData() {
		return reinterpret_cast<Vec4ub*>(m_data);
	}

public:
	Vec2<unsigned int> m_size;
	unsigned char* m_data;


};
}
}