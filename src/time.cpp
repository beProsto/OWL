#include <OWL/Time.hpp>

#include <chrono>
#include <thread>

#include <time.h>
#ifndef OWL_SYSTEM_WINDOWS
#include <sys/time.h>
#endif

namespace OWL {

void OWL_API Sleep(unsigned int _milliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(_milliseconds));
}


namespace Impl {
class OWL_API Timer {
public:
	Timer() {
	}
	~Timer() {
	}

public:
	std::chrono::high_resolution_clock::time_point m_S, m_E;
};
}


FPSLimiter::FPSLimiter(unsigned int _desiredFPS) {
	m_FPS = _desiredFPS;
	m_Impl = new Impl::Timer();
}
FPSLimiter::~FPSLimiter() {
	delete m_Impl;
}
void FPSLimiter::SetDesiredFPS(unsigned int _desiredFPS) {
	m_FPS = _desiredFPS;
}
unsigned int FPSLimiter::GetDesiredFPS() const {
	return m_FPS;
}
void FPSLimiter::Start() {
	m_Impl->m_S = std::chrono::high_resolution_clock::now();
}
void FPSLimiter::End() {
	m_Impl->m_E = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(m_Impl->m_E - m_Impl->m_S).count();
	float delay = (1000.0f / (float)m_FPS) - ms;
	if(delay > 0) {
		Sleep(delay);
	}
}


Timer::Timer() {
	m_Impl = new Impl::Timer();
}
Timer::~Timer() {
	delete m_Impl;
}
void Timer::Start() {
	m_Impl->m_S = std::chrono::high_resolution_clock::now();
}
void Timer::End() {
	m_Impl->m_E = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(m_Impl->m_E - m_Impl->m_S).count();
	m_DeltaTime = ms / 1000.0f;
}
float Timer::GetDeltaTime() const {
	return m_DeltaTime;
}

}