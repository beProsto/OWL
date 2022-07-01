#include <OWL/Main.hpp>
#include <OWL/OWL.hpp>
#include <OWL/Time.hpp>

#include <iostream>

int a();

int main(int argc, char** argv) {
	OWL::Timer time;
	time.Start();
	printf("HEYA DEAR!\n");
	OWL::Sleep(16);
	time.End();
	printf("%f\n", time.GetDeltaTime());
	printf("%d\n", a());
	std::cin.get();
	return 0;
}