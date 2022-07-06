#pragma once

#include <OWL/Utility/Config.hpp>

namespace OWL {

namespace Impl {
class OWL_API Context;
}

class OWL_API Context {
public:
	Context();
	~Context();

protected:
	// Seems like some operating systems require for there to be two seperate steps during graphics' context creation;
	// One done before the creation of a window and one after. We'll call them creation and validation.
	bool Create();
	bool Validate();

protected:
	Impl::Context* m_Impl;

	friend class Window;
};

}