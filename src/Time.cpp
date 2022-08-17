#include <OWL/Time.hpp>

#include <chrono>
#include <thread>

#include <time.h>
#ifndef OWL_SYSTEM_WINDOWS
#include <sys/time.h>
#endif

namespace OWL {

void OWL_API sleep(unsigned int _milliseconds) {
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
	std::chrono::steady_clock::time_point m_s, m_e;
};
}


FPSLimiter::FPSLimiter(unsigned int _desiredFPS) {
	m_fps = _desiredFPS;
	m_impl = new Impl::Timer();
}
FPSLimiter::~FPSLimiter() {
	delete m_impl;
}
void FPSLimiter::setDesiredFPS(unsigned int _desiredFPS) {
	m_fps = _desiredFPS;
}
unsigned int FPSLimiter::getDesiredFPS() const {
	return m_fps;
}
void FPSLimiter::start() {
	m_impl->m_s = std::chrono::steady_clock::now();
}
void FPSLimiter::end() {
	m_impl->m_e = std::chrono::steady_clock::now();
	double ms = std::chrono::duration_cast<std::chrono::milliseconds>(m_impl->m_e - m_impl->m_s).count();
	double delay = (1000.0 / static_cast<double>(m_fps)) - static_cast<double>(ms);
	if(delay > 0.0) {
		sleep(delay);
	}
}


Timer::Timer() {
	m_impl = new Impl::Timer();
}
Timer::~Timer() {
	delete m_impl;
}
void Timer::start() {
	m_impl->m_s = std::chrono::steady_clock::now();
}
void Timer::end() {
	m_impl->m_e = std::chrono::steady_clock::now();
	double ms = std::chrono::duration_cast<std::chrono::milliseconds>(m_impl->m_e - m_impl->m_s).count();
	m_deltaTime = static_cast<double>(ms) / 1000.0;
}
double Timer::getDeltaTime() const {
	return m_deltaTime;
}

}