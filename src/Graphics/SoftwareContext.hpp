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

	virtual bool create() {return false;}
	virtual bool validate() {return false;}
	
	virtual void destroy() {}

	virtual void setSize(Vec2ui _newSize) {}
	virtual Vec2ui getSize() const {return Vec2ui(0);}

	virtual void clear(const Vec4ub& _color) {}

	virtual void blitToScreen() {}

	virtual Vec4ub* getPixelData() {return nullptr;}
};
}
}

#if defined OWL_SYSTEM_WINDOWS
	#include "WinAPI/SoftwareContext.hpp"

#elif defined OWL_SYSTEM_LINUX
	#include "X11/SoftwareContext.hpp"

#endif