#include "Display_text.h"


Display_text::Display_text() noexcept
{
	this->width = 25;
	this->height = 25;
	this->user = User();
}
Display_text::Display_text(User user) noexcept
{
	this->width = 25;
	this->height = 25;
	this->user = User();
}
Display_text::Display_text(int width, int height, User user) noexcept
{
	this->width = width;
	this->height = height;
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
void Display_text::printMenu() noexcept
{
	cout << "1. Show the names of the stations.\n";
	cout << "2. Show the map of stations.\n";
	cout << "3. Load route from file.\n";
	cout << "4. Save route to file.\n";
	cout << "5. Add station.\n";
	cout << "6. Remove station.\n";
	cout << "7. Resets route.\n";
	cout << "0. End the program.\n\n";
	cout << "Please input the number: ";
}

void Display_text::printMap(Route route) noexcept
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

void Display_text::printStation(Station station) noexcept
{
	cout << "Station name: " << station.getName() << endl;
	cout << "Coordinates: (" << station.getCoordinate().x <<", "  << station.getCoordinate().y << ")" << endl;
}
void Display_text::printRoute(Route route) noexcept
{
	for (int i = 0; i < route.getStations().size(); i++)
	{
		cout << i << ")";
		printStation(route.getStations()[i]);
	}
}
void Display_text::printUser(User user) noexcept
{
	cout << "First name: " << user.getFirstName() << endl;
	cout << "Last name: " << user.getLastName() << endl;
	cout << "Username: " << user.getUsername() << endl;
	cout << "Mail: " << user.getMail();
}
void Display_text::printSchedule(string filename) noexcept
{
	ifstream file(filename);
	string line;
	while (!file.eof())
	{
		getline(file, line);
		cout << line << endl; 
	}
}