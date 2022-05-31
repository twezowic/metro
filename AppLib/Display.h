#pragma once
#include<string>
#include<fstream>
#include"MetroApp.h"
using namespace std;
class Display
{
private:
	int size;
public:
	Display() { this->size = 50; }
	Display(int size) { this->size = size; }
	string drawConnection(int x1, int y1, int x2, int y2);
	string drawStation(int x, int y);
	string drawTrain(int lastStationx, int lastStationy, int nextStationx, int nextStationy, double distance, double actualDistance);
	void create_map(MetroApp metroapp);
};

