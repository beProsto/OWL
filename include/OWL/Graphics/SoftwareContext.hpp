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

	void Resize(const Vec2ui& _newSize);
	const Vec2ui& GetSize() const;

	void Clear(const Vec4ub& _color = Vec4ub(0));
	
	void BlitToScreen();
	
	Vec4ub* GetPixelData();
	
	unsigned int GetType() const;
};

}