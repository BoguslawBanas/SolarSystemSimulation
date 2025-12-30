#ifndef ADD_PLANET_MENU_MODEL_H
#define ADD_PLANET_MENU_MODEL_H

#include <raylib.h>

class Add_Planet_Menu_Model{
    private:
    float radius;

    public:
    Add_Planet_Menu_Model();

    ~Add_Planet_Menu_Model();

    // bool getGoBackButton() const;

    // bool getAcceptNewPlanetButton() const;

    // const char* getName() const;

    float getRadius() const;

    // float getMass() const;

    // float getAngle() const;

    // float getDistanceFromCenter() const;

    // float getvelocity() const;

    // Color getColor() const;
};

#endif