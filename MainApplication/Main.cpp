#include "../AppLib/MetroApp.h"
#include "../CoordinatorLib/CoordinatorLib.h"
#include "../AppLib/Display.h"

#include <vector>
//#include <iostream> - currently can not include, as it has a "time" object defined, which causes redefinition with our "time"


int main()
{
	min_time t = 60 * 12;

	// read stations, trains, connections from first file
	// read people from second file
	auto metro = MetroApp();
	auto display = Display();
	metro.start();
	display.create_map(metro);
	//int sim_time = metro.run();
	//std::cout << sim_time;

	return 0;
}
