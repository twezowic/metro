#include "../AppLib/MetroApp.h"
#include "../CoordinatorLib/CoordinatorLib.h"
#include "../AppLib/Display.h"
#include "../AppLib/Display_text.h"

#include <vector>
#include <iostream>


int main()
{
	min_time t = 60 * 12;
	int people_number = 100;


	// read stations, trains, connections from first file
	// read people from second file
	auto metro = MetroApp();
	//auto display = Display();
	//auto display_text = Display_text();
	metro.start(people_number, t);
	//cout << display_text.showTrains(metro);
	//display.create_map(metro);
	metro.run();
	return 0;
}
