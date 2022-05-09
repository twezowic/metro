#pragma once
#include "Display_gui.h"
class Display_text :
    public Display_gui
{
private:
    int width;
    int height;
public:
    Display_text() noexcept;
    Display_text(User user) noexcept;
    Display_text(int width, int height, User user) noexcept;

    int getWidht() const noexcept;
    int getHeight() const noexcept;

    void printMap(Route route) noexcept;
    void printStation(Station station) noexcept;
    void printRoute(Route route) noexcept;
    void printUser(User user) noexcept;
    void printSchedule(string filename) noexcept;
    void printMenu() noexcept;
};

