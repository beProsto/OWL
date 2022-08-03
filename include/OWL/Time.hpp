#pragma once

#include <OWL/Utility/Config.hpp>

namespace OWL {

void OWL_API sleep(unsigned int _milliseconds);

namespace Impl {
class OWL_API Timer;
}

class OWL_API FPSLimiter {
public:
	FPSLimiter(unsigned int _desiredFPS = 30);
	~FPSLimiter();

	void setDesiredFPS(unsigned int _desiredFPS = 30);
	unsigned int getDesiredFPS() const;
	void start();
	void end();

private:
	Impl::Timer* m_impl;
	unsigned int m_fps;
};

class OWL_API Timer {
public:
	Timer();
	~Timer();

	void start();
	void end();

	float getDeltaTime() const;

private:
	Impl::Timer* m_impl;
	float m_deltaTime;
};

}