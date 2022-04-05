#ifndef _OWL_TIME_HPP_HEADER_FILE_GUARD
#define _OWL_TIME_HPP_HEADER_FILE_GUARD

#include <chrono>
#include <thread>
#include <time.h>

#ifndef _WIN32
#include <sys/time.h>
#endif

namespace OWL {
void Sleep(unsigned int _milliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(_milliseconds));
}

class FPSLimiter {
public:
	FPSLimiter(unsigned int _desiredFPS = 30) {
		m_FPS = _desiredFPS;
	}
	~FPSLimiter() {

	}

	FPSLimiter& SetDesiredFPS(unsigned int _desiredFPS = 30) {
		m_FPS = _desiredFPS;
		return *this;
	}
	unsigned int GetDesiredFPS() const {
		return m_FPS;
	}

	FPSLimiter& Start() {
		m_StartTicks = (clock())/(CLOCKS_PER_SEC/1000.0);
		return *this;
	}
	FPSLimiter& End() {
		unsigned int elapsedTicks = (clock())/(CLOCKS_PER_SEC/1000.0) - m_StartTicks;
		float delay = (1000.0f/m_FPS)-elapsedTicks;
		if(delay > 0) {
			Sleep(delay);
		}
		return *this;
	}

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

#endif/*_OWL_TIME_HPP_HEADER_FILE_GUARD*/