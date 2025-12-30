#ifndef MAIN_MENU_MODEL_H
#define MAIN_MENU_MODEL_H

#include <raylib.h>

class Main_Menu_Model{
    private:
    Rectangle add_planet_button_bounds;

    public:
    Main_Menu_Model(const Rectangle&);

    ~Main_Menu_Model();

    Rectangle getPlanetButtonBounds() const;
};

#endif