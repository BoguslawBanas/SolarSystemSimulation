#ifndef ADD_PLANET_MENU_VIEW_H
#define ADD_PLANET_MENU_VIEW_H

#include <raylib.h>
#include <raymath.h>

class Add_Planet_Menu_View{
    private:
    unsigned window_width;
    unsigned window_height;

    public:
    Add_Planet_Menu_View(const unsigned, const unsigned);

    ~Add_Planet_Menu_View();

    void draw();
};

#endif