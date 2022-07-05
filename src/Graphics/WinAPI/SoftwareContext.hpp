#pragma once

#include "../SoftwareContext.hpp"

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

	virtual bool Create() {printf("WINAPI SOFT CONT CREATED\n"); return true;}
	virtual bool Validate() {printf("WINAPI SOFT CONT VALIDATED\n"); return true;}


	virtual void Resize(Vec2ui _newSize) {

	}
	virtual Vec2ui GetSize() const {
		return Vec2ui(0);
	}

	virtual void Clear(const Vec4ub& _color) {
		printf("WINAPI CONTEXT CLEAR\n");
	}

	virtual void BlitToScreen() {

	}

	virtual Vec4ub* GetPixelData() {
		return nullptr;
	}

	virtual unsigned int GetType() const {
		return 0;
	}
};
}
}