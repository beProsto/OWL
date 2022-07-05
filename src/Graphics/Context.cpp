#include <OWL/Graphics/Context.hpp>

#include "Context.hpp"

namespace OWL {

Context::Context() {

}
Context::~Context() {

}

bool Context::Create() {
	return m_Impl->Create();
}

bool Context::Validate() {
	return m_Impl->Validate();
}

}