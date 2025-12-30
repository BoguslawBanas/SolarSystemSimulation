#ifndef START_MENU_VIEW_H
#define START_MENU_VIEW_H

#include <raylib.h>

class Start_Menu_View{
    private:

    public:
    Start_Menu_View();

    ~Start_Menu_View();

    void drawStartMenu1(const Rectangle&, const Rectangle&, const Rectangle&);

    void drawStartMenu2(const Rectangle&, const Rectangle&, const Rectangle&);
};

#endif