#pragma once

#include "Context.hpp"

namespace OWL {
namespace Impl {
class OWL_API SoftwareContext: public Context {
public:
	SoftwareContext() {}
	virtual ~SoftwareContext() {}

	virtual bool Create() {return false;}
	virtual bool Validate() {return false;}

	virtual void Resize(const Vec2ui& _newSize) {}
	const Vec2ui& GetSize() const;

	void Clear(const Vec4ub& _color = Vec4ub(0));

	void BlitToScreen();

	Vec4ub* GetPixelData();

	unsigned int GetType() const;
};
}
}

#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/SoftwareContext.hpp"
#elif defined OWL_SYSTEM_LINUX

#endif