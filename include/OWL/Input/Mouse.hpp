#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/Utility/Vec2.hpp>

namespace OWL {

namespace Impl {
class OWL_API Mouse;
}

class OWL_API Mouse {
public:
	Mouse();
	~Mouse();

	void setVisibility(bool _visible);
	bool isVisible() const;

	void setPosition(const Vec2i& _position);
	Vec2i getPosition() const;

	int getWheelRotation() const;
	
	bool isButtonPressed(unsigned int _button) const;

public:
	enum Button {
		Left = 0,
		Middle,
		Right,
		Backward,
		Forward,
		Count,
	};

	/// Later in the code we translate them to OS specific :
	// https://codereview.stackexchange.com/questions/24154/mapping-enum-to-enum

protected:
	Impl::Mouse* m_impl;

	friend class Window;
};

}