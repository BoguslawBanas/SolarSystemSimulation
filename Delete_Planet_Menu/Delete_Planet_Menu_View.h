#ifndef DELETE_PLANET_MENU_VIEW_H
#define DELETE_PLANET_MENU_VIEW_H

#include <raylib.h>

class Delete_Planet_Menu_View{
    private:
    unsigned window_width;
    unsigned window_height;

    public:
    Delete_Planet_Menu_View(const unsigned, const unsigned);

    ~Delete_Planet_Menu_View();

    void draw();
};

#endif