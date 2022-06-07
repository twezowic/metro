#include "Display_text.h"
vector<vector<char>> table;
void Display_text::create_map(MetroApp metroapp)
{
	for (int i = 0; i < width + 2; i++)
	{
		vector<char> row;
		for (int j = 0; j < height + 2; j++)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == height + 1) || (i == width + 1 && j == 0) || (i == width + 1 && j == height + 1))
			{
				row.push_back('*');
			}
			else if (i == 0 || i == width + 1) {
				row.push_back('|');
			}
			else if (j == 0 || j == height + 1)
			{
				row.push_back('-');
			}
			else
			{
				row.push_back(' ');
			}
		}
		table.push_back(row);
	}
	char stationChar = 'S';
	for (int i = 0; i < metroapp.getConnections().size(); i++)
	{
		int startX = metroapp.getStation(metroapp.getConnections()[i].getstation1id())->x;
		int startY = metroapp.getStation(metroapp.getConnections()[i].getstation1id())->y;
		table[startX][startY] = stationChar;
		int nextX = metroapp.getStation(metroapp.getConnections()[i].getstation2id())->x;
		int nextY = metroapp.getStation(metroapp.getConnections()[i].getstation2id())->y;
		while (startX != nextX || startY != nextY)
		{
			if (startX < nextX)
			{
				startX++;
			}
			if (startX > nextX)
			{
				startX--;
			}
			if (startY < nextY)
			{
				startY++;
			}
			if (startY > nextY)
			{
				startY--;
			}
			table[startX][startY] = '.';
		}
		table[nextX][nextY] = stationChar;
	}
	for (int i = 0; i < width + 2; i++)
	{
		for (int j = 0; j < height + 2; j++)
		{
			cout << table[j][i];
		}
		cout << endl;
	}
}

string Display_text::showStations(MetroApp metroapp)
{
	string result;
	for (int i = 0; i < metroapp.getCoordinator().getStations().size(); i++)
	{
		result += "Station number: " + to_string((metroapp.getCoordinator().getStations()[i].id)) + '\n';
		result += "Name:" + metroapp.getCoordinator().getStations()[i].getName() + '\n';
		result += "People on station: " + to_string(metroapp.getCoordinator().getStations()[i].getWaitingList().size()) + '\n';
		result += "Coordinates: (" + to_string(metroapp.getCoordinator().getStations()[i].x) + ", " + to_string(metroapp.getCoordinator().getStations()[i].y) + ")\n\n";
	}
	return result;
}

string Display_text::showTrains(MetroApp metroapp)
{
	string result;
	for (int i = 0; i < metroapp.getTrains().size(); i++)
	{
		int x, y;
		Train train = metroapp.getCurrentTrain(metroapp.getTrains()[i]);
		result += "Train number: " + to_string(i) + '\n';
		result += "Name:" + train.getName() + '\n';
		result += "Train capacity: " + to_string(train.getPeopleNumber()) + '/' + to_string(train.getMaxCapacity()) + "\n\n";
	}
	return result;
}

string Display_text::showMenu()
{
	string menu;
	cout << "Welcome to metro simulation.\n\n";
	cout << "1. Show stations.\n";
	cout << "2. Show trains.\n";
	cout << "3. Show map in terminal.\n";
	cout << "4. Update map in html.\n";
	cout << "5. Show current time of simulation.\n";
	cout << "6. Pass n minutes in simulation.\n";
	cout << "7. Add people to metro.\n";
	cout << "0. End the program.\n\n";
	cout << "Please input the number: ";
	return menu;
}

string Display_text::showTime(int time)
{
	string hour=to_string(time/60), minute=to_string(time%60);
	if (minute == "0")
	{
		minute = "00";
	}
	return  "Current time in metro: " + hour + ':' + minute  +'\n';
}

string Display_text::showSimulationTime(int time)
{
	string day, hour, minute;
	day = to_string(time / (24 * 60));
	time %= (24 * 60);
	hour = to_string(time / 60);
	minute = to_string(time % 60);
	return "Simulation time : Days: " + day + ", hours: " + hour + ", minutes: " + minute + "\n\n";
}