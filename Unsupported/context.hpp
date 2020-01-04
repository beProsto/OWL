#ifndef _OWL_UNSUPPORTED_CONTEXT_HPP_HEADER_FILE_GUARD
#define _OWL_UNSUPPORTED_CONTEXT_HPP_HEADER_FILE_GUARD

namespace OWL {
namespace Unsupported {
class Context {
public:
	Context() {

	}
	~Context() {

	}

public:
	virtual unsigned int GetType() const {
		return ContextType_Unknown;
	}

protected:
	virtual bool Create() {
		return false;
	}

	friend class Window;
};

class SoftwareContext: public Context {
public:
	SoftwareContext() {

	}
	~SoftwareContext() {

	}

public:
	unsigned int GetType() const {
		return ContextType_Software;
	}

protected:
	bool Create() {
		return false;
	}
	
	friend class Window;
};

}
}

#endif/*_OWL_UNSUPPORTED_CONTEXT_HPP_HEADER_FILE_GUARD*/