#ifndef MAIN_MENU_MODEL_H
#define MAIN_MENU_MODEL_H

#include <raylib.h>

class Main_Menu_Model{
    private:
    Rectangle add_planet_button_bounds;
    Rectangle delete_planet_button_bounds;

    public:
    Main_Menu_Model(const Rectangle&, const Rectangle&);

    ~Main_Menu_Model();

    Rectangle getAddPlanetButtonBounds() const;

    Rectangle getDeletePlanetButtonBounds() const;
};

#endif