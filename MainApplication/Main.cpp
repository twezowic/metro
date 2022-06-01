#include "../AppLib/MetroApp.h"
#include "../CoordinatorLib/CoordinatorLib.h"
#include "../AppLib/Display.h"

#include <vector>
#include <iostream>


int main()
{
	min_time t = 60 * 12;
	int people_number = 100;


	// read stations, trains, connections from first file
	// read people from second file
	auto metro = MetroApp();
	auto display = Display();
	metro.start(people_number, t);
	//display.create_map(metro);
	metro.run(display);
	return 0;
}
