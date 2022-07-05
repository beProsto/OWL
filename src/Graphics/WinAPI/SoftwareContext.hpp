#pragma once

#include "../SoftwareContext.hpp"

#include <OWL/OS/Windows.hpp>

#include <stdio.h>

namespace OWL {
namespace Impl {
class OWL_API WinAPISoftwareContext: public SoftwareContext {
public:
	WinAPISoftwareContext() {

	}
	virtual ~WinAPISoftwareContext() {

	}

	virtual bool Create() {printf("WINAPI SOFT CONT CREATED"); return true;}
	virtual bool Validate() {printf("WINAPI SOFT CONT VALIDATED"); return true;}


};
}
}