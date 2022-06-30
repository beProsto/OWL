#include <OWL/Time.hpp>

namespace OWL {

FPSLimiter::FPSLimiter(unsigned int _desiredFPS) {
	m_FPS = _desiredFPS;
}
FPSLimiter::~FPSLimiter() {

}
void FPSLimiter::SetDesiredFPS(unsigned int _desiredFPS) {
	m_FPS = _desiredFPS;
}
unsigned int FPSLimiter::GetDesiredFPS() const {
	return m_FPS;
}
void FPSLimiter::Start() {
	m_StartTicks = (clock())/(CLOCKS_PER_SEC/1000.0);
}
void FPSLimiter::End() {
	unsigned int elapsedTicks = (clock())/(CLOCKS_PER_SEC/1000.0) - m_StartTicks;
	float delay = (1000.0f/m_FPS)-elapsedTicks;
	if(delay > 0) {
		Sleep(delay);
	}
}

Timer::Timer() {

}
Timer::~Timer() {

}
void Timer::Start() {
	m_S = std::chrono::high_resolution_clock::now();
}
void Timer::End() {
	m_E = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(m_E - m_S).count();
	m_DeltaTime = ms / 1000.0f;
}
float Timer::GetDeltaTime() const {
	return m_DeltaTime;
}

}