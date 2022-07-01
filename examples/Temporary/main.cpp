#include <OWL/Main.hpp>
#include <OWL/OWL.hpp>
#include <OWL/Time.hpp>

#include <iostream>

int main(int argc, char** argv) {
	OWL::Timer time;
	time.Start();
	printf("HEYA DEAR!\n");
	OWL::Sleep(16);
	time.End();
	printf("%f\n", time.GetDeltaTime());
	std::cin.get();
	return 0;
}