#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/Utility/Vec2.hpp>

#include <OWL/OS/Windows.hpp>

namespace OWL {

class OWL_API Mouse {
public:
	Mouse();
	~Mouse();

	void SetVisibility(bool _visible);
	bool IsVisible() const;

	void SetPosition(const Vec2<int>& _position);
	Vec2<int> GetPosition() const;
	// const Vec2<int>& GetPositionFromEvent() const;

	int GetWheelRotation() const;
	
	bool IsButtonPressed(unsigned int _button) const;
};

}