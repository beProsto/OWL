#pragma once

#include "Context.hpp"

#include <OWL/Utility/Vec2.hpp>
#include <OWL/Utility/Vec4.hpp>

namespace OWL {
namespace Impl {
class OWL_API SoftwareContext: public Context {
public:
	SoftwareContext() {}
	virtual ~SoftwareContext() {}

	virtual bool Create() {return false;}
	virtual bool Validate() {return false;}

	virtual void SetSize(Vec2ui _newSize) {}
	virtual Vec2ui GetSize() const {return Vec2ui(0);}

	virtual void Clear(const Vec4ub& _color) {}

	virtual void BlitToScreen() {}

	virtual Vec4ub* GetPixelData() {return nullptr;}

	virtual unsigned int GetType() const {return 0;}
};
}
}

#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/SoftwareContext.hpp"
#elif defined OWL_SYSTEM_LINUX

#endif