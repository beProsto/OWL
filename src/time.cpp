#include <OWL/time.hpp>

namespace OWL {

FPSLimiter::FPSLimiter(unsigned int _desiredFPS) {
	m_FPS = _desiredFPS;
}
FPSLimiter::~FPSLimiter() {

}
FPSLimiter& FPSLimiter::SetDesiredFPS(unsigned int _desiredFPS) {
	m_FPS = _desiredFPS;
	return *this;
}
unsigned int FPSLimiter::GetDesiredFPS() const {
	return m_FPS;
}
FPSLimiter& FPSLimiter::Start() {
	m_StartTicks = (clock())/(CLOCKS_PER_SEC/1000.0);
	return *this;
}
FPSLimiter& FPSLimiter::End() {
	unsigned int elapsedTicks = (clock())/(CLOCKS_PER_SEC/1000.0) - m_StartTicks;
	float delay = (1000.0f/m_FPS)-elapsedTicks;
	if(delay > 0) {
		Sleep(delay);
	}
	return *this;
}

}