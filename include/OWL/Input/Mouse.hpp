#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/Utility/Vec2.hpp>

#include <OWL/OS/Windows.hpp>
#include <OWL/OS/Linux.hpp>

namespace OWL {

class OWL_API Mouse {
public:
	Mouse();
	~Mouse();

	void SetVisibility(bool _visible);
	bool IsVisible() const;

	void SetPosition(const Vec2<int>& _position);
	Vec2<int> GetPosition() const;

	int GetWheelRotation() const;
	bool IsButtonPressed(unsigned int _button) const;

public:
	/// THIS HAS TO BE THOUGHT THROUGH ONCE AGAIN
	/// WAYLAND MAY HAVE DIFFERENT BUTTON ID'S
	enum Button {
		#if defined OWL_SYSTEM_WINDOWS
			Left = VK_LBUTTON,
			Middle = VK_MBUTTON,
			Right = VK_RBUTTON,
			Backward = VK_XBUTTON1,
			Forward = VK_XBUTTON2,
		
		#elif defined OWL_SYSTEM_LINUX
			Left = 1<<8,
			Middle = 1<<9,
			Right = 1<<10,
			Backward = 1<<15,
			Forward = 1<<16,

		#endif
	};

	/// HERE'S MY PROPOSITION FOR A CHANGE :

	// enum Button {
	// 	Left = 0,
	//	Middle = 1,
	// 	Right = 2,
	// 	Backward = 3,
	// 	Forward = 4,
	//	Count,
	// };

	/// Later in the code (most likely the source files, in the window class as it chooses the windowing server) :
	// https://codereview.stackexchange.com/questions/24154/mapping-enum-to-enum

	// unsigned int ButtonMap[Button::Count]  = {
	// 	VK_LBUTTON,
	// 	VK_MBUTTON,
	// 	VK_RBUTTON,
	// 	VK_XBUTTON1,
	// 	VK_XBUTTON2,
	// };
};

}