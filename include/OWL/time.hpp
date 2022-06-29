#pragma once

#include "config.hpp"

#include <chrono>
#include <thread>
#include <time.h>

#ifndef OWL_SYSTEM_WINDOWS
#include <sys/time.h>
#endif

namespace OWL {
inline void Sleep(unsigned int _milliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(_milliseconds));
}

class OWL_LIB_EXPORT FPSLimiter {
public:
	FPSLimiter(unsigned int _desiredFPS = 30);
	~FPSLimiter();

	FPSLimiter& SetDesiredFPS(unsigned int _desiredFPS = 30);
	unsigned int GetDesiredFPS() const;
	FPSLimiter& Start();
	FPSLimiter& End();

private:
	unsigned int m_StartTicks;
	unsigned int m_FPS;
};
class Timer {
public:
	Timer() {

	}
	~Timer() {

	}

	Timer& Start() {
		m_S = std::chrono::high_resolution_clock::now();
		return *this;
	}
	Timer& End() {
		m_E = std::chrono::high_resolution_clock::now();
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(m_E - m_S).count();
		m_DeltaTime = ms / 1000.0f;
		return *this;
	}

	float GetDeltaTime() const {
		return m_DeltaTime;
	}

private:
	std::chrono::high_resolution_clock::time_point m_S, m_E;
	float m_DeltaTime;
};

}