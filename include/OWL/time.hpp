#pragma once

#include <OWL/Utility/Config.hpp>

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

class OWL_API FPSLimiter {
public:
	FPSLimiter(unsigned int _desiredFPS = 30);
	~FPSLimiter();

	void SetDesiredFPS(unsigned int _desiredFPS = 30);
	unsigned int GetDesiredFPS() const;
	void Start();
	void End();

private:
	unsigned int m_StartTicks;
	unsigned int m_FPS;
};

class OWL_API Timer {
public:
	Timer();
	~Timer();

	void Start();
	void End();

	float GetDeltaTime() const;

private:
	std::chrono::high_resolution_clock::time_point m_S, m_E;
	float m_DeltaTime;
};

}