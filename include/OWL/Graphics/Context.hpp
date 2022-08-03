#pragma once

#include <OWL/Utility/Config.hpp>

namespace OWL {

namespace Impl {
class OWL_API Context;
}

class OWL_API Window;

class OWL_API Context {
public:
	Context();
	~Context();

protected:
	Impl::Context* m_impl;
	friend Window;
};

}