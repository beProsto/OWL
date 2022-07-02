#include <OWL/OWL.hpp>
#include <OWL/Time.hpp>
#include <stdio.h>
float b() {
	OWL::Timer timer;
	OWL::FPSLimiter fps(1);
	timer.Start();
	fps.Start();
	fps.End();
	timer.End();
	OWL::Window window2;
	printf("%s\n", window2.GetTitle().c_str());
	return timer.GetDeltaTime();
}