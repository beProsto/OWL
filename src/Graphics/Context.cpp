#include <OWL/Graphics/Context.hpp>

#include "Context.hpp"

namespace OWL {

Context::Context() {

}
Context::~Context() {

}

bool Context::Create() {
	m_Impl->Create();
}

bool Context::Validate() {
	m_Impl->Validate();
}

}