#pragma once

#include <OWL/Graphics/Context.hpp>

namespace OWL {
namespace Impl {
class OWL_API Window;

class OWL_API Context {
public:
	Context() {}
	virtual ~Context() {}

	virtual bool create() {return false;}
	virtual bool validate() {return false;}

	virtual void destroy() {}


public:
	Window* m_windowImpl;
};
}
}
