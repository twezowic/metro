#pragma once
#include "Display.h"
class Display_text :
    public Display
{
private:
    int width;
    int height;
public:
    Display_text() noexcept;
    Display_text(int width, int height, Route route, User user) noexcept;

    int getWidht() const noexcept;
    int getHeight() const noexcept;

    void printMap() noexcept;
    void menu() noexcept;
};

