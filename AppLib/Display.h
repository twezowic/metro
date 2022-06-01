#pragma once
#include<string>
#include<fstream>
#include"MetroApp.h"
#include"Display_text.h"
using namespace std;
class Display: public Display_text
{
private:
	int size;
public:
	Display() { this->size = 20; this->width = 25*size; this->height = 25*size; }
	Display(int size, int width, int height) { this->size = size; this->width = width; this->height = height;}

	string drawConnection(int x1, int y1, int x2, int y2);
	string drawStation(int x, int y, int index);
	string drawTrain(int x, int y, int index);
	string addScripts();
	string addStationInfo(int index, string name, int peopleNumber);
	string addTrainInfo(int index, string name, int maxCapacity, int peopleNumber);

	void create_map(MetroApp metroapp);
};

