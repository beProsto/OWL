#include <OWL/Time.hpp>

#include <chrono>
#include <thread>

#include <time.h>
#ifndef OWL_SYSTEM_WINDOWS
#include <sys/time.h>
#endif

namespace OWL {

using Duration = std::chrono::duration<double, std::milli>;
using Clock = std::chrono::steady_clock;

void OWL_API sleep(double _milliseconds) {
	std::this_thread::sleep_for(Duration(_milliseconds));
}


namespace Impl {
class OWL_API Timer {
public:
	Timer() {
	}
	~Timer() {
	}

	inline void start() {
		m_s = Clock::now();
	}
	inline void end() {
		m_e = Clock::now();
	}
	inline double getDelta() {
		return std::chrono::duration_cast<Duration>(m_e - m_s).count();
	}

public:
	Clock::time_point m_s, m_e;
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
	m_impl->start();
}
void FPSLimiter::end() {
	m_impl->end();
	double ms = m_impl->getDelta();
	double delay = 1000.0 / static_cast<double>(m_fps) - ms;
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
	m_impl->start();
}
void Timer::end() {
	m_impl->end();
	m_deltaTime = m_impl->getDelta() / 1000.0;
}
double Timer::getDeltaTime() const {
	return m_deltaTime;
}

}