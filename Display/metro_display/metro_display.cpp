#include <iostream>
#include"Display_text.h"
#include"Display_gui.h"
#include"../metro_user/User_admin.h"
using namespace std;

int main()
{
    Display_text display;
    Route route;
    User_admin user;
    readFromFile("x.txt", route);
    display.setRoute(route);
    display.setUser(user);
    display.menu();
}