#include "../AppLib/MetroApp.h"
#include "../CoordinatorLib/CoordinatorLib.h"


#include <vector>
int main() {
	// read stations, trains, connections from first file
	// read people from second file
	auto metro = MetroApp();
	metro.start();
	metro.run();
	return 0;
}