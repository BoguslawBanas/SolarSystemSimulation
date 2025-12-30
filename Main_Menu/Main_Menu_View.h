#ifndef MAIN_MENU_VIEW_H
#define MAIN_MENU_VIEW_H

#include <raylib.h>

class Main_Menu_View{
    private:

    public:
    Main_Menu_View();

    ~Main_Menu_View();

    void draw(const bool, const Rectangle&);
};

#endif