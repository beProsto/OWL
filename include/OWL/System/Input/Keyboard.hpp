#pragma once

#include <OWL/Utility/Config.hpp>

namespace OWL {
namespace Input {

namespace Impl {
class OWL_API Keyboard;
}

class OWL_API Keyboard {
public:
	Keyboard();
	~Keyboard();

private:
	Impl::Keyboard* m_Impl;
};

}
}