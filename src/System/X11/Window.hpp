#pragma once

#include <OWL/Utility/Config.hpp>

#include "../Window.hpp"

namespace OWL {
namespace Impl {

class OWL_API X11Window: public Window {
public:
	X11Window() {

	}
	virtual ~X11Window() {
		
	}
};

}
}