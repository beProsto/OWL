#pragma once

#include <OWL/Utility/Config.hpp>

namespace OWL {
namespace Graphics {

namespace Impl {
class OWL_API Context;
}

class OWL_API Context {
public:
	Context();
	~Context();

	const char* GetType();

protected:
	void Init();
	void Validate();

	// friend Window;

	Impl::Context* m_Impl;
};

}
}
