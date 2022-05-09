#include <iostream>
#include"Display_text.h"
#include"Display_gui.h"
#include"../metro_user/User_admin.h"
using namespace std;


int main()
{
    Route route;
    User user;
    Display_text display(user);
    readFromFile("x.txt", route);
    //display.printMap(route);
    display.printSchedule("schedule.txt");
}