#include "Display_text.h"


Display_text::Display_text() noexcept
{
	this->width = 25;
	this->height = 25;
	this->route = vector<Station>{};
	this->user = User();
}
Display_text::Display_text(int width, int height, Route route, User user) noexcept
{
	this->width = width;
	this->height = height;
	this->route = route;
	this->user = user;
}

int Display_text::getWidht() const noexcept
{
	return width;
}
int Display_text::getHeight() const noexcept
{
	return height;
}
void Display_text::menu() noexcept
{
	int input;
	bool is_admin = true;
	//bool is_admin = is_base_of<User_admin,user>::value;
	//bool is_admin = static_cast<User_admin*>(&user);
	user.helloWorld();
	cout << "Welcome to metro configuration.\n\n";
	do
	{
		cout << "1. Show the names of the stations.\n";
		cout << "2. Show the map of stations.\n";
		cout << "3. Load route from file.\n";
		if (is_admin)
		{
			cout << "4. Save route to file.\n";
			cout << "5. Add station.\n";
			cout << "6. Remove station.\n";
			cout << "7. Resets route.\n";
		}
		cout << "0. End the program.\n\n";
		cout << "Please input the number: ";
		cin >> input;
		switch (input)
		{
		case(1):
		{
			for (int i = 0; i < route.getStations().size(); i++)
			{
				cout << i + 1 << ". " << route[i].getName() << endl;
			}
			break;
		}
		case(2):
		{
			printMap();
			break;
		}
		case(3):
		{
			string filename;
			cout << "Please input name of file: ";
			cin >> filename;
			readFromFile(filename, route);
			break;
		}
		if (is_admin)
		{
			case(4):
			{
				string filename;
				cout << "Please input name of file: ";
				cin >> filename;
				saveToFile(filename, route);
				break;
			}
			case(5):
			{
				Station station;
				cout << "Please input parameters of station to add: ";
				cin >> station;
				route += station;
				break;
			}
			case(6):
			{
				string name;
				cout << "Please input name of station to remove: ";
				cin >> name;
				route -= name;
				break;
			}
			case(7):
				route = {};
				break;
		}
		default:
			break;
		}
		cout << endl;
	} while (input != 0);
}

void Display_text::printMap() noexcept
{
	vector<vector<char>> table;
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
				row.push_back('-');
			}
			else if (j == 0 || j == height + 1)
			{
				row.push_back('|');
			}
			else
			{
				row.push_back(' ');
			}
		}
		table.push_back(row);
	}
	vector<Coordinate> coordinates;
	coordinates = route.getCoordinates();
	Coordinate start = coordinates[0];
	int startX = start.x;
	int startY = start.y;
	char stationChar = 'A';
	table[startX][startY] = stationChar;
	stationChar++;
	for (int i = 0; i < coordinates.size() - 1; i++)
	{
		Coordinate next = coordinates[i + 1];
		int nextX = next.x;
		int nextY = next.y;
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
		stationChar++;
	}
	for (int i = 0; i < width + 2; i++)
	{
		for (int j = 0; j < height + 2; j++)
		{
			cout << table[i][j];
		}
		cout << endl;
	}
}
