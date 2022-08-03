#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/Utility/Vec2.hpp>
#include <OWL/Utility/Vec4.hpp>

#include <OWL/Graphics/Context.hpp>

namespace OWL {

class OWL_API SoftwareContext: public Context {
public:
	SoftwareContext();
	~SoftwareContext();

	void setSize(Vec2ui _newSize);
	Vec2ui getSize() const;

	void clear(const Vec4ub& _color = Vec4ub(0));
	
	void blitToScreen();
	
	Vec4ub* getPixelData();
};

}