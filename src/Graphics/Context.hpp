#pragma once

#include <OWL/Graphics/Context.hpp>

namespace OWL {
namespace Impl {
class OWL_API Context {
public:
	Context() {}
	virtual ~Context() {}

	virtual bool Create() {return false;}
	virtual bool Validate() {return false;}
};
}
}
