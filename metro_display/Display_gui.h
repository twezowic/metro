#pragma once
#include "Display.h"
class Display_gui :
    public Display
{
public:
    Display_gui() noexcept;
    Display_gui(Route route, User user) noexcept;

    void menu() noexcept;
    void printMap() noexcept;
};

