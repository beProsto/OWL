#include <OWL/OWL.hpp>
#include <OWL/Time.hpp>

float b() {
	OWL::Timer timer;
	OWL::FPSLimiter fps(1);
	timer.Start();
	fps.Start();
	fps.End();
	timer.End();
	return timer.GetDeltaTime();
}