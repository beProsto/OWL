#pragma once

#include <OWL/Utility/Config.hpp>

namespace OWL {
namespace Input {

namespace Impl {
class OWL_API Mouse;
}

class OWL_API Mouse {
public:
	Mouse();
	~Mouse();

private:
	Impl::Mouse* m_Impl;
};

}
}