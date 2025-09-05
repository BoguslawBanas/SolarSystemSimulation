#ifndef ADD_PLANET_MENU_H
#define ADD_PLANET_MENU_H

#include <raylib.h>
#include <string>
#include "raygui.h"
#include <math.h>

class Add_Planet_Menu{
    private:
    unsigned menu_width;
    unsigned menu_height;
    unsigned start_menu_width;
    float radius;
    float mass;
    float angle;
    float distance_from_center;
    float velocity;
    Color color;
    char radius_str[15];
    char mass_str[15];
    char angle_str[15];
    char distance_from_center_str[15];
    char velocity_str[15];
    char name[50];

    public:
    Add_Planet_Menu(unsigned, unsigned, unsigned);

    ~Add_Planet_Menu();

    const char* getName() const;

    float getRadius() const;

    float getMass() const;

    float getAngle() const;

    float getDistanceFromCenter() const;

    float getvelocity() const;

    Color getColor() const;

    void drawMenu();
};

#endif