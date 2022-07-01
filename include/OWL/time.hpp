#pragma once

#include <OWL/Utility/Config.hpp>

namespace OWL {

void OWL_API Sleep(unsigned int _milliseconds);

namespace Impl {
class OWL_API Timer;
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
	Impl::Timer* m_Impl;
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
	Impl::Timer* m_Impl;
	float m_DeltaTime;
};

}